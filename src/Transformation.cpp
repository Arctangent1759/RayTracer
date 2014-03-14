#include "Transformation.hpp"
#include <math.h>
#include <vector>

//////////////////////
//  Transformation  //
//////////////////////

Transformation::Transformation() {
  this->m = Matrix();
}

Transformation::Transformation(Matrix m) {
  this->m = m;
}

Transformation::Transformation(Transformation* t) {
  this->m = t->m;
}

Matrix Transformation::getTransformation() {
  return this->m;
}

Transformation Transformation::operator*(const Transformation rhs) const {
  return Transformation(this->m * rhs.m);
}

Vect Transformation::operator*(const Vect rhs) const {
  return this->m * rhs;
}

Transformation Transformation::inverse() const {
  return Transformation((this->m).inverse());
}

Transformation Transformation::transpose() const {
  return Transformation((this->m).transpose());
}

Ray Transformation::apply(const Ray r) const {
  Transformation inv = this->inverse();
  return Ray(inv*r.getPos(), r.getDir());
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
    v = Vect(0, 1, 0);
  } else if (axis == "z") {
    v = Vect(0, 0, 1);
  }
  scalar a = v.getX();
  scalar b = v.getY();
  scalar c = v.getZ();
  vector< vector<scalar> > n(3, vector<scalar> (3, 0));
  n[1][0] = c;
  n[0][1] = -c;
  n[0][2] = -b;
  n[2][0] = b;
  n[2][1] = a;
  n[1][2] = -a;
  vector< vector<scalar> > n_2(3, vector<scalar> (3, 0));
  n_2[0][0] = (-(c*c)-(b*b));
  n_2[1][0] = a*b;
  n_2[2][0] = a*c;
  n_2[0][1] = a*b;
  n_2[1][1] = (-(c*c)-(a*a));
  n_2[2][1] = b*c;
  n_2[0][2] = a*c;
  n_2[1][2] = b*c;
  n_2[2][2] = (-(b*b)-(a*a));
  vector< vector<scalar> > r(4, vector<scalar> (4, 0));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      n[i][j] *= sin(angle);
      n_2[i][j] *= (1-cos(angle));
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j) {
        r[i][j] = 1 + n[i][j] + n_2[i][j];
      } else {
        r[i][j] = n[i][j] + n_2[i][j];
      }
    }
  }
  r[3][3] = 1;
  this->m = Matrix(r);
}

Rotation::Rotation(scalar angle, Vect axis) {
  scalar a = axis.getX();
  scalar b = axis.getY();
  scalar c = axis.getZ();
  vector< vector<scalar> > n(3, vector<scalar> (3, 0));
  n[1][0] = c;
  n[0][1] = -c;
  n[0][2] = -b;
  n[2][0] = b;
  n[2][1] = a;
  n[1][2] = -a;
  vector< vector<scalar> > n_2(3, vector<scalar> (3, 0));
  n_2[0][0] = (-(c*c)-(b*b));
  n_2[1][0] = a*b;
  n_2[2][0] = a*c;
  n_2[0][1] = a*b;
  n_2[1][1] = (-(c*c)-(a*a));
  n_2[2][1] = b*c;
  n_2[0][2] = a*c;
  n_2[1][2] = b*c;
  n_2[2][2] = (-(b*b)-(a*a));
  vector< vector<scalar> > r(4, vector<scalar> (4, 0));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      n[i][j] *= sin(angle);
      n_2[i][j] *= (1-cos(angle));
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j) {
        r[i][j] = 1 + n[i][j] + n_2[i][j];
      } else {
        r[i][j] = n[i][j] + n_2[i][j];
      }
    }
  }
  r[3][3] = 1;
  this->m = Matrix(r);
}

// Scale

Scale::Scale() : Transformation() {}

Scale::Scale(scalar x, scalar y, scalar z) : Transformation(Matrix(x,0,0,0, 0,y,0,0, 0,0,z,0, 0,0,0,1)) {}

// Translate

Translate::Translate() : Transformation() {}

Translate::Translate(scalar x, scalar y, scalar z) : Transformation(Matrix(1,0,0,x, 0,1,0,y, 0,0,1,z, 0,0,0,1)) {}

