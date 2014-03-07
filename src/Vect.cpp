#include "Vect.hpp"
#include "math.h"

///////////////////////////
//  Vect Implementations //
///////////////////////////

Vect::Vect(){
    vector = Eigen::Vector3d(0.0, 0.0, 0.0);
}

Vect::Vect(Vect* v){
    vector = v->vector;
}

Vect::Vect(scalar x, scalar y, scalar z){
    vector = Eigen::Vector3d(x, y, z);
}

Vect::Vect(Eigen::Vector3d v) {
    vector = v;
}

Vect& Vect::operator+(const Vect& rhs) const{
    return *(new Vect(this->vector + rhs.vector));
}

Vect& Vect::operator-(const Vect& rhs) const{
    return *(new Vect(this->vector - rhs.vector));
}

scalar Vect::operator*(const Vect& rhs) const{
    return this->vector.dot(rhs.vector);
}

Vect& Vect::operator*(const scalar rhs) const{
    return *(new Vect(rhs * this->vector));
}

Vect& Vect::cross(const Vect& rhs) const{
    return *(new Vect(this->vector.cross(rhs.vector)));
}

Vect& Vect::operator/(const scalar rhs) const{
    return *(new Vect(this->vector / rhs));
}

Vect& Vect::operator+=(Vect& rhs){
    *(this) = *(this) + rhs;
}

Vect& Vect::operator-=(Vect& rhs){
    *(this) = *(this) - rhs;
}

Vect& Vect::operator/=(scalar rhs){
    *(this) = *(this) / rhs;
}

Vect& Vect::operator*=(scalar rhs){
    *(this) = *(this) * rhs;
}


scalar Vect::normSq() const{
    return (*this)*(*this);
}

scalar Vect::norm() const{
    return sqrt(this->normSq());
}

Vect& Vect::normalized() const{
    double n = this->norm();
    return n==0?*(new Vect(0,0,0)):*(this)/n;
}

Vect& Vect::normalize(){
    return *(this)/=this->norm();
}

ostream& operator<<(ostream& lhs, Vect& v){
    return lhs << "Vect(" << v.vector[0] << ", " << v.vector[1] << ", " << v.vector[2] << ")";
}

Vect& operator*(const scalar s, const Vect& v){return v*s;}

Vect& cross(const Vect& u, const Vect& v){return u.cross(v);}

scalar normSq(const Vect& v){return v.normSq();}

scalar norm(const Vect& v){return v.norm();}

Vect& normalized(const Vect& v){
    return v.normalized();
}

Vect& normalize(Vect& v){
    return v.normalize();
}

Vect& project(const Vect& u, const Vect& v){
    return (((u)*(v))/normSq(v))*v;
}

Vect& perp(const Vect& u, const Vect& v){
    return u-project(u,v);
}

/////////////////////////////
//  Point Implementations  //
/////////////////////////////

Point::Point() : Vect(){}

Point::Point(scalar x, scalar y, scalar z) : Vect(x,y,z){}

ostream& operator<<(ostream& lhs, Point& v){
    return lhs << "Point(" << v.vector[0] << ", " << v.vector[1] << ", " << v.vector[2] << ")";
}

///////////////////////////
//  Ray Implementations  //
///////////////////////////

Ray::Ray(Vect& p, Vect& v){
    this->pos=p;
    this->dir=normalized(v);
}

void Ray::setPos(Vect& v){
    this->pos=v;
}
void Ray::setDir(Vect& v){
    this->dir=normalized(v);
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
