// matrix2x2.cpp
#include "matrix2x2.h"

float Matrix2x2::operator () (const unsigned int row, const unsigned int column){
  if ((row < 3) && (column < 3))
    return data[row][column];
  else
    throw ("MatrixIndexOutOfBoundsError");
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

Matrix2x2 Matrix2x2::operator = (Matrix2x2 other){
  for(int row = 0; row < 2; row ++){
    for(int col = 0; col < 2; col ++){
      this->data[row][col] = other.data[row][col];
    }
  }
  return *this;
}

