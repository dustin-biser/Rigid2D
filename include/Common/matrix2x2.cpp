// matrix2x2.cpp
#include "matrix2x2.h"
#include "r2error.h"
using namespace Rigid2D;

float & Matrix2x2::operator () (const unsigned int row, const unsigned int column){
  if ((row < 3) && (column < 3))
    return data[row][column];
  else
    throw R2Error(MatrixIndexOutOfBoundsError);
}

Matrix2x2 Matrix2x2::operator + (Matrix2x2 other){
  Matrix2x2 temp;
  for(int row = 0; row < 2; row++){
    for(int col = 0; col < 2; col++){
      temp.data[row][col] = this->data[row][col] + other.data[row][col];
    }
  }
  return temp;
}

Matrix2x2 Matrix2x2::operator - (Matrix2x2 other){
  Matrix2x2 temp;
  for(int row = 0; row < 2; row++){
    for(int col = 0; col < 2; col++){
      temp.data[row][col] = this->data[row][col] - other.data[row][col];
    }
  }
  return temp;
}

Matrix2x2 Matrix2x2::operator = (Matrix2x2 other){
  for(int row = 0; row < 2; row ++){
    for(int col = 0; col < 2; col ++){
      this->data[row][col] = other.data[row][col];
    }
  }
  return *this;
}

void Matrix2x2::setZeros(){
  for(int row = 0; row < 2; row ++){
    for(int col = 0; col < 2; col ++){
      data[row][col] = 0.0f;
    }
  }
}

Matrix2x2 Matrix2x2::operator * (Matrix2x2 other){
  Matrix2x2 temp;

  temp(0,0) = (data[0][0] * other(0,0)) + (data[0][1] * other(1,0));
  temp(0,1) = (data[0][0] * other(0,1)) + (data[0][1] * other(1,1));
  temp(1,0) = (data[1][0] * other(0,0)) + (data[1][1] * other(1,0));
  temp(1,1) = (data[1][0] * other(0,1)) + (data[1][1] * other(1,1));

  return temp;
}

Matrix2x2 Matrix2x2::setIdentity(){
  data[0][0] = data[1][1] = 1;
  data[0][1] = data[1][0] = 0;
  return *this;
}


