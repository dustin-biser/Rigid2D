// matrix2x2.h
#ifndef MATRIX2X2_H
#define MATRIX2X2_H

namespace Rigid2D {

  // Row-Major order implementation of a 2by2 Matrix of floats.
  class Matrix2x2{
    float data[2][2];
    public:

      // Default constructor that does nothing for performance.
      Matrix2x2(){};

      Matrix2x2(float m11, float m12, float m21, float m22){
        data[0][0] = m11;
        data[0][1] = m12;
        data[1][0] = m21;
        data[1][1] = m22;
      }

      float & operator () (const unsigned int row, const unsigned int column);

      Matrix2x2 operator + (Matrix2x2 other);

      Matrix2x2 operator - (Matrix2x2 other);

      Matrix2x2 operator = (Matrix2x2 other);

      //bool operator == (Matrix2x2 other);

      Matrix2x2 operator * (Matrix2x2 other);

      void setZeros();

      Matrix2x2 setIdentity();
  };
}

#endif
