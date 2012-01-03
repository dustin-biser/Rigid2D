//matrix2x2_unittest.cpp
#include "../matrix2x2.h"
#include "../feq.h"
#include "../r2error.h"
#include "gtest/gtest.h"
#include <float.h>
using namespace Rigid2D;

TEST(Matrix2x2Test, SetZeros){
  Matrix2x2 m;
  m.setZeros();

  EXPECT_EQ(0.0, m(0,0));
  EXPECT_EQ(0.0, m(0,1));
  EXPECT_EQ(0.0, m(1,0));
  EXPECT_EQ(0.0, m(1,1));
}

TEST(Matrix2x2Test, ParameterizedConstruction){
  Matrix2x2 m(1,2,3,4);

  EXPECT_EQ(1.0, m(0,0));
  EXPECT_EQ(2.0, m(0,1));
  EXPECT_EQ(3.0, m(1,0));
  EXPECT_EQ(4.0, m(1,1));
}

TEST(Matrix2x2Test, Addition){
  Matrix2x2 a(1,2,3,4);
  Matrix2x2 b(5,6,7,8);

  EXPECT_EQ(6.0, (a+b)(0,0));
  EXPECT_EQ(8.0, (a+b)(0,1));
  EXPECT_EQ(10.0, (a+b)(1,0));
  EXPECT_EQ(12.0, (a+b)(1,1));
}

TEST(Matrix2x2Test, ElementAssignment){
  Matrix2x2 a;
  
  a(0,0) = 1.0f;
  a(0,1) = 2.0f;
  a(1,0) = 3.0f;
  a(1,1) = 4.0f;

  EXPECT_TRUE(feq(a(0,0), 1.0f));
  EXPECT_TRUE(feq(a(0,1), 2.0f));
  EXPECT_TRUE(feq(a(1,0), 3.0f));
  EXPECT_TRUE(feq(a(1,1), 4.0f));
}

TEST(Matrix2x2Test, MatrixToMatrixAssignmentWithInts){
  Matrix2x2 a;
  Matrix2x2 b(-1, 0, 1, 2);

  a = b;

  EXPECT_EQ(-1, a(0,0));
  EXPECT_EQ(0, a(0,1));
  EXPECT_EQ(1, a(1,0));
  EXPECT_EQ(2, a(1,1));
}

TEST(Matrix2x2Test, MatrixToMatrixAssignmentWithFloats){
  Matrix2x2 a;
  Matrix2x2 b(0x1p+0, 0x1p+1, 0x1.8p+1, 0x1p+2); // b(1,2,3,4) in floating-point hex

  a = b;

  EXPECT_EQ(0x1p+0, a(0,0));
  EXPECT_EQ(0x1p+1, a(0,1));
  EXPECT_EQ(0x1.8p+1, a(1,0));
  EXPECT_EQ(0x1p+2, a(1,1));
}

TEST(Matrix2x2Test, MatrixToMatrixAssignmentWithFloats2){
  Matrix2x2 a;
  Matrix2x2 b(-123.0, 99999.9, 0.12345, 0.0000001);

  a = b;

  // Compare using float equality function feq.
  EXPECT_TRUE(feq(b(0,0), a(0,0)));
  EXPECT_TRUE(feq(b(0,1), a(0,1)));
  EXPECT_TRUE(feq(b(1,0), a(1,0)));
  EXPECT_TRUE(feq(b(1,1), a(1,1)));
}

TEST(Matrix2x2Test, AdditionAndAssignment1){
  Matrix2x2 a(22,33,44,55);
  Matrix2x2 b(-1,-1,-1,-1);
  Matrix2x2 c;

  c = a + b;

  EXPECT_TRUE(feq(21, c(0,0)));
  EXPECT_TRUE(feq(32, c(0,1)));
  EXPECT_TRUE(feq(43, c(1,0)));
  EXPECT_TRUE(feq(54, c(1,1)));
}

TEST(Matrix2x2Test, ThrowsR2ErrorWhenOutOfBounds){
  Matrix2x2 a;
  a.setZeros();

  EXPECT_THROW(a(3,2), R2Error);
  EXPECT_THROW(a(2,3), R2Error);
  EXPECT_THROW(a(3,3), R2Error);
}

