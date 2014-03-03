#include <iostream>
#include "Color.hpp"
#include "Vect.hpp"
#include "Scene.hpp"

using namespace std;

int main(){
    Scene s(new Vect(0,0,0),new Vect(-1,1,-1),new Vect(1,1,-1),new Vect(-1,-1,1),new Vect(-1,-1,-1),100,100);
    s.render("outfile.png");
}
