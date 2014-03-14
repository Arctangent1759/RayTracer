#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.hpp"

class Material{
    public:
        Material(Color ca, Color cd, Color cs, Color cr, Color cf, scalar indexOfRefraction, scalar p);
        Material(Color ca, Color cd, Color cs, Color cr, scalar p);
        Material(Color cd, Color cs, Color cr, scalar p);
        Color getCa();
        Color getCd();
        Color getCs();
        Color getCr();
        Color getCf();
        scalar getP();
    protected:
        void init(Color ca, Color cd, Color cs, Color cr, Color cf, scalar indexOfRefraction, scalar p);
        Color ca; //Material ambient color
        Color cd; //Material diffuse color
        Color cs; //Material specular color
        Color cr; //Material reflective color
        Color cf; //Material refractive color
        scalar p; //Material specular exponent
        scalar indexOfRefraction;
};
#endif
