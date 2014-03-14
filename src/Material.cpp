#include "Material.hpp"

Material::Material(Color ca, Color cd, Color cs, Color cr, Color cf, scalar indexOfRefraction, scalar p){
    this->init(ca,cd,cs,cr,cf,indexOfRefraction,p);
}
Material::Material(Color ca, Color cd, Color cs, Color cr, scalar p){
    this->init(ca,cd,cs,cr,Color(0,0,0),-1,p);
}
Material::Material(Color cd, Color cs, Color cr, scalar p){
    this->init(Color(0,0,0),cd,cs,cr,Color(0,0,0),-1,p);
}
void Material::init(Color ca, Color cd, Color cs, Color cr, Color cf, scalar indexOfRefraction, scalar p){
    this->ca = ca;
    this->cd = cd;
    this->cs = cs;
    this->cr = cr;
    this->cf = cf;
    this->p = p;
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
Color Material::getCf(){
    return this->cf;
}
scalar Material::getP(){
    return this->p;
}
