#include "Material.hpp"

Material::Material(Color ca, Color cd, Color cs, Color cr, scalar p){
    this->ca = ca;
    this->cd = cd;
    this->cs = cs;
    this->cr = cr;
    this->p=p;
}
Material::Material(Color cd, Color cs, Color cr, scalar p){
    this->ca = Color(0,0,0);
    this->cd = cd;
    this->cs = cs;
    this->cr = cr;
    this->p=p;
}
Color Material::getCa(){
    return this->ca;
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
