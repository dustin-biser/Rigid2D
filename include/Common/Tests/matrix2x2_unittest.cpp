//matrix2x2_unittest.cpp
#include "../matrix2x2.h"
#include "../feq.h"
#include "gtest/gtest.h"
#include <float.h>
#include <cstdio>
using namespace Rigid2D;

TEST(Matrix2x2Test, ConstructorParameterized){
  Matrix2x2 m(1,2,3,4);

  EXPECT_EQ(1.0, m(0,0));
  EXPECT_EQ(2.0, m(0,1));
  EXPECT_EQ(3.0, m(1,0));
  EXPECT_EQ(4.0, m(1,1));
}

TEST(Matrix2x2Test, CosntructorDeepCopy){
  Matrix2x2 a(101, 0.0020, -333.333, 4.0f/5.0f);
  Matrix2x2 b(a);

  for(int i = 0; i<2; i++){
    for(int j=0; j<2; j++){
      printf("a(%d,%d): %1.15f\n",i,j,a(i,j));
      printf("b(%d,%d): %1.15f\n",i,j,b(i,j));
      printf("\n");
    }
  }

  EXPECT_TRUE(feq(a(0,0), b(0,0)));
  EXPECT_TRUE(feq(a(0,1), b(0,1)));
  EXPECT_TRUE(feq(a(1,0), b(1,0)));
  EXPECT_TRUE(feq(a(1,1), b(1,1)));
}

TEST(Matrix2x2Test, SetZeros){
  Matrix2x2 m(1,1,1,1);
  m.setZeros();

  EXPECT_EQ(0.0, m(0,0));
  EXPECT_EQ(0.0, m(0,1));
  EXPECT_EQ(0.0, m(1,0));
  EXPECT_EQ(0.0, m(1,1));
}

TEST(Matrix2x2Test, SetIdentity){
  Matrix2x2 a;
  a.setIdentity();

  EXPECT_TRUE(feq(a(0,0), 1.0f));
  EXPECT_TRUE(feq(a(0,1), 0.0f));
  EXPECT_TRUE(feq(a(1,0), 0.0f));
  EXPECT_TRUE(feq(a(1,1), 1.0f));
}

TEST(Matrix2x2Test, Transpose){
  Matrix2x2 a(1,2,3,4);
  Matrix2x2 c;

  c = a.transpose();

  EXPECT_TRUE(feq(c[0][0], 1.0f));
  EXPECT_TRUE(feq(c[0][1], 3.0f));
  EXPECT_TRUE(feq(c[1][0], 2.0f));
  EXPECT_TRUE(feq(c[1][1], 4.0f));

}
//=== Test Determinant ========================================================
TEST(Matrix2x2Determinant, DeterminantIsNegative){
  Matrix2x2 a(1,2,3,4);

  EXPECT_TRUE(feq(a.det(), -2.0f));
}

TEST(Matrix2x2Determinant, DeterminantIsPositive){
  Matrix2x2 a(1,-1,1,1);

  EXPECT_TRUE(feq(a.det(), 2.0f));
}

TEST(Matrix2x2Determinant, DeterminantIsZero){
  Matrix2x2 a(4,1,4,1);

  EXPECT_TRUE(feq(a.det(), 0.0f));
}

TEST(Matrix2x2Determinant, DeterminantIsSmallPositive){
  Matrix2x2 a(1e-3, 0, 0, 1e-3);


  EXPECT_TRUE(feq(a.det(), 1e-6));
}

TEST(Matrix2x2Determinant, DeterminantIsSmallNegative){
  Matrix2x2 a(-1e-3, 0, 0, 1e-3);


  EXPECT_TRUE(feq(a.det(), -1e-6));
}
// End Test Determinant
//==============================================================================

//=== Test Inverse =============================================================
TEST(Matrix2x2Inverse, HasInverseTrue){
  Matrix2x2 a(1,1,1,2);

  EXPECT_TRUE(a.hasInverse());
}

TEST(Matrix2x2Inverse, HasInverseFalse){
  Matrix2x2 a(1,1,1,1);

  EXPECT_FALSE(a.hasInverse());
}

