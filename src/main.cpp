#include <iostream>
#include "Color.hpp"
#include "Vect.hpp"
#include "Scene.hpp"

#include "ImgWriter.hpp"

using namespace std;

int main(){
  Scene s(new Vect(0,0,0),new Vect(-1,1,-1),new Vect(1,1,-1),new Vect(-1,-1,1),new Vect(-1,-1,-1),100,100);
  s.render("outfile.png");

  ImgWriter test0(100, 100);
  for (int i = 50; i < 100; i++) {
    for (int j = 50; j < 75; j++) {
      Color c(0.69, 0.09, 0.12);
      test0.setPixel(i, j, c);
    }
  }
  test0.write("test.png");
}
