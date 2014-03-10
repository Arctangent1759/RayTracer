#ifndef MATRIX_H
#define MATRIX_H

#include "Vect.hpp"
#include <vector>

class Matrix {
  friend ostream& operator<<(ostream& lhs, Matrix& m);

  public:
    Matrix();
    Matrix(Matrix* m);
    Matrix(vector< vector<scalar> > m);
    Matrix(scalar a0, scalar a1, scalar a2, scalar a3, 
            scalar b0, scalar b1, scalar b2, scalar b3, 
            scalar c0, scalar c1, scalar c2, scalar c3, 
            scalar d0, scalar d1, scalar d2, scalar d3);
    Matrix(scalar a0, scalar a1, scalar a2, 
            scalar b0, scalar b1, scalar b2, 
            scalar c0, scalar c1, scalar c2);
    Matrix(scalar a0, scalar a1, 
            scalar b0, scalar b1);

    Matrix operator+(const Matrix rhs) const;
    Matrix operator-(const Matrix rhs) const;
    Matrix operator*(const Matrix rhs) const;
    Vect operator*(const Vect rhs) const;
    Matrix operator*(const scalar rhs) const;
    scalar operator()(int x, int y);

    Matrix inverse() const;

  protected:
    vector< vector<scalar> > m;
};

#endif
