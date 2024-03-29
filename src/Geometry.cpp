#include "Geometry.hpp"
#include "math.h"
#include "stdexcept"
#include <algorithm>
#include <fstream>

////////////////////////////////
//  Geometry Implementations  //
////////////////////////////////

Vect Geometry::getIntersection(Ray r){
    return r.getPos() + r.getDir()*this->getDistAlongRay(r);
}

//////////////////////////////////////
//  SphereGeometry Implementations  //
//////////////////////////////////////

SphereGeometry::SphereGeometry(Vect center, scalar radius){
    this->center=center;
    this->radius=radius;
}
scalar SphereGeometry::getDistAlongRay(Ray r){
    Vect displacement = r.getPos() - this->center;
    Vect dir = r.getDir();

    scalar a = dir*dir;
    scalar b = 2*displacement*dir;
    scalar c = displacement*displacement - this->radius*this->radius;

    scalar discriminant = b*b-4*a*c;
    if (discriminant < 0){
        return -1;
    }else{
        scalar out = (-b - sqrt(discriminant))/(2.0*a);
        if (out < 0){
            return -1;
        }else{
            return out;
        }
    }
}
Vect SphereGeometry::getNormal(Ray r){
    Vect p = getIntersection(r);
    return normalized(p-this->center);
}

////////////////////////////////////////
//  PolygonGeometry Implementations  //
////////////////////////////////////////

struct PointComparator{
    inline bool operator() (const Vect v1, const Vect v2){
        return this->getKey(v1) < this->getKey(v2);
    }
    double getKey(Vect p){
        Vect r = normalized(p-this->center);
        scalar c = r*x;
        Vect crossProd = cross(r,x);
        scalar s = norm(crossProd) * ((this->y*r)>=0?1:-1);
        double out = atan2(s,c);
        if (out < 0){
            out += 2*M_PI;
        }
        return out;
    }
    Vect center;
    Vect x;
    Vect y;
};

PolygonGeometry::PolygonGeometry(vector<Vect> points){
    this->points = points;
    this->preprocess();

    Vect center(0,0,0);
    for (vector<Vect>::iterator i = points.begin(); i != points.end(); i++){
        center+=*i;
    }
    center/=points.size();

    PointComparator pc;
    pc.center=center;
    pc.x=normalized(points[0]-center);
    pc.y=cross(pc.x,this->n);

    std::sort(this->points.begin(),this->points.end(),pc);
}

PolygonGeometry::PolygonGeometry(Vect a, Vect b, Vect c){
    this->points = vector<Vect>(3);
    this->points[0]=a;
    this->points[1]=b;
    this->points[2]=c;
    this->preprocess();
}
void PolygonGeometry::preprocess(){
    //Preprocessing. Should make rendering faster.
    this->n=-1*normalized(cross(this->points[1]-this->points[0],this->points[2]-this->points[0]));
}
scalar PolygonGeometry::getDistAlongRay(Ray r){
    scalar t = ((this->points[0]-r.getPos())*this->n)/(r.getDir()*this->n);
    Vect p = r.getPos()+t*r.getDir();

    if (t < 1e-5){
        return -1;
    }
    int len = this->points.size();
    for (int i = 0; i < len; i++){
        if (cross(this->points[(len+i-1)%len]-this->points[(len+i)%len],p-this->points[(len+i)%len])*
                cross(this->points[(len+i-1)%len]-this->points[(len+i)%len],this->points[(len+i+1)%len]-this->points[(len+i)%len])<0){
            return -1;
        }
    }


    return t;
}
Vect PolygonGeometry::getNormal(Ray r){
    return ((this->n*r.getDir())<0?1.0:-1.0)*this->n;
}

///////////////////////////////////
//  ObjGeometry Implementations  //
///////////////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

ObjGeometry::ObjGeometry(string filepath){
    ifstream file(filepath.c_str());
    string line;

    vector<Vect> vertices;
    vector< vector<int> > faces;
    while (getline(file,line)){
        if (line == "" || line.at(0)=='#'){
            continue;
        }

        istringstream lstr(line);
        string token;

        lstr >> token;

        if (token=="v"){
            scalar x,y,z;
            lstr >> x >> y >> z;
            vertices.push_back(Vect(x,y,z));
        }else if(token=="f"){
            string vertString;
            int vertNum;
            vector<int> currFace;
            while (lstr >> vertString){
                vertNum = atoi(vertString.substr(0,vertString.find('/')).c_str());
                currFace.push_back(vertNum-1);
            }
            faces.push_back(currFace);
        }else{
        }
    }
    for (vector<vector<int> >::iterator i = faces.begin(); i != faces.end(); i++){
        vector<Vect> points;
        for (int j = 0; j < (*i).size(); j++){
            points.push_back(vertices[(*i)[j]]);
        }
        this->polygons.push_back(PolygonGeometry(points));
    }
}
scalar ObjGeometry::getDistAlongRay(Ray r){
    scalar min=-1;
    for (vector<PolygonGeometry>::iterator i = this->polygons.begin(); i != this->polygons.end(); i++){
        scalar d = i->getDistAlongRay(r);
        if (d == -1){
            continue;
        }
        if (min == -1 || d < min){
            min = d;
        }
    }
    return min;
}

Vect ObjGeometry::getNormal(Ray r){
    scalar min = -1;
    Vect vectmin;
    for (vector<PolygonGeometry>::iterator i = this->polygons.begin(); i != this->polygons.end(); i++){
        scalar d = i->getDistAlongRay(r);
        if (d == -1){
            continue;
        }
        if (min == -1 || d < min){
            min = d;
            vectmin = i->getNormal(r);
        }
    }
    return vectmin;
}

////////////////
//  Ostreams  //
////////////////

ostream& operator<<(ostream& lhs, SphereGeometry& g){
    lhs << "SphereGeometry(" << g.center << "," << g.radius << ")";
}
ostream& operator<<(ostream& lhs, PolygonGeometry& g){
    lhs << "PolygonGeometry(" << "[ ";
    for (int i = 0; i < g.points.size(); i++){
        lhs << g.points[i] << " ";
    }
    lhs << "])";
}
ostream& operator<<(ostream& lhs, ObjGeometry& g){
    lhs << "ObjGeometry(" << "[ ";
    for (int i = 0; i < g.polygons.size(); i++){
        lhs << g.polygons[i] << " ";
    }
    lhs << "])";

}
