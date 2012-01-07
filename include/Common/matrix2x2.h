// matrix2x2.h
#ifndef MATRIX2X2_H
#define MATRIX2X2_H
#include "r2error.h"
#include "feq.h"

namespace Rigid2D {

  // Row-Major order implementation of a 2by2 Matrix of floats.
  class Matrix2x2{
    float data_[2][2];
    public:
      // Default constructor.  Used to speed up performance when creating temporary objects.
      Matrix2x2(){};

      Matrix2x2(float m11, float m12, float m21, float m22){
        data_[0][0] = m11;
        data_[0][1] = m12;
        data_[1][0] = m21;
        data_[1][1] = m22;
      }

      // member access/assignment using the construct mat(i,j).
      float & operator () (unsigned int row, unsigned int column);

      // member access/assignment using the construct mat[i][j].
      float * operator [] (unsigned int row);

      // arithmetic operations
      Matrix2x2 operator + (const Matrix2x2& other) const;
      Matrix2x2 operator - (const Matrix2x2& other) const;
      Matrix2x2 operator * (const Matrix2x2& other) const;

      // If fDivisor is non-zero, function returns a new Matrix2x2 object with elements equal to
      // calling object's elements divided by fDivisor.  If fDivisor is zero, function throws an
      // error.
      //Matrix2x2 operator / (const float fDivisor) const;
      // Matrix2x2 operator += (const Matrix2x2& other);
      // Matrix2x2 operator -= (const Matrix2x2& other);
      // Matrix2x2 operator *= (const Matrix2x2& other);
      // Matrix2x2 operator /= (const Matrix2x2& other);

      Matrix2x2 operator = (const Matrix2x2& other);

      bool operator == (const Matrix2x2& other) const;

      void setZeros();

      Matrix2x2 setIdentity();

      // returns the determinant of calling object, in floating-point format.
      inline float det() const{
        return (data_[0][0]*data_[1][1] - data_[0][1]*data_[1][0]);
      }

      // Returns true if the determinant of calling object is greater than maxUlp - 1
      // floats from 0.0f.  Otherwise, hasInverse() returns false.  Note that maxUlp stands for
      // maximum units in the last place.
      bool hasInverse(int maxUlp = 5) const;

      // If calling object has a determinant that is atleast maxUlp floats away from 0.0f, then
      // inv() returns true and assigns to invMatrix the inverse matrix of calling object.  Otherwise,
      // inv() returns false and assigns to invMatrix the 2 by 2 matrix of all zeros.
      bool inv(Matrix2x2& invMatrix, int maxUlp = 5) const;

  }; // end class Matrix2x2.
} // end namespace Rigid2D.

#endif
