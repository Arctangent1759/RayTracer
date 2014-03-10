#ifndef SURFACE_H
#define SURFACE_H

#include "Vect.hpp"
#include "Color.hpp"
#include "Geometry.hpp"
#include "Material.hpp"

class Scene;
class Surface{
    public:
        Surface(Geometry* g, Material* m);
        scalar getDistAlongRay(Ray r);
        Vect getNormal(Ray r);
        Vect getIntersection(Ray r);
        Color getCd();
        Color getCs();
        Color getCr();
        scalar getP();
    protected:
        Geometry* geo;
        Material* mat;
};
#endif
