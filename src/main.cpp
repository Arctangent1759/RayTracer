#include <iostream>
#include "Color.hpp"
#include "Vect.hpp"
#include "Scene.hpp"
#include "Surface.hpp"
#include "Transformation.hpp"

#include "ImgWriter.hpp"

#include <math.h>

const scalar pi = atan(1)*4;

using namespace std;

int main(){
    Scene s(Color(0.0,0.0,0.0),Color(0,0,0),5);
    s.addCamera(new Camera(new Vect(0,0,0),new Vect(-1,1,-3),new Vect(1,1,-3),new Vect(1,-1,-3),new Vect(-1,-1,-3),1000,1000));
    s.addLight(new DirectionalLight( Vect(0.57735027,-0.57735027,-0.57735027), Color(1,1,1)));
    s.addLight(new DirectionalLight( Vect(-0.57735027,0.57735027,0.57735027), Color(1,1,1)));

    //s.addSurface(new Surface(new SphereGeometry(Vect(0,0,0),1),new Material(Color(0.1, 0.1, 0.1),Color(1., 0., 0.),Color(1., 1., 1.),Color(0.9, 0.9, 0.9),50.0),Translate(0.0,0.0,-17)*Rotation(0,-M_PI/4,-M_PI/4)*Scale(0.25,4.0,2.0)));
    //s.addSurface(new Surface(new SphereGeometry(Vect(0,0,10),1),new Material(Color(0.1, 0.1, 0.1),Color(0., 1., 0.),Color(0., 1., 0.),Color(0.9, 0.9, 0.9),50.0)));

    s.addSurface(new Surface(new SphereGeometry(Vect(0,0,0),1),new Material(Color(0.1, 0.1, 0.1),Color(1., 0., 0.),Color(1., 1., 1.),Color(0.9, 0.9, 0.9),50.0),Translate(0,0,-17)*Rotation(0.0,0,0)*Scale(4,2,2)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,0,0),1),new Material(Color(0.1, 0.1, 0.1),Color(0., 1., 0.),Color(1., 1., 1.),Color(0.9, 0.9, 0.9),50.0),Translate(-2,4,-17)*Rotation(0.0,-M_PI/4,-M_PI/4)*Scale(0.5,1.5,1.0)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,0,0),1),new Material(Color(0.1, 0.1, 0.1),Color(0., 0., 1.),Color(1., 1., 1.),Color(0.9, 0.9, 0.9),50.0),Translate(-2,-4,-17)*Rotation(0.0,-M_PI/4,M_PI/4)*Scale(0.5,1.5,1.0)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,0,0),1),new Material(Color(0.1, 0.1, 0.1),Color(1., 1., 0.),Color(1., 1., 1.),Color(0.9, 0.9, 0.9),50.0),Translate(2,4,-17)*Rotation(0.0,M_PI/4,-3*M_PI/4)*Scale(0.5,1.5,1.0)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,0,0),1),new Material(Color(0.1, 0.1, 0.1),Color(0., 1., 1.),Color(1., 1., 1.),Color(0.9, 0.9, 0.9),50.0),Translate(2,-4,-17)*Rotation(0.0,M_PI/4,3*M_PI/4)*Scale(0.5,1.5,1.0)));
    s.render("out.png");


    /*Scene s(Color(0.0,0.0,0.0),Color(0,0,0),5);

    s = Scene(Color(0.0,0.0,0.0),Color(0,0,0),5);
    s.addCamera(new Camera(Vect(0,0,0),Vect(0,0,-3),Vect(0,1,0),2.0,1000,1000));
    s.addLight(new DirectionalLight( Vect(0.57735027,-0.57735027,-0.57735027), Color(1,1,1)));
    s.addLight(new DirectionalLight( Vect(-0.57735027,0.57735027,0.57735027), Color(1,1,1)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,0,-17), 2.0), new Material(Color(0.1,0.1,0.1), Color(1,0,0), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,4,-17), 1.5), new Material(Color(0.1,0.1,0.1), Color(0,1,0), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,-4,-17), 1.5), new Material(Color(0.1,0.1,0.1), Color(0,0,1), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.addSurface(new Surface(new SphereGeometry(Vect(4,0,-17), 1.5), new Material(Color(0.1,0.1,0.1), Color(1,1,0), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.addSurface(new Surface(new SphereGeometry(Vect(-4,0,-17), 1.5), new Material(Color(0.1,0.1,0.1), Color(0,1,1), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.render("img/5sphere.png");


    s = Scene(Color(0.0,0.0,0.0),Color(0,0,0),5);
    s.addCamera(new Camera(new Vect(0,0,0),new Vect(-1,1,-3),new Vect(1,1,-3),new Vect(1,-1,-3),new Vect(-1,-1,-3),500,500));
    s.addLight(new DirectionalLight(Vect(0.57735027,-0.57735027,-0.57735027), Color(1,1,1)));
    s.addLight(new DirectionalLight(Vect(0.57735027,0.57735027,-0.57735027), Color(0,0,1)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,0,-20), 3.0), new Material(Color(1,0,1), Color(1,1,1), Color(0,0,0), 50.0)));
    s.addSurface(new Surface(new SphereGeometry(Vect(-2,2,-15), 1.0), new Material(Color(1,1,0), Color(1,1,1), Color(0,0,0), 50.0)));
    s.addSurface(new Surface(new SphereGeometry(Vect(-2,-2,-15), 1.0), new Material(Color(0,1,1), Color(1,1,1), Color(0,0,0), 50.0)));
    s.addSurface(new Surface(new PolygonGeometry(Vect(5,5,-17),Vect(1,4,-20),Vect(6,-1,-20)), new Material(Color(0.1,0.1,0.1), Color(1,1,1), Color(1,1,1), 50.0)));
    s.render("img/PolyReflect.png");

    s = Scene(Color(0.0,0.0,0.0),Color(0,0,0),5);
    s.addCamera(new Camera(new Vect(0,0,0),new Vect(-1,1,-3),new Vect(1,1,-3),new Vect(1,-1,-3),new Vect(-1,-1,-3),500,500));
    s.addLight(new PointLight(Vect(0,0,0),Color(1,1,1)));
    vector<Vect> points(5);
    points[4]=Vect(-3,-2,-14);
    points[0]=Vect(-3,1,-15);
    points[2]=Vect(0,4,-16);
    points[1]=Vect(3,1,-15);
    points[3]=Vect(3,-2,-14);
    s.addSurface(new Surface(new PolygonGeometry(points), new Material(Color(.1,.1,.1),Color(0,0,.3),Color(0,0,1),Color(1,1,1),50.0)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,10,5),5), new Material(Color(.1,.1,.1),Color(1,0,0),Color(1,1,1),Color(0,0,0),50.0)));
    s.render("img/SphereMirror.png");

    s = Scene(Color(0.0,0.0,0.0),Color(0,0,0),5);
    s.addCamera(new Camera(Vect(-5,-5,5),Vect(1,1,-1),Vect(-1,1,-1),2.0,500,500));
    s.addLight(new DirectionalLight( Vect(0.57735027,-0.57735027,-0.57735027), Color(1,1,1)));
    s.addLight(new DirectionalLight( Vect(-0.57735027,0.57735027,0.57735027), Color(1,1,1)));
    s.addSurface(new Surface(new ObjGeometry("obj/dodecahedron.obj"), new Material(Color(0.1,0.1,0.1),Color(.5,.5,.5), Color(1,1,1), Color(.9,.9,.9), 50.0)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,2,0), 0.5), new Material(Color(0.1,0.1,0.1), Color(0,1,0), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,-2,0), 0.5), new Material(Color(0.1,0.1,0.1), Color(0,0,1), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.addSurface(new Surface(new SphereGeometry(Vect(2,0,0), 0.5), new Material(Color(0.1,0.1,0.1), Color(1,1,0), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.addSurface(new Surface(new SphereGeometry(Vect(-2,0,0), 0.5), new Material(Color(0.1,0.1,0.1), Color(0,1,1), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.render("img/5sphereDodec.png");

    s = Scene(Color(0.0,0.0,0.0),Color(0,0,0),5);
    s.addCamera(new Camera(Vect(0,0,20),Vect(0,0,-1),Vect(0,1,0),2,50,50));
    s.addLight(new PointLight(Vect(0,0,20), Color(1,1,1)));
    s.addSurface(new Surface(new ObjGeometry("obj/airboat.obj"), new Material(Color(.1,.1,.1),Color(1,0,0),Color(1,1,1),Color(.9,.9,.9),50)));
    s.render("img/Airboat.png");

    s = Scene(Color(0.0,0.0,0.0),Color(0,0,0),5);
    s.addCamera(new Camera(Vect(0,8,0)*2,Vect(0,-1,0),Vect(0,0,1),2,100,100));
    s.addLight(new PointLight(Vect(0,0,10), Color(1,1,1)));
    s.addSurface(new Surface(new ObjGeometry("obj/shuttle.obj"), new Material(Color(.1,.1,.1),Color(.7,.7,.7),Color(1,1,1),Color(.5,.5,.5),50)));
    s.addSurface(new Surface(new PolygonGeometry(Vect(-1000,-1000,-5),Vect(1000,-1000,-5),Vect(0,1000,-5)), new Material(Color(.1,.1,.1),Color(0,0,.7),Color(0,0,.5),Color(1,1,1),50)));
    s.addSurface(new Surface(new PolygonGeometry(Vect(-1000,-1000,12),Vect(1000,-1000,12),Vect(0,1000,12)), new Material(Color(.1,.1,.1),Color(0,0,.7),Color(0,0,.5),Color(1,1,1),50)));
    s.render("img/Shuttle.png");

    //s = Scene(Color(0.0,0.0,0.0),Color(0,0,0),5);
    //s.addCamera(new Camera(Vect(0,0,0),Vect(0,-1,0),Vect(0,0,1),2,500,500));*/
}
