#include "Sphere.hpp"

Sphere::Sphere(Vect center, scalar radius){
    this->center=center;
    this->radius=radius;
}

bool Sphere::isIntersected(Ray r){
    Vect displacement = this->center - r.getPos();
    return displacement * r.getDir() >= 0 && normSq(perp(displacement, r.getDir())) <= this->radius*this->radius;
}
