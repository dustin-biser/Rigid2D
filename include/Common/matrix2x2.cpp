// matrix2x2.cpp
#include "matrix2x2.h"

namespace Rigid2D {

  float & Matrix2x2::operator () (unsigned int row, unsigned int column){
    if ((row < 3) && (column < 3))
      return data_[row][column];
    else
      throw R2Error(MatrixIndexOutOfBoundsError);
  }

  Matrix2x2 Matrix2x2::operator + (const Matrix2x2 &other) const {
    Matrix2x2 result;

    result.data_[0][0] = data_[0][0] + other.data_[0][0];
    result.data_[0][1] = data_[0][1] + other.data_[0][1];
    result.data_[1][0] = data_[1][0] + other.data_[1][0];
    result.data_[1][1] = data_[1][1] + other.data_[1][1];

    return result;
  }

  Matrix2x2 Matrix2x2::operator - (const Matrix2x2 &other) const {
    Matrix2x2 result;

    result.data_[0][0] = data_[0][0] - other.data_[0][0];
    result.data_[0][1] = data_[0][1] - other.data_[0][1];
    result.data_[1][0] = data_[1][0] - other.data_[1][0];
    result.data_[1][1] = data_[1][1] - other.data_[1][1];

    return result;
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
    else if ((feq(data_[0][0],other.data_[0][0])) &&
             (feq(data_[0][1],other.data_[0][1])) &&
             (feq(data_[1][0],other.data_[1][0])) &&
             (feq(data_[1][1],other.data_[1][1])))
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
    Matrix2x2 result;

    result(0,0) = (data_[0][0] * other.data_[0][0]) + (data_[0][1] * other.data_[1][0]);
    result(0,1) = (data_[0][0] * other.data_[0][1]) + (data_[0][1] * other.data_[1][1]);
    result(1,0) = (data_[1][0] * other.data_[0][0]) + (data_[1][1] * other.data_[1][0]);
    result(1,1) = (data_[1][0] * other.data_[0][1]) + (data_[1][1] * other.data_[1][1]);

    return result;
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

  bool Matrix2x2::hasInverse(int maxUlp) const{
    if (feq(this->det(), 0.0f, maxUlp))
      return false;
    else
      return true;
  }

  bool Matrix2x2::inv(Matrix2x2& invMatrix, int maxUlp) const{
    if (hasInverse(maxUlp) == false){
      invMatrix.setZeros();
      return false;
    }

    float det = this->det();

    invMatrix.data_[0][0] =  data_[1][1] / det;
    invMatrix.data_[0][1] = -data_[0][1] / det;
    invMatrix.data_[1][0] = -data_[1][0] / det;
    invMatrix.data_[1][1] =  data_[0][0] / det;

    return true;
  }
  
  //Matrix2x2 operator / (const float fDivisor) const {
    //Matrix2x2 result;
    
    //result.data_[0][0] = data_[0][0] / fDivisor;

  //}

} // end namespace Rigid2D.
