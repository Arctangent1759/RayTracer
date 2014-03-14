#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Vect.hpp"
#include "Matrix.hpp"

class Transformation {
    public:
        friend ostream& operator<<(ostream& lhs, Transformation& t);
        Transformation();
        Transformation(Matrix m);
        Transformation(Transformation* t);
        Matrix getTransformation();
        Transformation operator*(const Transformation rhs) const;
        Vect operator*(const Vect rhs) const;
        Transformation inverse() const;
        Transformation transpose() const;
        Ray apply(const Ray r) const;
    protected:
        Matrix m;
};

class Rotation : public Transformation {
    public:
        Rotation();
        Rotation(scalar angle, string axis);
        Rotation(scalar angle, Vect axis);
};

class Scale : public Transformation {
    public:
        Scale();
        Scale(scalar x, scalar y, scalar z);
};

class Translate : public Transformation {
    public:
        Translate();
        Translate(scalar x, scalar y, scalar z);
};

#endif

