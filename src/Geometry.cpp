#include "Geometry.hpp"
#include "math.h"
#include "stdexcept"
#include <algorithm>
#include <fstream>

////////////////////////////////
//  Geometry Implementations  //
////////////////////////////////

Vect Geometry::getIntersection(Ray r){
    return r.getPos() + r.getDir()*this->getDistAlongRay(r);
}

//////////////////////////////////////
//  SphereGeometry Implementations  //
//////////////////////////////////////

SphereGeometry::SphereGeometry(Vect center, scalar radius){
    this->center=center;
    this->radius=radius;
}
scalar SphereGeometry::getDistAlongRay(Ray r){
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
Vect SphereGeometry::getNormal(Ray r){
    Vect p = getIntersection(r);
    return normalized(p-this->center);
}

////////////////////////////////////////
//  PolygonGeometry Implementations  //
////////////////////////////////////////

struct PointComparator{
    inline bool operator() (const Vect v1, const Vect v2){
        return this->getKey(v1) < this->getKey(v2);
    }
    double getKey(Vect p){
        Vect r = normalized(p-this->center);
        scalar c = r*x;
        Vect crossProd = cross(r,x);
        scalar s = norm(crossProd) * ((this->y*r)>=0?1:-1);
        double out = atan2(s,c);
        if (out < 0){
            out += 2*M_PI;
        }
        return out;
    }
    Vect center;
    Vect x;
    Vect y;
};

PolygonGeometry::PolygonGeometry(vector<Vect> points){
    this->points = points;
    this->preprocess();

    Vect center(0,0,0);
    for (vector<Vect>::iterator i = points.begin(); i != points.end(); i++){
        center+=*i;
    }
    center/=points.size();

    PointComparator pc;
    pc.center=center;
    pc.x=normalized(points[0]-center);
    pc.y=cross(pc.x,this->n);

    std::sort(this->points.begin(),this->points.end(),pc);
}

PolygonGeometry::PolygonGeometry(Vect a, Vect b, Vect c){
    this->points = vector<Vect>(3);
    this->points[0]=a;
    this->points[1]=b;
    this->points[2]=c;
    this->preprocess();
}
void PolygonGeometry::preprocess(){
    //Preprocessing. Should make rendering faster.
    this->n=normalized(cross(this->points[1]-this->points[0],this->points[2]-this->points[0]));
    this->offset=this->n*this->points[0];
}
scalar PolygonGeometry::getDistAlongRay(Ray r){
    scalar t = (r.getPos()*this->n+this->offset)/(r.getDir()*this->n);
    Vect p = r.getPos()+t*r.getDir();

    if (t < 0){
        return -1;
    }
    int len = this->points.size();
    for (int i = 0; i < len; i++){
        if (cross(this->points[(len+i-1)%len]-this->points[(len+i)%len],p-this->points[(len+i)%len])*
                cross(this->points[(len+i-1)%len]-this->points[(len+i)%len],this->points[(len+i+1)%len]-this->points[(len+i)%len])<0){
            return -1;
        }
    }


    return t;
}
Vect PolygonGeometry::getNormal(Ray r){
    return ((this->n*r.getDir())<0?1.0:-1.0)*this->n;
}

///////////////////////////////////
//  ObjGeometry Implementations  //
///////////////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

ObjGeometry::ObjGeometry(string filepath){
    ifstream file("foobar.txt");
    string line;
    while (getline(file,line)){
        istringstream lstr(line);
        string token;
    }
}
scalar ObjGeometry::getDistAlongRay(Ray r){}
Vect ObjGeometry::getNormal(Ray r){}
