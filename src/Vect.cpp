#include "Vect.hpp"
#include "math.h"

///////////////////////////
//  Vect Implementations //
///////////////////////////

Vect::Vect(){
    this->x=0;
    this->y=0;
    this->z=0;
}

Vect::Vect(Vect* v){
    this->x=v->x;
    this->y=v->y;
    this->z=v->z;
}

Vect::Vect(scalar x, scalar y, scalar z){
    this->x=x;
    this->y=y;
    this->z=z;
}

scalar Vect::getX() const{
    return this->x;
}
scalar Vect::getY() const{
    return this->y;
}
scalar Vect::getZ() const{
    return this->z;
}

Vect Vect::operator+(const Vect rhs) const{
    return Vect(this->x+rhs.x,this->y+rhs.y,this->z+rhs.z);
}

Vect Vect::operator-(const Vect rhs) const{
    return Vect(this->x-rhs.x,this->y-rhs.y,this->z-rhs.z);
}

scalar Vect::operator*(const Vect rhs) const{
    return this->x*rhs.x+this->y*rhs.y+this->z*rhs.z;
}

Vect Vect::operator*(const scalar rhs) const{
    return Vect(rhs*this->x,rhs*this->y,rhs*this->z);
}

Vect Vect::cross(const Vect rhs) const{
    return Vect(this->y * rhs.z - this->z * rhs.y,this->z * rhs.x - this->x * rhs.z,this->x * rhs.y - this->y * rhs.x);
}

Vect Vect::operator/(const scalar rhs) const{
    return *(this)*(1.0/rhs);
}

Vect Vect::operator+=(Vect rhs){
    *(this) = *(this) + rhs;
}

Vect Vect::operator-=(Vect rhs){
    *(this) = *(this) - rhs;
}

Vect Vect::operator/=(scalar rhs){
    *(this) = *(this) / rhs;
}

Vect Vect::operator*=(scalar rhs){
    *(this) = *(this) * rhs;
}


scalar Vect::normSq() const{
    return this->x*this->x+this->y*this->y+this->z*this->z;
}

scalar Vect::norm() const{
    return sqrt(this->normSq());
}

Vect Vect::normalized() const{
    double n = this->norm();
    return n==0?Vect(0,0,0):*(this)/n;
}

ostream& operator<<(ostream& lhs, Vect& v){
    return lhs << "Vect(" << v.x << ", " << v.y << ", " << v.z << ")";
}

Vect operator*(const scalar s, const Vect v){return v*s;}

Vect cross(const Vect u, const Vect v){return u.cross(v);}

scalar normSq(const Vect v){return v.normSq();}

scalar norm(const Vect v){return v.norm();}

Vect normalized(const Vect v){
    return v.normalized();
}

Vect project(const Vect u, const Vect v){
    return (((u)*(v))/normSq(v))*v;
}

Vect perp(const Vect u, const Vect v){
    return u-project(u,v);
}

///////////////////////////
//  Ray Implementations  //
///////////////////////////

Ray::Ray(Vect p, Vect v){
    this->pos=p;
    this->dir=v;
}

void Ray::setPos(Vect v){
    this->pos=v;
}
void Ray::setDir(Vect v){
    this->dir=v;
}
Vect Ray::getPos() const{
    return this->pos;
}
Vect Ray::getDir() const{
    return this->dir;
}

ostream& operator<<(ostream& lhs, Ray& r){
    return lhs << "Ray(" << r.pos << ", " << r.dir << ")";
}
