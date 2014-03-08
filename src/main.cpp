#include <iostream>
#include "Color.hpp"
#include "Vect.hpp"
#include "Scene.hpp"
#include "Surface.hpp"

#include "ImgWriter.hpp"

using namespace std;

int main(){
    Scene s(Color(.1,.1,.1),Color(0,0,0),1);

    s.addCamera(new Camera(new Vect(0,0,0),new Vect(-1,1,-3),new Vect(1,1,-3),new Vect(1,-1,-3),new Vect(-1,-1,-3),1000,1000));

    s.addLight(new DirectionalLight( *(new Vect(0.57735027,-0.57735027,-0.57735027)), Color(1,1,1)));
    s.addLight(new DirectionalLight( *(new Vect(-0.57735027,0.57735027,0.57735027)), Color(1,1,1)));

    s.addSurface(new Surface(new SphereGeometry(Vect(0,0,-17), 2.0), new Material(Color(1,0,0), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    s.addSurface(new Surface(new SphereGeometry(Vect(0,4,-17), 1.5), new Material(Color(0,1,0), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    //s.addSurface(new Surface(new SphereGeometry(Vect(0,-4,-17), 1.5), new Material(Color(0,0,1), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    //s.addSurface(new Surface(new SphereGeometry(Vect(4,0,-17), 1.5), new Material(Color(1,1,0), Color(1,1,1), Color(0.9,0.9,0.9), 50)));
    //s.addSurface(new Surface(new SphereGeometry(Vect(-4,0,-17), 1.5), new Material(Color(0,1,1), Color(1,1,1), Color(0.9,0.9,0.9), 50)));

    s.render("out.png");
}
