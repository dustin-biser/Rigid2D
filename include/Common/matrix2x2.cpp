// matrix2x2.cpp
#include "matrix2x2.h"
#include "r2error.h"
using namespace Rigid2D;

float & Matrix2x2::operator () (unsigned int row, unsigned int column){
  if ((row < 3) && (column < 3))
    return data_[row][column];
  else
    throw R2Error(MatrixIndexOutOfBoundsError);
}

Matrix2x2 Matrix2x2::operator + (const Matrix2x2 &other) const {
  Matrix2x2 temp;

  temp.data_[0][0] = data_[0][0] + other.data_[0][0];
  temp.data_[0][1] = data_[0][1] + other.data_[0][1];
  temp.data_[1][0] = data_[1][0] + other.data_[1][0];
  temp.data_[1][1] = data_[1][1] + other.data_[1][1];

  return temp;
}

Matrix2x2 Matrix2x2::operator - (const Matrix2x2 &other) const {
  Matrix2x2 temp;

  temp.data_[0][0] = data_[0][0] - other.data_[0][0];
  temp.data_[0][1] = data_[0][1] - other.data_[0][1];
  temp.data_[1][0] = data_[1][0] - other.data_[1][0];
  temp.data_[1][1] = data_[1][1] - other.data_[1][1];

  return temp;
}

Matrix2x2 Matrix2x2::operator = (const Matrix2x2 &other){
  data_[0][0] = other.data_[0][0];
  data_[0][1] = other.data_[0][1];
  data_[1][0] = other.data_[1][0];
  data_[1][1] = other.data_[1][1];

  return *this;
}

/* Returns true if calling object and other have the same memory address or if
 * all corresponding matrix elements are the same.  Otherwise, == returns false.
 */
bool Matrix2x2::operator == (const Matrix2x2 &other) const {
  // Check if addresses are equal
  if (this == &other)
    return true;

  // Check if all matrix elements are equal.
  else if ((data_[0][0] == other.data_[0][0]) &&
           (data_[0][1] == other.data_[0][1]) &&
           (data_[1][0] == other.data_[1][0]) &&
           (data_[1][1] == other.data_[1][1]))
    return true;
  else
    return false;
}

void Matrix2x2::setZeros(){
  data_[0][0] = 0.0f;
  data_[0][1] = 0.0f;
  data_[1][0] = 0.0f;
  data_[1][1] = 0.0f;
}

Matrix2x2 Matrix2x2::operator * (const Matrix2x2 &other) const {
  Matrix2x2 temp;

  temp(0,0) = (data_[0][0] * other.data_[0][0]) + (data_[0][1] * other.data_[1][0]);
  temp(0,1) = (data_[0][0] * other.data_[0][1]) + (data_[0][1] * other.data_[1][1]);
  temp(1,0) = (data_[1][0] * other.data_[0][0]) + (data_[1][1] * other.data_[1][0]);
  temp(1,1) = (data_[1][0] * other.data_[0][1]) + (data_[1][1] * other.data_[1][1]);

  return temp;
}

Matrix2x2 Matrix2x2::setIdentity(){
  data_[0][0] = data_[1][1] = 1.0f;
  data_[0][1] = data_[1][0] = 0.0f;

  return *this;
}

float * Matrix2x2::operator [] (unsigned int row){
  if (row < 3)
    return data_[row];
  else
    throw R2Error(MatrixIndexOutOfBoundsError);
}
