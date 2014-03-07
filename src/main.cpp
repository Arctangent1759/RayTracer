#include <iostream>
#include "Color.hpp"
#include "Vect.hpp"
#include "Scene.hpp"
#include "Surface.hpp"

#include "ImgWriter.hpp"

using namespace std;

int main(){
  Scene s;
  s.addCamera(new Camera(new Vect(0,0,0),new Vect(-1,1,-1),new Vect(1,1,-1),new Vect(1,-1,-1),new Vect(-1,-1,-1),100,100));
  s.addSurface(new Surface(new SphereGeometry(Vect(0,0,-2),1),new Material(Color(1.0,0.0,0.0),Color(1.0,1.0,1.0),32.0)));
  s.render("out.png");
}
