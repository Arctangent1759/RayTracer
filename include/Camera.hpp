#ifndef CAMERA_H
#define CAMERA_H

#include "Vect.hpp"

class Camera{
    public:
        friend ostream& operator<<(ostream& lhs, Camera& c);
        Camera(Vect eye, Vect ul, Vect ur, Vect lr, Vect ll, int imgWidth, int imgHeight);
        Camera(Vect eye, Vect lookat, Vect up, scalar fovy, int imgWidth, int imgHeight);
        Ray getRay(int i, int j);
        int getImgWidth();
        int getImgHeight();
    protected:
        Vect u,v;
        Vect eye;
        Vect ul;
        Vect ur;
        Vect ll;
        Vect lr;
        int imgWidth;
        int imgHeight;
};

ostream& operator<<(ostream& lhs, Camera& s);

#endif
