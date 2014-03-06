#include "Material.hpp"

Material::Material(Color cd, Color cs, scalar p){
    this->cd = cd;
    this->cs = cs;
}
Color& Material::getCd(){
    return this->cd;
}
Color& Material::getCs(){
    return this->cs;
}
scalar Material::getP(){
    return this->p;
}
