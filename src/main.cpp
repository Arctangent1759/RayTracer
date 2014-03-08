#include <iostream>
#include "Color.hpp"
#include "Vect.hpp"
#include "Scene.hpp"
#include "Surface.hpp"
#include "Matrix.hpp"

#include "ImgWriter.hpp"

using namespace std;

int main(){
  //matrix tests
  //constructor/print tests
  Matrix m0;
  vector< vector<scalar> > v0(4, vector<scalar> (4, 3));
  Matrix m1(v0);
  Matrix m2(m1);
  Matrix m3(5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5);
  Matrix m4(5,5,5,5,5,5,5,5,5);
  Matrix m5(5,5,5,5);
  cout << m0 << endl << m1 << endl << m2 << endl << m3 << endl << m4 << endl << m5 << endl;

  //add/subtract
  Matrix m6 = m4 + m5;
  Matrix m7 = m4 - m5;
  cout << m6 << endl << m7 << endl;

  //matrix multiplication and access
  Matrix m8 = m6 * m4;
  cout << m8 << endl << m8(2, 1) << endl;

  //matrix and vector multiplication
  Vect v1(3, 3, 3);
  Vect v2 = m6 * v1;
  cout << v2 << endl;

  //matrix scalar
  scalar s0 = 5;
  Matrix m9 = m6 * s0;
  cout << m9 << endl;

  //matrix inverse
  Matrix m10(4,0,0,0,0,0,2,0,0,1,2,0,1,0,0,1);
  cout << m10.inverse() << endl;

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
