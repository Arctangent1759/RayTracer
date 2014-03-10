#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Vect.hpp"

class Geometry{
    public:
        virtual scalar getDistAlongRay(Ray r)=0;
        virtual Vect getIntersection(Ray r);
        virtual Vect getNormal(Ray r)=0;
};

class SphereGeometry : public Geometry{
    public:
        SphereGeometry(Vect center, scalar radius);
        virtual scalar getDistAlongRay(Ray r);
        virtual Vect getNormal(Ray r);
    protected:
        Vect center;
        scalar radius;
};

class TriangleGeometry : public Geometry{
    public:
        TriangleGeometry(Vect a, Vect b, Vect c);
        virtual scalar getDistAlongRay(Ray r);
        virtual Vect getNormal(Ray r);
    protected:
        Vect a;
        Vect b;
        Vect c;
        Vect n;
        scalar offset;
};

#endif