TEST(Matrix2x2Inverse, ComputeInverseSimple){
  Matrix2x2 a(1,2,2,1);
  Matrix2x2 true_inv(-1.0/3.0, 2.0/3.0, 2.0/3.0, -1.0/3.0);
  Matrix2x2 result;

  EXPECT_TRUE(a.inv(result));
  EXPECT_TRUE(feq(result(0,0), true_inv(0,0)));
  EXPECT_TRUE(feq(result(1,0), true_inv(1,0)));
  EXPECT_TRUE(feq(result(0,1), true_inv(0,1)));
  EXPECT_TRUE(feq(result(1,1), true_inv(1,1)));
}

TEST(Matrix2x2Inverse, ComputeInverseIdentity){
  Matrix2x2 a(1,0,0,1);
  Matrix2x2 true_inv(1,0,0,1);
  Matrix2x2 result;

  EXPECT_TRUE(a.inv(result));
  EXPECT_TRUE(feq(result(0,0), 1.0f));
  EXPECT_TRUE(feq(result(1,0), 0.0f));
  EXPECT_TRUE(feq(result(0,1), 0.0f));
  EXPECT_TRUE(feq(result(1,1), 1.0f));
}

TEST(Matrix2x2Inverse, ComputeInverseSmall){
  Matrix2x2 a(1e-6, 2e-6, 2e-6, 1e-6);
  Matrix2x2 result;

  EXPECT_TRUE(a.inv(result));
  EXPECT_TRUE(feq(result(0,0), -(1.0/3.0)*1e+6));
  EXPECT_TRUE(feq(result(1,0),  (2.0/3.0)*1e+6));
  EXPECT_TRUE(feq(result(0,1),  (2.0/3.0)*1e+6));
  EXPECT_TRUE(feq(result(1,1), -(1.0/3.0)*1e+6));
}
// End Test Inverse
//==============================================================================

