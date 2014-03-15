#include <iostream>
#include "Color.hpp"
#include "Vect.hpp"
#include "Scene.hpp"
#include "Surface.hpp"
#include "Transformation.hpp"
#include "ImgWriter.hpp"
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>

const scalar pi = atan(1)*4;

using namespace std;

int main(int argc, char *argv[]){

    if ((argc != 4 && argc != 2) || string(argv[1])=="-h" || (argc==4 && string(argv[2])!="-o")){
        cout << "Usage:" << endl;
        cout << "./as2 <SCENEFILE> [-o <OUTFILE>]" << endl;
        cout << "\t <SCENEFILE> is the path to a scene file." << endl;
        cout << "\t <OUTFILE> is the path to the output file. If left unspecified, defaults to \"out.png\"." << endl;
        exit(0);
    }

    string outFile = "out.png";
    string inFile = argv[1];
    if (argc==4){
        outFile = argv[3];
    }

    ifstream file(inFile.c_str());

    if (!file){
        cout << "File " << inFile << " not found." << endl;
        exit(0);
    }

    string line;
    Scene s(Color(0,0,0),Color(0,0,0),5);
    while (getline(file,line)){
        if (line == "" || line.at(0)=='#'){
            continue;
        }
        istringstream lstr(line);
        string token;
        lstr >> token;
        cout << "Processing token " << token << endl;
        if (token == "Scene"){
            scalar bgR,bgG,bgB;
            int recursiveDepth;
            lstr >>bgR>>bgG>>bgB>>recursiveDepth;
            s = Scene(Color(0,0,0),Color(bgR,bgG,bgB),recursiveDepth);
            cout << "Initializing scene " << s << endl;
        }else if (token == "Camera"){
            scalar lookfromX,lookfromY,lookfromZ,lookatX,lookatY,lookatZ,upX,upY,upZ,fov,imgX,imgY;
            lstr >> lookfromX>>lookfromY>>lookfromZ>>lookatX>>lookatY>>lookatZ>>upX>>upY>>upZ>>fov>>imgX>>imgY;
            Camera* c = new Camera(Vect(lookfromX,lookfromY,lookfromZ),Vect(lookatX,lookatY,lookatZ),Vect(upX,upY,upZ),fov,imgX,imgY);
            s.addCamera(c);
            cout << "Initializing camera " << *c << endl;
        }else if (token == "PointLight"){
            scalar x,y,z,r,g,b;
            lstr >> x>>y>>z>>r>>g>>b;
            s.addLight(new PointLight(Vect(x,y,z),Color(r,g,b)));
        }else if (token == "DirectionalLight"){
            scalar x,y,z,r,g,b;
            lstr >> x>>y>>z>>r>>g>>b;
            s.addLight(new DirectionalLight(Vect(x,y,z),Color(r,g,b)));
        }else if (token == "Polygon"){
            vector<Vect> points;
            Material* m = NULL;
            Transformation trans;
            while (lstr >> token){
                cout << "\tProcessing token " << token << endl;
                if (token == "v"){
                    scalar x,y,z;
                    lstr >> x>>y>>z;
                    points.push_back(Vect(x,y,z));
                }else if (token == "m"){
                    scalar car, cag, cab, cdr, cdg, cdb, csr, csg, csb, crr, crg, crb, p;
                    lstr >> car>> cag>> cab>> cdr>> cdg>> cdb>> csr>> csg>> csb>> crr>> crg>> crb>> p;
                    m = new Material(Color(car,cag,cab),Color(cdr,cdg,cdb),Color(csr,csg,csb),Color(crr,crg,crb),p);
                }else if (token == "t"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Translate(x,y,z);
                }else if (token == "r"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Rotation(x*M_PI/180.0,y*M_PI/180.0,z*M_PI/180.0);
                }else if (token == "s"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Scale(x,y,z);
                }else{
                    cout << "Unexpected token " << token << " encountered while parsing Polygon arglist." << endl;
                    exit(-1);
                }
            }
            s.addSurface(new Surface(new PolygonGeometry(points),m,trans));
        }else if (token == "Sphere"){
            Material* m = NULL;
            Transformation trans;
            scalar cx,cy,cz,radius;
            lstr >> cx >> cy >> cz >> radius;
            while (lstr >> token){
                cout << "\tProcessing token " << token << endl;
                if (token == "m"){
                    scalar car, cag, cab, cdr, cdg, cdb, csr, csg, csb, crr, crg, crb, p;
                    lstr >> car>> cag>> cab>> cdr>> cdg>> cdb>> csr>> csg>> csb>> crr>> crg>> crb>> p;
                    m = new Material(Color(car,cag,cab),Color(cdr,cdg,cdb),Color(csr,csg,csb),Color(crr,crg,crb),p);
                }else if (token == "t"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Translate(x,y,z);
                }else if (token == "r"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Rotation(x*M_PI/180.0,y*M_PI/180.0,z*M_PI/180.0);
                }else if (token == "s"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Scale(x,y,z);
                }else{
                    cout << "Unexpected token " << token << " encountered while parsing Sphere arglist." << endl;
                    exit(-1);
                }
            }
            s.addSurface(new Surface(new SphereGeometry(Vect(cx,cy,cz),radius),m,trans));
        }else if (token == "Obj"){
            Material* m = NULL;
            Transformation trans;
            string filename;
            lstr >> filename;
            while (lstr >> token){
                cout << "\tProcessing token " << token << endl;
                if (token == "m"){
                    scalar car, cag, cab, cdr, cdg, cdb, csr, csg, csb, crr, crg, crb, p;
                    lstr >> car>> cag>> cab>> cdr>> cdg>> cdb>> csr>> csg>> csb>> crr>> crg>> crb>> p;
                    m = new Material(Color(car,cag,cab),Color(cdr,cdg,cdb),Color(csr,csg,csb),Color(crr,crg,crb),p);
                }else if (token == "t"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Translate(x,y,z);
                }else if (token == "r"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Rotation(x*M_PI/180.0,y*M_PI/180.0,z*M_PI/180.0);
                }else if (token == "s"){
                    scalar x,y,z;
                    lstr >>x>>y>>z;
                    trans=trans*Scale(x,y,z);
                }else{
                    cout << "Unexpected token " << token << " encountered while parsing Sphere arglist." << endl;
                    exit(-1);
                }
            }
            s.addSurface(new Surface(new ObjGeometry(filename),m,trans));

        }else{
            cout << "Unexpected token " << token << " encountered while parsing scene file." << endl;
            exit(-1);
        }
    }
    s.render(outFile);
}
