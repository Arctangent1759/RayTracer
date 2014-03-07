#include "Light.hpp"

Light::Light(Vect& pos, Color& cl){
    this->pos = pos;
    this->cl = cl;
}
Color& Light::getCl(){
    return this->cl;
}

DirectionalLight::DirectionalLight(Vect& dir, Color cl) : Light(dir,cl){}
Vect& DirectionalLight::getPos(){
    return this->pos;
}
Vect& DirectionalLight::getLightVector(Vect& position){
    return -1*normalized(this->getPos());
}

PointLight::PointLight(Vect& pos, Color cl) : Light(pos,cl){}
Vect& PointLight::getPos(){
    return this->pos;
}
Vect& PointLight::getLightVector(Vect& position){
    return normalized(this->getPos()-position);
}
