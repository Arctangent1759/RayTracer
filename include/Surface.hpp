#ifndef SURFACE_H
#define SURFACE_H

#include "Vect.hpp"
#include "Color.hpp"
#include "Geometry.hpp"
#include "Material.hpp"
#include "Transformation.hpp"

class Scene;
class Surface{
    public:
        Surface(Geometry* g, Material* m, Transformation trans);
        Surface(Geometry* g, Material* m);
        Transformation getTransformation();
        scalar getDistAlongRay(Ray r);
        Vect getNormal(Ray r);
        Vect getIntersection(Ray r);
        Ray apply(Ray r);
        Color getCa();
        Color getCd();
        Color getCs();
        Color getCr();
        scalar getP();
    protected:
        Geometry* geo;
        Material* mat;
        Transformation trans;
};
#endif
