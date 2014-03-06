#include "Surface.hpp"

Surface::Surface(Geometry* g, Material* m){
    this->geo=g;
    this->mat=m;
}

bool Surface::isIntersected(Ray r){
    return this->geo->isIntersected(r);
}


Color Surface::getColor(Ray& r, Scene* s){
    //TODO: Implement BRDF here
    return this->mat->getCd();
}
