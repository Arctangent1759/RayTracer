#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Vect.hpp"

class Geometry{
    public:
        virtual bool isIntersected(Ray& r)=0;
        virtual Vect getNormal(Ray& r)=0;
};

class SphereGeometry : public Geometry{
    public:
        SphereGeometry(Vect center, scalar radius);
        virtual bool isIntersected(Ray& r);
        virtual Vect getNormal(Ray& r);
    protected:
        Vect center;
        scalar radius;
};

#endif
