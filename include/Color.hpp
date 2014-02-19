#include "Vect.hpp"

class Color{
    friend ostream& operator<<(ostream& lhs, Color& c);
    public:
        Color(scalar r,scalar g,scalar b);
        Color();

        Color& operator+(Color& rhs);
        Color& operator-(Color& rhs);
        Color& operator*(scalar rhs);
        Color& operator/(scalar rhs);

        Color& operator+=(Color& rhs);
        Color& operator-=(Color& rhs);
        Color& operator*=(scalar rhs);
        Color& operator/=(scalar rhs);
    protected:
        scalar r,g,b;
};

ostream& operator<<(ostream& lhs, Color& c);
Color operator*(scalar lhs, Color& rhs);
Color operator/(scalar lhs, Color& rhs);

class BRDF{
    public:
    friend ostream& operator<<(ostream& lhs, BRDF& b);
        BRDF(Color kd, Color ks, Color ka, Color kr);
    protected:
        Color kd, ks, ka, kr;

};

ostream& operator<<(ostream& lhs, BRDF& b);
