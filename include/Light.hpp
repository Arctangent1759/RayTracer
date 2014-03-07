#ifndef LIGHT_H
#define LIGHT_H

#include "Vect.hpp"
#include "Color.hpp"

class Light{
    public:
        Light(Vect& pos, Color& cl);
        virtual Vect& getPos()=0;
        virtual Vect& getLightVector(Vect& position)=0;
        Color& getCl();
    protected:
        Vect pos;
        Color cl;
};

class DirectionalLight : public Light{
    public:
        DirectionalLight(Vect& dir, Color cl);
        virtual Vect& getPos();
        virtual Vect& getLightVector(Vect& position);
};

class PointLight : public Light{
    public:
        PointLight(Vect& pos, Color cl);
        virtual Vect& getPos();
        virtual Vect& getLightVector(Vect& position);
};

#endif
