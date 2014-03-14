#include "Matrix.hpp"
#include "stdexcept"

Matrix::Matrix() {
  vector< vector<scalar> > m(4, vector<scalar> (4, 0));
  for (int i = 0; i < 4; i++) {
    m[i][i] = 1;
  }
  this->m = m;
}

Matrix::Matrix(Matrix* v) {
  this->m = v->m;
}

Matrix::Matrix(vector< vector<scalar> > m) {
  if (m.size() > 4) {
    throw std::invalid_argument("Expected horizontal size between 0, 4 (inclusive).");
  }
  for (int i = 0; i < m.size(); i++) {
    if (m[i].size() > 4) {
      throw std::invalid_argument("Expected vertical size between 0, 4 (inclusive).");
    }
  }
  this->m = m;
  if (this->m.size() < 4) {
    this->m.resize(4, vector<scalar> (4, 0));
  }
  for (int i = 0; i < this->m.size(); i++) {
    if (this->m[i].size() < 4) {
      this->m[i].resize(4, 0);
    }
  }
}


Matrix::Matrix(scalar a0, scalar a1, scalar a2, scalar a3, scalar b0, scalar b1, scalar b2, scalar b3, scalar c0, scalar c1, scalar c2, scalar c3, scalar d0, scalar d1, scalar d2, scalar d3) {
  vector< vector<scalar> > v (4, vector<scalar> (4, 0));
  v[0][0] = a0;
  v[0][1] = a1;
  v[0][2] = a2;
  v[0][3] = a3;
  v[1][0] = b0;
  v[1][1] = b1;
  v[1][2] = b2;
  v[1][3] = b3;
  v[2][0] = c0;
  v[2][1] = c1;
  v[2][2] = c2;
  v[2][3] = c3;
  v[3][0] = d0;
  v[3][1] = d1;
  v[3][2] = d2;
  v[3][3] = d3;
  this->m = v;
}

Matrix::Matrix(scalar a0, scalar a1, scalar a2, scalar b0, scalar b1, scalar b2, scalar c0, scalar c1, scalar c2) {
  vector< vector<scalar> > v (4, vector<scalar> (4, 0));
  v[0][0] = a0;
  v[0][1] = a1;
  v[0][2] = a2;
  v[1][0] = b0;
  v[1][1] = b1;
  v[1][2] = b2;
  v[2][0] = c0;
  v[2][1] = c1;
  v[2][2] = c2;
  this->m = v;
}

Matrix::Matrix(scalar a0, scalar a1, scalar b0, scalar b1) {
  vector< vector<scalar> > v (4, vector<scalar> (4, 0));
  v[0][0] = a0;
  v[0][1] = a1;
  v[1][0] = b0;
  v[1][1] = b1;
  this->m = v;
}

Matrix Matrix::operator+(const Matrix rhs) const {
  if (this->m.size() != (rhs.m).size()) {
    throw std::invalid_argument("Horizontal size of argument and matrix must be the same.");
  }
  vector< vector<scalar> > added (4, vector<scalar> (4, 0));
  for (int i = 0; i < this->m.size(); i++) {
    for (int j = 0; j < this->m[i].size(); j++) {
      if (this->m[i].size() != (rhs.m)[i].size()) {
        throw std::invalid_argument("Vertical size of argument and matrix must be the same.");
      }
      added[i][j] = this->m[i][j]+(rhs.m)[i][j];
    }
  }
  return Matrix(added);
}

Matrix Matrix::operator-(const Matrix rhs) const {
  if (this->m.size() != (rhs.m).size()) {
    throw std::invalid_argument("Horizontal size of argument and matrix must be the same.");
  }
  vector< vector<scalar> > subtracted (4, vector<scalar> (4, 0));
  for (int i = 0; i < this->m.size(); i++) {
    for (int j = 0; j < this->m[i].size(); j++) {
      if (this->m[i].size() != (rhs.m)[i].size()) {
        throw std::invalid_argument("Vertical size of argument and matrix must be the same.");
      }
      subtracted[i][j] = this->m[i][j]-(rhs.m)[i][j];
    }
  }
  return Matrix(subtracted);
}