//=== Test Matrix2x2 Operators =================================================
TEST(Matrix2x2Operator, ParenthesesElementAssignment){
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

TEST(Matrix2x2Operator, ParenthesesElementAccess){
  Matrix2x2 a(1.0f, 2.0f, 3.0f, 4.0f);

  EXPECT_TRUE(feq(a(0,0), 1.0f));
  EXPECT_TRUE(feq(a(0,1), 2.0f));
  EXPECT_TRUE(feq(a(1,0), 3.0f));
  EXPECT_TRUE(feq(a(1,1), 4.0f));
}

TEST(Matrix2x2Operator, BracketsMemberAccess){
  Matrix2x2 a(1,2,3,4);

  EXPECT_TRUE(feq(a[0][0], 1.0f));
  EXPECT_TRUE(feq(a[0][1], 2.0f));
  EXPECT_TRUE(feq(a[1][0], 3.0f));
  EXPECT_TRUE(feq(a[1][1], 4.0f));
}

TEST(Matrix2x2Operator, BracketsMemberAssignment){
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

TEST(Matrix2x2Operator, MatrixAddition){
  Matrix2x2 a(1,2,3,4);
  Matrix2x2 b(5,6,7,8);

  EXPECT_EQ(6.0, (a+b)(0,0));
  EXPECT_EQ(8.0, (a+b)(0,1));
  EXPECT_EQ(10.0, (a+b)(1,0));
  EXPECT_EQ(12.0, (a+b)(1,1));
}

TEST(Matrix2x2Operator, MatrixAdditionAndAssignment){
  Matrix2x2 a(22,33,44,55);
  Matrix2x2 b(-1,-1,-1,-1);
  Matrix2x2 c;

  c = a + b;

  EXPECT_TRUE(feq(21, c(0,0)));
  EXPECT_TRUE(feq(32, c(0,1)));
  EXPECT_TRUE(feq(43, c(1,0)));
  EXPECT_TRUE(feq(54, c(1,1)));
}

TEST(Matrix2x2Operator, MatrixAdditionWithIdentity){
  Matrix2x2 a;
  Matrix2x2 b(-1, 0, 0, -1);
  Matrix2x2 c;

  c = a.setIdentity() + b;

  EXPECT_TRUE(feq(c(0,0), 0.0f));
  EXPECT_TRUE(feq(c(0,1), 0.0f));
  EXPECT_TRUE(feq(c(1,0), 0.0f));
  EXPECT_TRUE(feq(c(0,1), 0.0f));
}

TEST(Matrix2x2Operator, MatrixToMatrixAssignmentWithInts){
  Matrix2x2 a;
  Matrix2x2 b(-1, 0, 1, 2);

  a = b;

  EXPECT_EQ(-1, a(0,0));
  EXPECT_EQ(0, a(0,1));
  EXPECT_EQ(1, a(1,0));
  EXPECT_EQ(2, a(1,1));
}

TEST(Matrix2x2Operator, MatrixToMatrixAssignmentWithFloats){
  Matrix2x2 a;
  Matrix2x2 b(0x1p+0, 0x1p+1, 0x1.8p+1, 0x1p+2); // b(1,2,3,4) in floating-point hex

  a = b;

  EXPECT_EQ(0x1p+0, a(0,0));
  EXPECT_EQ(0x1p+1, a(0,1));
  EXPECT_EQ(0x1.8p+1, a(1,0));
  EXPECT_EQ(0x1p+2, a(1,1));
}

TEST(Matrix2x2Operator, MatrixToMatrixAssignmentWithFloats2){
  Matrix2x2 a;
  Matrix2x2 b(-123.0, 99999.9, 0.12345, 0.0000001);

  a = b;

  // Compare using float equality function feq.
  EXPECT_TRUE(feq(b(0,0), a(0,0)));
  EXPECT_TRUE(feq(b(0,1), a(0,1)));
  EXPECT_TRUE(feq(b(1,0), a(1,0)));
  EXPECT_TRUE(feq(b(1,1), a(1,1)));
}

TEST(Matrix2x2Operator, MatrixSubtraction1){
  Matrix2x2 a(11,22,33,44);
  Matrix2x2 b(10,20,30,40);
  Matrix2x2 c;

  c = a - b;

  EXPECT_TRUE(feq(1,c(0,0)));
  EXPECT_TRUE(feq(2,c(0,1)));
  EXPECT_TRUE(feq(3,c(1,0)));
  EXPECT_TRUE(feq(4,c(1,1)));
}

TEST(Matrix2x2Operator, MatrixSubtraction2){
  Matrix2x2 a(11,22,33,44);
  Matrix2x2 b(10,20,30,40);
  Matrix2x2 c;

  c = b - a;

  EXPECT_TRUE(feq(-1,c(0,0)));
  EXPECT_TRUE(feq(-2,c(0,1)));
  EXPECT_TRUE(feq(-3,c(1,0)));
  EXPECT_TRUE(feq(-4,c(1,1)));
}

TEST(Matrix2x2Operator, EqualityByAddress){
  Matrix2x2 a;
  Matrix2x2 *ptr;

  ptr = &a;

  EXPECT_TRUE(a == *ptr);
}

TEST(Matrix2x2Operator, EqualityByElements){
  Matrix2x2 a(-10, 99999.9, 0.1234, 0.000001);
  Matrix2x2 b(-10, 99999.9, 0.1234, 0.000001);

  EXPECT_TRUE(a == b);
}

TEST(Matrix2x2Operator, MatrixToMatrixMultiplicationWithIdentity){
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

TEST(Matrix2x2Operator, MatrixToMatrixMultiplication){
  Matrix2x2 a(1, 2, 2, 1);
  Matrix2x2 b(3, 1, 1, 3);
  Matrix2x2 c;

  c = a * b;

  EXPECT_TRUE(feq(c(0,0), 5.0f));
  EXPECT_TRUE(feq(c(0,1), 7.0f));
  EXPECT_TRUE(feq(c(1,0), 7.0f));
  EXPECT_TRUE(feq(c(1,1), 5.0f));

  c.setZeros();

  c = b * a;

  EXPECT_TRUE(feq(c(0,0), 5.0f));
  EXPECT_TRUE(feq(c(0,1), 7.0f));
  EXPECT_TRUE(feq(c(1,0), 7.0f));
  EXPECT_TRUE(feq(c(1,1), 5.0f));
}

// end Test Matrix2x2 Operators
//==============================================================================