TEST(Matrix2x2Test, ThrowsMatrixIndexOutOfBoundsError){
  Matrix2x2 a;
  try{
    a.setZeros();
    a(3,3);
  }
  catch(R2Error e){
    EXPECT_EQ(e.type(), MatrixIndexOutOfBoundsError);
  }
  catch(...){
    EXPECT_TRUE(false);
  }
}

TEST(Matrix2x2Test, MatrixSubtraction1){
  Matrix2x2 a(11,22,33,44);
  Matrix2x2 b(10,20,30,40);
  Matrix2x2 c;

  c = a - b;

  EXPECT_TRUE(feq(1,c(0,0)));
  EXPECT_TRUE(feq(2,c(0,1)));
  EXPECT_TRUE(feq(3,c(1,0)));
  EXPECT_TRUE(feq(4,c(1,1)));
}

TEST(Matrix2x2Test, MatrixSubtraction2){
  Matrix2x2 a(11,22,33,44);
  Matrix2x2 b(10,20,30,40);
  Matrix2x2 c;

  c = b - a;

  EXPECT_TRUE(feq(-1,c(0,0)));
  EXPECT_TRUE(feq(-2,c(0,1)));
  EXPECT_TRUE(feq(-3,c(1,0)));
  EXPECT_TRUE(feq(-4,c(1,1)));
}

TEST(Matrix2x2Test, SetIdentity){
  Matrix2x2 a;
  a.setIdentity();

  EXPECT_TRUE(feq(a(0,0), 1.0f));
  EXPECT_TRUE(feq(a(0,1), 0.0f));
  EXPECT_TRUE(feq(a(1,0), 0.0f));
  EXPECT_TRUE(feq(a(1,1), 1.0f));
}

TEST(Matrix2x2Test, SetIdentityWithAddition){
  Matrix2x2 a;
  Matrix2x2 b(-1, 0, 0, -1);
  Matrix2x2 c;

  c = a.setIdentity() + b;

  EXPECT_TRUE(feq(c(0,0), 0.0f));
  EXPECT_TRUE(feq(c(0,1), 0.0f));
  EXPECT_TRUE(feq(c(1,0), 0.0f));
  EXPECT_TRUE(feq(c(0,1), 0.0f));
}

TEST(Matrix2x2Test, EqualityByAddress){
  Matrix2x2 a;
  Matrix2x2 *ptr;

  ptr = &a;

  EXPECT_TRUE(a == *ptr);
}

TEST(Matrix2x2Test, EqualityByElements){
  Matrix2x2 a(-10, 99999.9, 0.1234, 0.000001);
  Matrix2x2 b(-10, 99999.9, 0.1234, 0.000001);

  EXPECT_TRUE(a == b);
}

TEST(Matrix2x2Test, MatrixMultiplicationWithIdentity){
  Matrix2x2 I;
  Matrix2x2 b(1,-2,-3,4);
  Matrix2x2 c;

  I.setIdentity();

  c = I * b;

  EXPECT_EQ(c,b);

  c.setZeros();

  c = b * I;

  EXPECT_EQ(c,b);
}

TEST(Matrix2x2Test, MemberAccessUsingBrackets){
  Matrix2x2 a(1,2,3,4);

  EXPECT_TRUE(feq(a[0][0], 1));
  EXPECT_TRUE(feq(a[0][1], 2));
  EXPECT_TRUE(feq(a[1][0], 3));
  EXPECT_TRUE(feq(a[1][1], 4));
}

TEST(Matrix2x2Test, MemberAssignmentUsingBrackets){
  Matrix2x2 a;

  a[0][0] = 1.0f;
  a[0][1] = 2.0f;
  a[1][0] = 3.0f;
  a[1][1] = 4.0f;

  EXPECT_TRUE(feq(a[0][0], 1.0f));
  EXPECT_TRUE(feq(a[0][1], 2.0f));
  EXPECT_TRUE(feq(a[1][0], 3.0f));
  EXPECT_TRUE(feq(a[1][1], 4.0f));
}
