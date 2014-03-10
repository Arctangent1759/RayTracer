#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Vect.hpp"
#include <vector>

class Geometry{
    public:
        virtual Vect getIntersection(Ray r);
        virtual scalar getDistAlongRay(Ray r)=0;
        virtual Vect getNormal(Ray r)=0;
};

class SphereGeometry : public Geometry{
    friend ostream& operator<<(ostream& lhs, SphereGeometry& v);
    public:
        SphereGeometry(Vect center, scalar radius);
        virtual scalar getDistAlongRay(Ray r);
        virtual Vect getNormal(Ray r);
    protected:
        Vect center;
        scalar radius;
};

class PolygonGeometry : public Geometry{
    friend ostream& operator<<(ostream& lhs, PolygonGeometry& v);
    public:
        PolygonGeometry(vector<Vect> points);
        PolygonGeometry(Vect a, Vect b, Vect c);
        virtual scalar getDistAlongRay(Ray r);
        virtual Vect getNormal(Ray r);
    protected:
        void preprocess();
        vector<Vect> points;
        Vect n;
};

class ObjGeometry : public Geometry{
    friend ostream& operator<<(ostream& lhs, ObjGeometry& v);
    public:
        ObjGeometry(string filepath);
        virtual scalar getDistAlongRay(Ray r);
        virtual Vect getNormal(Ray r);
    protected:
        vector<PolygonGeometry> polygons;
};

ostream& operator<<(ostream& lhs, SphereGeometry& v);
ostream& operator<<(ostream& lhs, PolygonGeometry& v);
ostream& operator<<(ostream& lhs, ObjGeometry& v);

#endif
