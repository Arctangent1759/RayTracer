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
Ray& Camera::getRay(int i, int j){
    return *(new Ray(this->eye,(this->ul+i*u+j*v) - this->eye));
}
int Camera::getImgWidth(){
    return this->imgWidth;
}
int Camera::getImgHeight(){
    return this->imgHeight;
}
