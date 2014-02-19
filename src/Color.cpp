#include "Color.hpp"
#include "stdexcept"
#include "math.h"

////////////////////////////
//  Color Implementations //
////////////////////////////
Color::Color(scalar r,scalar g,scalar b){
    if (r<0.0 || g<0.0 || b<0.0 || r>1.0 || g>1.0 || b>1.0){
        throw std::invalid_argument("Expected r g b between 0.0, 1.0.");
    }
    this->r=r;
    this->g=g;
    this->b=b;
}
Color::Color(){
    this->r=0;
    this->g=0;
    this->b=0;
}

Color& Color::operator+(Color& rhs){
    return *(new Color(max(min(this->r+rhs.r,1.0),0.0),max(min(this->g+rhs.g,1.0),0.0),max(min(this->b+rhs.b,1.0),0.0)));
}
Color& Color::operator-(Color& rhs){
    return *(new Color(max(min(this->r-rhs.r,1.0),0.0),max(min(this->g-rhs.g,1.0),0.0),max(min(this->b-rhs.b,1.0),0.0)));
}
Color& Color::operator*(scalar rhs){
    return *(new Color(max(min(this->r*rhs,1.0),0.0),max(min(this->g*rhs,1.0),0.0),max(min(this->b*rhs,1.0),0.0)));
}
Color& Color::operator/(scalar rhs){
    return *(this)*(1.0/rhs);
}

Color& Color::operator+=(Color& rhs){
    return *(this) = *(this) + rhs;
}
Color& Color::operator-=(Color& rhs){
    return *(this) = *(this) - rhs;
}
Color& Color::operator*=(scalar rhs){
    return *(this) = *(this) * rhs;
}
Color& Color::operator/=(scalar rhs){
    return *(this) = *(this) / rhs;
}

Color operator*(scalar lhs, Color& rhs){
    return rhs*lhs;
}
Color operator/(scalar lhs, Color& rhs){
    return rhs/lhs;
}

ostream& operator<<(ostream& lhs, Color& c){
    return lhs << "Color(" << c.r << ", " << c.g << ", " << c.b << ")";
}

////////////////////////////
//  BRDF Implementations  //
////////////////////////////

BRDF::BRDF(Color kd, Color ks, Color ka, Color kr){
    this->kd=kd;
    this->ks=ks;
    this->ka=ka;
    this->kr=kr;
}

ostream& operator<<(ostream& lhs, BRDF& b){
    return lhs << "BRDF(" << b.kd << b.ks << b.ka << b.kr << ")";
}
