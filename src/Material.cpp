#include "Material.hpp"

Material::Material(Color cd, Color cs, Color cr, scalar p){
    this->cd = cd;
    this->cs = cs;
    this->cr = cr;
    this->p=p;
}
Color Material::getCd(){
    return this->cd;
}
Color Material::getCs(){
    return this->cs;
}
Color Material::getCr(){
    return this->cr;
}
scalar Material::getP(){
    return this->p;
}
