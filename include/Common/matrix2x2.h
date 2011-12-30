// matrix2x2.h
#ifndef MATRIX2X2_H
#define MATRIX2X2_H

// Row-Major order implementation of a 2by2 Matrix of floats.
class Matrix2x2{
  float data[2][2];
  public:
    Matrix2x2(float m11 = 0.0, float m12 = 0.0, float m21 = 0.0, float m22 = 0.0){
      data[0][0] = m11;
      data[0][1] = m12;
      data[1][0] = m21;
      data[1][1] = m22;
    };
    //void set(const unsigned int row, const unsigned int column);

    float operator () (const unsigned int row, const unsigned int column);

    Matrix2x2 operator + (Matrix2x2 other);

    Matrix2x2 operator = (Matrix2x2 other);

};

#endif
