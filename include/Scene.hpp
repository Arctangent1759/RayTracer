#ifndef SCENE_H
#define SCENE_H

#include "Vect.hpp"

class Scene{
    public:
        Scene(Vect eye, Vect ul, Vect ur, Vect ll, Vect lr, int imgWidth, int imgHeight);
        void render(string filepath);
    protected:
        void init(Vect eye, Vect ul, Vect ur, Vect ll, Vect lr, int imgWidth, int imgHeight);
        Vect eye;
        Vect ul;
        Vect ur;
        Vect ll;
        Vect lr;
        int imgWidth;
        int imgHeight;

};

#endif