Matrix Matrix::operator*(const Matrix rhs) const {
  scalar a0 = this->m[0][0];
  scalar a1 = this->m[0][1];
  scalar a2 = this->m[0][2];
  scalar a3 = this->m[0][3];
  scalar b0 = this->m[1][0];
  scalar b1 = this->m[1][1];
  scalar b2 = this->m[1][2];
  scalar b3 = this->m[1][3];
  scalar c0 = this->m[2][0];
  scalar c1 = this->m[2][1];
  scalar c2 = this->m[2][2];
  scalar c3 = this->m[2][3];
  scalar d0 = this->m[3][0];
  scalar d1 = this->m[3][1];
  scalar d2 = this->m[3][2];
  scalar d3 = this->m[3][3];

  scalar x0 = (rhs.m)[0][0];
  scalar x1 = (rhs.m)[0][1];
  scalar x2 = (rhs.m)[0][2];
  scalar x3 = (rhs.m)[0][3];
  scalar f0 = (rhs.m)[1][0];
  scalar f1 = (rhs.m)[1][1];
  scalar f2 = (rhs.m)[1][2];
  scalar f3 = (rhs.m)[1][3];
  scalar g0 = (rhs.m)[2][0];
  scalar g1 = (rhs.m)[2][1];
  scalar g2 = (rhs.m)[2][2];
  scalar g3 = (rhs.m)[2][3];
  scalar h0 = (rhs.m)[3][0];
  scalar h1 = (rhs.m)[3][1];
  scalar h2 = (rhs.m)[3][2];
  scalar h3 = (rhs.m)[3][3];

  vector< vector<scalar> > m (4, vector<scalar> (4, 0));
  m[0][0] = a1*f0+a2*g0+a3*h0+a0*x0;
  m[1][0] = b1*f0+b2*g0+b3*h0+b0*x0;
  m[2][0] = c1*f0+c2*g0+c3*h0+c0*x0;
  m[3][0] = d1*f0+d2*g0+d3*h0+d0*x0;
        
  m[0][1] = a1*f1+a2*g1+a3*h1+a0*x1;
  m[1][1] = b1*f1+b2*g1+b3*h1+b0*x1;
  m[2][1] = c1*f1+c2*g1+c3*h1+c0*x1;
  m[3][1] = d1*f1+d2*g1+d3*h1+d0*x1;
        
  m[0][2] = a1*f2+a2*g2+a3*h2+a0*x2;
  m[1][2] = b1*f2+b2*g2+b3*h2+b0*x2;
  m[2][2] = c1*f2+c2*g2+c3*h2+c0*x2;
  m[3][2] = d1*f2+d2*g2+d3*h2+d0*x2;
        
  m[0][3] = a1*f3+a2*g3+a3*h3+a0*x3;
  m[1][3] = b1*f3+b2*g3+b3*h3+b0*x3;
  m[2][3] = c1*f3+c2*g3+c3*h3+c0*x3;
  m[3][3] = d1*f3+d2*g3+d3*h3+d0*x3;

  return Matrix(m);
}

Vect Matrix::operator*(const Vect rhs) const {
  scalar a0 = this->m[0][0];
  scalar a1 = this->m[0][1];
  scalar a2 = this->m[0][2];
  scalar a3 = this->m[0][3];
  scalar b0 = this->m[1][0];
  scalar b1 = this->m[1][1];
  scalar b2 = this->m[1][2];
  scalar b3 = this->m[1][3];
  scalar c0 = this->m[2][0];
  scalar c1 = this->m[2][1];
  scalar c2 = this->m[2][2];
  scalar c3 = this->m[2][3];
  scalar d0 = this->m[3][0];
  scalar d1 = this->m[3][1];
  scalar d2 = this->m[3][2];
  scalar d3 = this->m[3][3];

  scalar x = rhs.getX();
  scalar y = rhs.getY();
  scalar z = rhs.getZ();
  scalar q = 1;
  if (rhs.isDir()) {
    q = 0;
  }

  scalar row0 = a3*q+a0*x+a1*y+a2*z;
  scalar row1 = b3*q+b0*x+b1*y+b2*z;
  scalar row2 = c3*q+c0*x+c1*y+c2*z;
  scalar row3 = d3*q+d0*x+d1*y+d2*z;

  if (row3 == 0) {
    return Vect(row0, row1, row2);
  }
  return Vect(row0/row3, row1/row3, row2/row3);
}

Matrix Matrix::operator*(const scalar rhs) const {
  vector< vector<scalar> > v (4, vector<scalar> (4, 0));
  for (int i = 0; i < this->m.size(); i++) {
    for (int j = 0; j < this->m[i].size(); j++) {
      v[i][j] = this->m[i][j]*rhs;
    }
  }
  return Matrix(v);
}

