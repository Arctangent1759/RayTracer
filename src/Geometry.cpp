#include "Geometry.hpp"
#include "math.h"

////////////////////////////////
//  Geometry Implementations  //
////////////////////////////////

Vect& Geometry::getIntersection(Ray& r){
    return r.getPos() + r.getDir()*this->getDistAlongRay(r);
}

//////////////////////////////////////
//  SphereGeometry Implementations  //
//////////////////////////////////////

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
Vect& SphereGeometry::getNormal(Ray& r){
    Vect p = getIntersection(r);
    return normalized(p-this->center);
}

////////////////////////////////////////
//  TriangleGeometry Implementations  //
////////////////////////////////////////

TriangleGeometry::TriangleGeometry(Vect a, Vect b, Vect c){
    this->a=a;
    this->b=b;
    this->c=c;
    //Preprocessing. Should make rendering faster.
    this->n=normalized(cross(b-a,c-a));
    this->offset=this->n*a;
}
scalar TriangleGeometry::getDistAlongRay(Ray& r){
    scalar t = (r.getPos()*this->n+this->offset)/(r.getDir()*this->n);
    Vect p = r.getPos()+t*r.getDir();
    if (cross(b-a,p-a)*cross(b-a,c-a)<0 
            || cross(c-b,p-b)*cross(c-b,a-b)<0 
            || cross(a-c,p-c)*cross(a-c,b-c)<0){
        return -1;
    }
    return t;
}
Vect& TriangleGeometry::getNormal(Ray& r){
    return ((this->n*r.getDir())<0?1.0:-1.0)*this->n;
}

