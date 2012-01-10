// matrix2x2.h
#ifndef MATRIX2X2_H
#define MATRIX2X2_H
#include "RigidSettings.h"
#include "feq.h"

namespace Rigid2D {

  // Row-Major order implementation of a 2by2 Matrix of floating-point values.
  class Matrix2x2{
    Real data_[2][2];
    public:
      // Default constructor.  Used to speed up performance when creating temporary objects.
      Matrix2x2(){};

      Matrix2x2(Real m11, Real m12, Real m21, Real m22){
        data_[0][0] = m11;
        data_[0][1] = m12;
        data_[1][0] = m21;
        data_[1][1] = m22;
      }

      // Perform deep copy of other.
      Matrix2x2(Matrix2x2& other);

      // member access/assignment using the construct mat(i,j).
      Real & operator () (unsigned int row, unsigned int column);

      // member access/assignment using the construct mat[i][j].
      Real * operator [] (unsigned int row);

      // arithmetic operations
      Matrix2x2 operator + (const Matrix2x2& other) const;
      Matrix2x2 operator - (const Matrix2x2& other) const;
      Matrix2x2 operator * (const Matrix2x2& other) const;

			// Returns a Matrix2x2 object representing the state of calling object whos
			// elements are all multiplied by value.
			Matrix2x2 operator * (Real value) const;

      Matrix2x2 operator = (const Matrix2x2& other);

      bool operator == (const Matrix2x2& other) const;

      void setZeros();

      Matrix2x2 setIdentity();

      // returns the determinant of calling object, in floating-point format.
      Real det() const{
        return (data_[0][0]*data_[1][1] - data_[0][1]*data_[1][0]);
      }

      // Returns true if the determinant of calling object is greater than
			// maxUlp - 1 floating-point values from 0.0f.  Otherwise, hasInverse()
			// returns false.  Note that maxUlp stands for maximum units in the last place.
      bool hasInverse(int maxUlp = 5) const;

      // If calling object has a determinant that is at least maxUlp
			// floating-point values away from 0.0f, then inv() returns true and
			// assigns to invMatrix the inverse matrix of calling object.  Otherwise,
      // inv() returns false and assigns to invMatrix the 2 by 2 matrix of all zeros.
      bool inv(Matrix2x2& invMatrix, int maxUlp = 5) const;

      // Returns a Matrix2x2 object representing the transpose of calling object.
      Matrix2x2 transpose() const;

  }; // end class Matrix2x2.
} // end namespace Rigid2D.

#endif
