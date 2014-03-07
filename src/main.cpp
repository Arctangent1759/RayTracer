#include <iostream>
#include "Color.hpp"
#include "Vect.hpp"
#include "Scene.hpp"
#include "Surface.hpp"

#include "ImgWriter.hpp"

using namespace std;

int main(){
    Scene s(Color(.1,.1,.1),Color(0,0,0),5);
    s.addCamera(new Camera(new Vect(0,0,0),new Vect(-1,1,-1),new Vect(1,1,-1),new Vect(1,-1,-1),new Vect(-1,-1,-1),1000,1000));

    //s.addSurface(new Surface(new SphereGeometry(Vect(0,0,-2),1),new Material(Color(1.0,0.0,0.0),Color(1.0,1.0,1.0),32.0)));

    //s.addSurface(new Surface(new SphereGeometry(Vect(0,0,-8),5.0),new Material(Color(0.0,1.0,0.0),Color(1.0,1.0,1.0),32.0)));

    //s.addLight(new DirectionalLight(*(new Vect(1,-1,-1)),Color(1,1,1)));
    //s.addLight(new PointLight(*(new Vect(-1,1,0)),Color(1,1,1)));
    //
    s.addLight(new PointLight(*(new Vect(0,0,0)),Color(1,1,1)));
    
    //s.addLight(new DirectionalLight(*(new Vect(1,0,0)),Color(1,1,1)));

    s.addSurface(new Surface(new SphereGeometry(Vect(1.0,0.0,-4.0),1.5), new Material(Color(0.0,0.0,0.0),Color(1.0,1.0,1.0),Color(0.7,0.7,0.7),32.0)));
    s.addSurface(new Surface(new SphereGeometry(Vect(-1.1,0.0,-3.0),0.6), new Material(Color(1.0,0.0,0.0),Color(1.0,1.0,1.0),Color(0.7,0.7,0.7),32.0)));

    s.render("out.png");
}
