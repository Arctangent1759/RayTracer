#include "Camera.hpp"
Camera::Camera(Vect eye, Vect ul, Vect ur, Vect lr, Vect ll, int imgWidth, int imgHeight){
    this->eye=eye;
    this->ul=ul;
    this->ur=ur;
    this->ll=ll;
    this->lr=lr;
    this->imgWidth=imgWidth;
    this->imgHeight=imgHeight;
    this->u = (this->ur - this->ul)/this->imgWidth;
    this->v = (this->ll - this->ul)/this->imgHeight;
}
Ray Camera::getRay(int i, int j){
    return Ray(this->eye,(this->ul+(i+0.5)*u+(j+0.5)*v) - this->eye);
}
int Camera::getImgWidth(){
    return this->imgWidth;
}
int Camera::getImgHeight(){
    return this->imgHeight;
}
