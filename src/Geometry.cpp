#include "Geometry.hpp"

SphereGeometry::SphereGeometry(Vect center, scalar radius){
    this->center=center;
    this->radius=radius;
}

bool SphereGeometry::isIntersected(Ray& r){
    Vect displacement = this->center - r.getPos();
    return displacement * r.getDir() >= 0 && normSq(perp(displacement, r.getDir())) <= this->radius*this->radius;
}

Vect SphereGeometry::getNormal(Ray& r){
    //TODO: Implement
}
