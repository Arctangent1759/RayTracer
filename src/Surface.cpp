#include "Surface.hpp"

Surface::Surface(Geometry* g, Material* m, Transformation trans){
    this->geo=g;
    this->mat=m;
    this->trans = trans;
}
Surface::Surface(Geometry* g, Material* m){
    this->geo=g;
    this->mat=m;
    this->trans = Transformation();
}

scalar Surface::getDistAlongRay(Ray r){
    return this->geo->getDistAlongRay(this->trans.apply(r));
}

Vect Surface::getNormal(Ray r){
    return this->trans.inverse().transpose()*this->geo->getNormal(this->trans.apply(r));
}

Vect Surface::getIntersection(Ray r){
    return this->geo->getIntersection(this->trans.apply(r));
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
