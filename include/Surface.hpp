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
        bool isIntersected(Ray r);
        Color getColor(Ray& r, Scene* s);
    protected:
        Geometry* geo;
        Material* mat;
};
#endif
