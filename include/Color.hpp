#ifndef COLOR_H
#define COLOR_H

#include "Vect.hpp"

class Color{
    friend ostream& operator<<(ostream& lhs, Color& c);
    public:
        Color(scalar r,scalar g,scalar b);
        Color();

        void setR(scalar r);
        void setG(scalar g);
        void setB(scalar b);

        scalar getR() const;
        scalar getG() const;
        scalar getB() const;

        bool operator==(Color rhs) const;

        Color operator+(Color rhs) const;
        Color operator-(Color rhs) const;
        Color operator*(scalar rhs) const;
        Color operator*(Color rhs) const;
        Color operator/(scalar rhs) const;

        Color operator+=(Color rhs);
        Color operator-=(Color rhs);
        Color operator*=(scalar rhs);
        Color operator/=(scalar rhs);
    protected:
        scalar r,g,b;
};

ostream& operator<<(ostream& lhs, Color& c);
Color operator*(scalar lhs, Color rhs);
Color operator/(scalar lhs, Color rhs);

#endif
