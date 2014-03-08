#ifndef VECT_H
#define VECT_H

#include <iostream>

using namespace std;

class Vect;
class Normal;
class Point;
class Ray;

typedef double scalar;

class Vect{
    friend class Normal;
    friend ostream& operator<<(ostream& lhs, Vect& v);

    public:
        Vect();
        Vect(Vect* v);
        Vect(scalar x, scalar y, scalar z);

        scalar getX();
        scalar getY();
        scalar getZ();

        virtual Vect& operator+(const Vect& rhs) const;
        virtual Vect& operator-(const Vect& rhs) const;
        scalar operator*(const Vect& rhs) const;
        Vect& operator*(const scalar rhs) const;
        Vect& cross(const Vect& rhs) const;
        Vect& operator/(const scalar rhs) const;

        virtual Vect& operator+=(Vect& rhs);
        virtual Vect& operator-=(Vect& rhs);
        Vect& operator/=(scalar rhs);
        Vect& operator*=(scalar rhs);

        scalar normSq() const;
        scalar norm() const;
        Vect& normalized() const;
        Vect& normalize();

    protected:
        scalar x,y,z;
};

ostream& operator<<(ostream& lhs, Vect& v);

Vect& operator*(const scalar s, const Vect& v);
Vect& cross(const Vect& u, const Vect& v);
scalar normSq(const Vect& v);
scalar norm(const Vect& v);
Vect& normalized(const Vect& v);
Vect& normalize(Vect& v);
Vect& project(const Vect& u, const Vect& v);
Vect& perp(const Vect& u, const Vect& v);


class Normal : public Vect{
    friend ostream& operator<<(ostream& lhs, Normal& v);

    public:
        Normal();
        Normal(scalar x, scalar y, scalar z);
        Normal(Vect& v);
        Normal& operator+(Vect& rhs) const;
        Normal& operator-(Vect& rhs) const;
        Normal& operator+=(Vect& rhs);
        Normal& operator-=(Vect& rhs);
};

ostream& operator<<(ostream& lhs, Normal& v);

class Point : public Vect{
    friend ostream& operator<<(ostream& lhs, Point& v);
    public:
        Point();
        Point(scalar x, scalar y, scalar z);
};

class Ray {
    friend ostream& operator<<(ostream& lhs, Ray& r);
    public:
        Ray(Vect& p, Vect& v);

        void setPos(Vect& v);
        void setDir(Vect& v);
        Vect getPos() const;
        Vect getDir() const;

    protected:
        Vect pos;
        Vect dir;
        scalar t_min, t_max;
};

#endif
