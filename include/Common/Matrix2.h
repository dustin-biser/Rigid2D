#ifndef RIGID_MATRIX2_H
#define RIGID_MATRIX2_H
#include "RigidSettings.h"
#include "feq.h"

namespace Rigid2D {

  // Row-Major order implementation of a 2by2 Matrix of floating-point values.
  class Matrix2{
    Real data_[2][2];
    public:
      // Default constructor.  Used to speed up performance when creating temporary objects.
      Matrix2(){};

      Matrix2(Real m11, Real m12, Real m21, Real m22){
        data_[0][0] = m11;
        data_[0][1] = m12;
        data_[1][0] = m21;
        data_[1][1] = m22;
      }

      // Perform deep copy of other.
      Matrix2(Matrix2& other);

      // member access/assignment using the construct mat(i,j).
      Real & operator () (unsigned int row, unsigned int column);

      // member access/assignment using the construct mat[i][j].
      Real * operator [] (unsigned int row);

      // arithmetic operations with matrices
      Matrix2 operator + (const Matrix2& other) const;
      Matrix2 operator - (const Matrix2& other) const;
      Matrix2 operator * (const Matrix2& other) const;

      // arithmetic operations with scalars
			friend Matrix2 operator * (Real leftOperand, Matrix2& rightOperand);
      friend Matrix2 operator * (Matrix2& leftOperand, Real rightOperand);

      Matrix2 operator = (const Matrix2& other);

      bool operator == (const Matrix2& other) const;

			// Set all elements of calling object to zero.
      void setZeros();

			// Modify calling object, making it a 2 by 2 identity matrix and returning a copy.
      Matrix2 setIdentity();

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
      bool inv(Matrix2& invMatrix, int maxUlp = 5) const;

      // Returns a Matrix2 object representing the transpose of calling object.
      Matrix2 transpose() const;

  }; // end class Matrix2.
} // end namespace Rigid2D.

#endif
