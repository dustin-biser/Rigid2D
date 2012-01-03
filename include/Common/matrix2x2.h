// matrix2x2.h
#ifndef MATRIX2X2_H
#define MATRIX2X2_H

namespace Rigid2D {

  // Row-Major order implementation of a 2by2 Matrix of floats.
  class Matrix2x2{
    float data_[2][2];
    public:
      // Default constructor that does nothing for performance.
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
      Matrix2x2 operator + (const Matrix2x2 & other) const;
      Matrix2x2 operator - (const Matrix2x2 & other) const;
      Matrix2x2 operator * (const Matrix2x2 & other) const;

      Matrix2x2 operator = (const Matrix2x2 & other);

      bool operator == (const Matrix2x2 & other) const;

      void setZeros();

      Matrix2x2 setIdentity();

      // returns the determinant of matrix.
      inline float det() const{
        return (data_[0][0]*data_[1][1] - data_[0][1]*data_[1][0]);
      }
  }; // end class Matrix2x2.

} // end namespace Rigid2D.

#endif

