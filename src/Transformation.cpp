#include "Transformation.hpp"
#include <math.h>
#include <vector>

//////////////////////
//  Transformation  //
//////////////////////

Transformation::Transformation() {
  this->m = Matrix();
  init();
}

Transformation::Transformation(Matrix m) {
  this->m = m;
  init();
}

Transformation::Transformation(Transformation* t) {
  this->m = t->m;
  this->m_inverse = t->m_inverse;
  this->m_transpose = t->m_transpose;
  this->m_inverse_transpose = t->m_inverse_transpose;
}

void Transformation::init(){
    this->m_inverse = this->m.inverse();
    this->m_transpose = this->m.transpose();
    this->m_inverse_transpose = this->m.inverse().transpose();
}

Matrix Transformation::getTransformation() {
  return this->m;
}

Matrix Transformation::getInverseTranspose() {
    return this->m_inverse_transpose;
}

Transformation Transformation::operator*(const Transformation rhs) const {
  return Transformation(this->m * rhs.m);
}

Vect Transformation::operator*(const Vect rhs) const {
  return this->m * rhs;
}

Transformation Transformation::inverse() const {
  return Transformation(this->m_inverse);
}

Transformation Transformation::transpose() const {
  return Transformation(this->m_transpose);
}

Ray Transformation::apply(const Ray r) const {
  return Ray(this->m_inverse*r.getPos(), this->m_inverse*r.getDir());
}

ostream& operator<<(ostream& lhs, Transformation& t) {
  return lhs << t.m;
}

// Rotation

Rotation::Rotation() : Transformation() {}

Rotation::Rotation(scalar angle, string axis) {
  Vect v;
  if (axis == "x") {
    v = Vect(1, 0, 0);
  } else if (axis == "y") {
    v = Vect(0, -1, 0);
  } else if (axis == "z") {
    v = Vect(0, 0, 1);
  }
  scalar a = v.getX();
  scalar b = v.getY();
  scalar c = v.getZ();
  vector< vector<scalar> > n(4, vector<scalar> (4, 0));
  n[1][0] = c;
  n[0][1] = -c;
  n[0][2] = -b;
  n[2][0] = b;
  n[2][1] = a;
  n[1][2] = -a;
  Matrix n1(n);
  Matrix n2(n1*n1);
  this->m = n1*sin(angle)+n2*(1-cos(angle))+Matrix();
  scalar t1 = sin(angle);
  scalar t2 = (1-cos(angle));
  this->m.maintainHomogeneous();
}

Rotation::Rotation(scalar angle, Vect axis) {
  scalar a = axis.getX();
  scalar b = axis.getY();
  scalar c = axis.getZ();
  vector< vector<scalar> > n(4, vector<scalar> (4, 0));
  n[1][0] = c;
  n[0][1] = -c;
  n[0][2] = -b;
  n[2][0] = b;
  n[2][1] = a;
  n[1][2] = -a;
  n[3][3] = 1;
  Matrix n1(n);
  Matrix n2(n1*n1);
  this->m = n1*sin(angle)+n2*(1-cos(angle))+Matrix();
  this->m.maintainHomogeneous();
}

Rotation::Rotation(scalar x, scalar y, scalar z) {
  this->m = (Rotation(x, "x")*Rotation(y, "y")*Rotation(z, "z")).getTransformation();
  this->m.maintainHomogeneous();
}

// Scale

Scale::Scale() : Transformation() {}

Scale::Scale(scalar x, scalar y, scalar z) : Transformation(Matrix(x,0,0,0, 0,y,0,0, 0,0,z,0, 0,0,0,1)) {}

// Translate

Translate::Translate() : Transformation() {}

Translate::Translate(scalar x, scalar y, scalar z) : Transformation(Matrix(1,0,0,x, 0,1,0,y, 0,0,1,z, 0,0,0,1)) {}

