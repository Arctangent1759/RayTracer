#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.hpp"

class Material{
    public:
        Material(Color cd, Color cs, Color cr, scalar p);
        Color& getCd();
        Color& getCs();
        Color& getCr();
        scalar getP();
    protected:
        Color cd;
        Color cs;
        Color cr;
        scalar p;
};
#endif
