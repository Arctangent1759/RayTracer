#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.hpp"

class Material{
    public:
        Material(Color ca, Color cd, Color cs, Color cr, scalar p);
        Material(Color cd, Color cs, Color cr, scalar p);
        Color getCa();
        Color getCd();
        Color getCs();
        Color getCr();
        scalar getP();
    protected:
        Color ca;
        Color cd;
        Color cs;
        Color cr;
        scalar p;
};
#endif
