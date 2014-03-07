#include "Geometry.hpp"
#include "math.h"

SphereGeometry::SphereGeometry(Vect center, scalar radius){
    this->center=center;
    this->radius=radius;
}

scalar SphereGeometry::getDistAlongRay(Ray& r){
    Vect displacement = r.getPos() - this->center;
    Vect dir = r.getDir();

    scalar b = 2*displacement*r.getDir();
    scalar c = displacement*displacement - this->radius*this->radius;

    scalar discriminant = b*b-4*c;
    if (discriminant < 0){
        return -1;
    }else{
        scalar out = (-b - sqrt(discriminant))/2.0;
        if (out < 0){
            return -1;
        }else{
            return out;
        }
    }
}
Vect& SphereGeometry::getIntersection(Ray& r){
    return r.getPos() + r.getDir()*getDistAlongRay(r);
}

Vect& SphereGeometry::getNormal(Ray& r){
    Vect p = getIntersection(r);
    return normalized(p-this->center);
}