Matrix Matrix::inverse() const {
  scalar a0 = this->m[0][0];
  scalar a1 = this->m[1][0];
  scalar a2 = this->m[2][0];
  scalar a3 = this->m[3][0];
  scalar b0 = this->m[0][1];
  scalar b1 = this->m[1][1];
  scalar b2 = this->m[2][1];
  scalar b3 = this->m[3][1];
  scalar c0 = this->m[0][2];
  scalar c1 = this->m[1][2];
  scalar c2 = this->m[2][2];
  scalar c3 = this->m[3][2];
  scalar d0 = this->m[0][3];
  scalar d1 = this->m[1][3];
  scalar d2 = this->m[2][3];
  scalar d3 = this->m[3][3];
  scalar det = (a0*b1*c2*d3-a0*b1*c3*d2-a0*b2*c1*d3+a0*b2*c3*d1+a0*b3*c1*d2-a0*b3*c2*d1-a1*b0*c2*d3+a1*b0*c3*d2+a1*b2*c0*d3-a1*b2*c3*d0-a1*b3*c0*d2+a1*b3*c2*d0+a2*(b0*c1*d3-b0*c3*d1-b1*c0*d3+b1*c3*d0+b3*c0*d1-b3*c1*d0)+a3*(-b0*c1*d2+b0*c2*d1+b1*c0*d2-b1*c2*d0-b2*c0*d1+b2*c1*d0));
  if (det == 0) {
    throw std::invalid_argument("Determinant of matrix must be zero.");
  }
  scalar indet = 1.0 / det;
  vector< vector<scalar> > m (4, vector<scalar> (4, 0));
  m[0][0] = -b3*c2*d1+b2*c3*d1+b3*c1*d2-b1*c3*d2-b2*c1*d3+b1*c2*d3;
  m[0][1] = b3*c2*d0-b2*c3*d0-b3*c0*d2+b0*c3*d2+b2*c0*d3-b0*c2*d3;
  m[0][2] = -b3*c1*d0+b1*c3*d0+b3*c0*d1-b0*c3*d1-b1*c0*d3+b0*c1*d3;
  m[0][3] = b2*c1*d0-b1*c2*d0-b2*c0*d1+b0*c2*d1+b1*c0*d2-b0*c1*d2;
  m[1][0] = a3*c2*d1-a2*c3*d1-a3*c1*d2+a1*c3*d2+a2*c1*d3-a1*c2*d3;
  m[1][1] = -a3*c2*d0+a2*c3*d0+a3*c0*d2-a0*c3*d2-a2*c0*d3+a0*c2*d3;
  m[1][2] = a3*c1*d0-a1*c3*d0-a3*c0*d1+a0*c3*d1+a1*c0*d3-a0*c1*d3;
  m[1][3] = -a2*c1*d0+a1*c2*d0+a2*c0*d1-a0*c2*d1-a1*c0*d2+a0*c1*d2;
  m[2][0] = -a3*b2*d1+a2*b3*d1+a3*b1*d2-a1*b3*d2-a2*b1*d3+a1*b2*d3;
  m[2][1] = a3*b2*d0-a2*b3*d0-a3*b0*d2+a0*b3*d2+a2*b0*d3-a0*b2*d3;
  m[2][2] = -a3*b1*d0+a1*b3*d0+a3*b0*d1-a0*b3*d1-a1*b0*d3+a0*b1*d3;
  m[2][3] = a2*b1*d0-a1*b2*d0-a2*b0*d1+a0*b2*d1+a1*b0*d2-a0*b1*d2;
  m[3][0] = a3*b2*c1-a2*b3*c1-a3*b1*c2+a1*b3*c2+a2*b1*c3-a1*b2*c3;
  m[3][1] = -a3*b2*c0+a2*b3*c0+a3*b0*c2-a0*b3*c2-a2*b0*c3+a0*b2*c3; m[3][2] = a3*b1*c0-a1*b3*c0-a3*b0*c1+a0*c3*c1+a1*b0*c3-a0*b1*c3;
  m[3][3] = -a2*b1*c0+a1*b2*c0+a2*b0*c1-a0*b2*c1-a1*b0*c2+a0*b1*c2;

  Matrix h(m);
  h = h*indet;
  return Matrix(h);
}

Matrix Matrix::transpose() const {
  Matrix transposed;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      (transposed.m)[i][j] = this->m[j][i];
    }
  }
  return transposed;
}

ostream& operator<<(ostream& lhs, Matrix& m) {
  lhs << "Matrix:" << endl;
  for (int i = 0; i < m.m.size(); i++) {
    lhs << "[";
    for (int j = 0; j < m.m[i].size() - 1; j++) {
      lhs << m.m[i][j] << " ";
    }
    lhs << m.m[i][m.m[i].size()-1] << "]" << endl;
  }
  return lhs;
}

scalar Matrix::operator()(int x, int y) {
  if (x >= 4 or y >= 4 or x < 0 or y < 0) {
    throw std::invalid_argument("Expected x y between 0, 3 (inclusive).");
  }
  return this->m[x][y];
}

void Matrix::maintainHomogeneous() {
  this->m[3][3] = 1;
}

