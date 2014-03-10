#include "Surface.hpp"

Surface::Surface(Geometry* g, Material* m){
    this->geo=g;
    this->mat=m;
}

scalar Surface::getDistAlongRay(Ray r){
    return this->geo->getDistAlongRay(r);
}

Vect Surface::getNormal(Ray r){
    return this->geo->getNormal(r);
}

Vect Surface::getIntersection(Ray r){
    return this->geo->getIntersection(r);
}

Color Surface::getCa(){
    return this->mat->getCa();
}

Color Surface::getCd(){
    return this->mat->getCd();
}

Color Surface::getCs(){
    return this->mat->getCs();
}

Color Surface::getCr(){
    return this->mat->getCr();
}

scalar Surface::getP(){
    return this->mat->getP();
}
