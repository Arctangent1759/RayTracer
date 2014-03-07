#include "Matrix.hpp"
#include "math.h"

Matrix::Matrix() {
  vector< vector<scalar> > m(4, vector<scalar> (4, 0));
}

Matrix::Matrix(Matrix* v) {
  this->m = v->m;
}

Matrix::Matrix(vector< vector<scalar> > m) {
  if (m.size() > 4) {
    throw std::invalid_arguments("Expected horizontal size between 0, 4 (inclusive).");
  }
  for (int i = 0; i < m.size(); i++) {
    if (m[i].size() > 4) {
      throw std::invalid_arguments("Expected vertical size between 0, 4 (inclusive).");
    }
  }
  this->m = m;
  if (this->m.size() < 4) {
    this->m.resize(4, vector<scalar> (4, 0));
  }
  for (int i = 0; i < this->m.size(); i++) {
    if (this->m[i].size() < 4) {
      this->m[i].resize(4, 1);
    }
  }
}

Matrix& operator+(const Matrix& rhs) const {
  if (this->m.size() != (rhs.m).size()) {
    std::invalid_arguments("Horizontal size of argument and matrix must be the same.");
  }
  vector< vector<scalar> > added = new vector< vector<scalar> >(4, vector<scalar> (4, 0));
  for (int i = 0; i < this->m.size(); i++) {
    for (int j = 0; j < this->m[i].size(); j++) {
      if (this->m[i].size() != (rhs.m)[i].size()) {
        std:invalid_arguments("Vertical size of argument and matrix must be the same.");
        (*added)[i][j] = this->m[i][j]+(rhs.m)[i][j];
      }
    }
  }
  return added;
}

Matrix& operator-(const Matrix& rhs) const {
  if (this->m.size() != (rhs.m).size()) {
    std::invalid_arguments("Horizontal size of argument and matrix must be the same.");
  }
  vector< vector<scalar> > subtracted = new vector< vector<scalar> >(4, vector<scalar> (4, 0));
  for (int i = 0; i < this->m.size(); i++) {
    for (int j = 0; j < this->m[i].size(); j++) {
      if (this->m[i].size() != (rhs.m)[i].size()) {
        std:invalid_arguments("Vertical size of argument and matrix must be the same.");
        (*subtracted)[i][j] = this->m[i][j]-(rhs.m)[i][j];
      }
    }
  }
  return subtracted;
}

Matrix& operator*(const Matrix& rhs) const {
}

Matrix& inverse(const Matrix& rhs) const {
}

scalar operator()(int x, int y) {
  if (x >= 4 or y >= 4 or x < 0 or y < 0) {
    throw std::invalid_arguments("Expected x y between 0, 3 (inclusive).");
  }
  return this->m[x][y]
}

