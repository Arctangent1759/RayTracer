#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.hpp"

class Material{
    public:
        Material(Color cd, Color cs, scalar p);
        Color& getCd();
        Color& getCs();
        scalar getP();
    protected:
        Color cd;
        Color cs;
        scalar p;
};
#endif
