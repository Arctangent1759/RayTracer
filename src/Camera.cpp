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

Camera::Camera(Vect eye, Vect lookat, Vect up, scalar fovy, int imgWidth, int imgHeight){
    this->eye=eye;
    Vect center = eye+lookat;
    Vect y = normalized(up);
    Vect x = normalized(cross(y,normalized(lookat)));
    scalar fovx = (fovy*imgWidth)/imgHeight;
    this->ul=center+((fovy/2.0)*y)-((fovx/2.0)*x);
    this->ur=center+((fovy/2.0)*y)+((fovx/2.0)*x);
    this->ll=center-((fovy/2.0)*y)-((fovx/2.0)*x);
    this->lr=center-((fovy/2.0)*y)+((fovx/2.0)*x);
    this->imgWidth=imgWidth;
    this->imgHeight=imgHeight;
    this->u = (this->ur - this->ul)/this->imgWidth;
    this->v = (this->ll - this->ul)/this->imgHeight;
}

Ray Camera::getRay(int i, int j){
    return Ray(this->eye,normalized((this->ul+(i+0.5)*u+(j+0.5)*v) - this->eye));
}

int Camera::getImgWidth(){
    return this->imgWidth;
}

int Camera::getImgHeight(){
    return this->imgHeight;
}
