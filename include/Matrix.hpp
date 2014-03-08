#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Vect.hpp"
#include <vector>

using namespace std;

class Matrix;

class Matrix {
  friend ostream& operator<<(ostream& lhs, Matrix& m);

  public:
    Matrix();
    Matrix(Matrix* m);
    Matrix(vector< vector<scalar> > m);

    Matrix& operator+(const Matrix& rhs) const;
    Matrix& operator-(const Matrix& rhs) const;
    Matrix& operator*(const Matrix& rhs) const;
    scalar operator()(int x, int y);

    Matrix& inverse(const Matrix& rhs) const;

  protected:
    vector< vector<scalar> > m;

