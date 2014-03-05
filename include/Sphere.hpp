#ifndef SPHERE_H
#define SPHERE_H

#include "Vect.hpp"

class Sphere{
    public:
        Sphere(Vect center, scalar radius);
        bool isIntersected(Ray r);
    protected:
        Vect center;
        scalar radius;
};
#endif
