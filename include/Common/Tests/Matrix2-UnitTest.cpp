#include "../Matrix2.h"
#include "../feq.h"
#include "gtest/gtest.h"
#include <float.h>
using namespace Rigid2D;

TEST(Matrix2Test, ConstructorParameterized){
  Matrix2 m(1,2,3,4);

  EXPECT_EQ(1.0, m(0,0));
  EXPECT_EQ(2.0, m(0,1));
  EXPECT_EQ(3.0, m(1,0));
  EXPECT_EQ(4.0, m(1,1));
}

TEST(Matrix2Test, CosntructorDeepCopy){
  Matrix2 a(101, 0.0020, -333.333, 4.0f/5.0f);
  Matrix2 b(a);

  EXPECT_TRUE(feq(a(0,0), b(0,0)));
  EXPECT_TRUE(feq(a(0,1), b(0,1)));
  EXPECT_TRUE(feq(a(1,0), b(1,0)));
  EXPECT_TRUE(feq(a(1,1), b(1,1)));
}

TEST(Matrix2Test, SetZeros){
  Matrix2 m(1,1,1,1);
  m.setZeros();

  EXPECT_EQ(0.0, m(0,0));
  EXPECT_EQ(0.0, m(0,1));
  EXPECT_EQ(0.0, m(1,0));
  EXPECT_EQ(0.0, m(1,1));
}

TEST(Matrix2Test, SetIdentity){
  Matrix2 a;
  a.setIdentity();

  EXPECT_TRUE(feq(a(0,0), 1.0f));
  EXPECT_TRUE(feq(a(0,1), 0.0f));
  EXPECT_TRUE(feq(a(1,0), 0.0f));
  EXPECT_TRUE(feq(a(1,1), 1.0f));
}

TEST(Matrix2Test, Transpose){
  Matrix2 a(1,2,3,4);
  Matrix2 c;

  c = a.transpose();

  EXPECT_TRUE(feq(c[0][0], 1.0f));
  EXPECT_TRUE(feq(c[0][1], 3.0f));
  EXPECT_TRUE(feq(c[1][0], 2.0f));
  EXPECT_TRUE(feq(c[1][1], 4.0f));

}
//=== Test Determinant ========================================================
TEST(Matrix2Determinant, DeterminantIsNegative){
  Matrix2 a(1,2,3,4);

  EXPECT_TRUE(feq(a.det(), -2.0f));
}

TEST(Matrix2Determinant, DeterminantIsPositive){
  Matrix2 a(1,-1,1,1);

  EXPECT_TRUE(feq(a.det(), 2.0f));
}

TEST(Matrix2Determinant, DeterminantIsZero){
  Matrix2 a(4,1,4,1);

  EXPECT_TRUE(feq(a.det(), 0.0f));
}

TEST(Matrix2Determinant, DeterminantIsSmallPositive){
  Matrix2 a(1e-3, 0, 0, 1e-3);


  EXPECT_TRUE(feq(a.det(), 1e-6));
}

TEST(Matrix2Determinant, DeterminantIsSmallNegative){
  Matrix2 a(-1e-3, 0, 0, 1e-3);


  EXPECT_TRUE(feq(a.det(), -1e-6));
}
// End Test Determinant
//==============================================================================

//=== Test Inverse =============================================================
TEST(Matrix2Inverse, HasInverseTrue){
  Matrix2 a(1,1,1,2);

  EXPECT_TRUE(a.hasInverse());
}

TEST(Matrix2Inverse, HasInverseFalse){
  Matrix2 a(1,1,1,1);

  EXPECT_FALSE(a.hasInverse());
}

TEST(Matrix2Inverse, ComputeInverseSimple){
  Matrix2 a(1,2,2,1);
  Matrix2 true_inv(-1.0/3.0, 2.0/3.0, 2.0/3.0, -1.0/3.0);
  Matrix2 result;

  EXPECT_TRUE(a.inv(result));
  EXPECT_TRUE(feq(result(0,0), true_inv(0,0)));
  EXPECT_TRUE(feq(result(1,0), true_inv(1,0)));
  EXPECT_TRUE(feq(result(0,1), true_inv(0,1)));
  EXPECT_TRUE(feq(result(1,1), true_inv(1,1)));
}

TEST(Matrix2Inverse, ComputeInverseIdentity){
  Matrix2 a(1,0,0,1);
  Matrix2 true_inv(1,0,0,1);
  Matrix2 result;

  EXPECT_TRUE(a.inv(result));
  EXPECT_TRUE(feq(result(0,0), 1.0f));
  EXPECT_TRUE(feq(result(1,0), 0.0f));
  EXPECT_TRUE(feq(result(0,1), 0.0f));
  EXPECT_TRUE(feq(result(1,1), 1.0f));
}

TEST(Matrix2Inverse, ComputeInverseSmall){
  Matrix2 a(1e-6, 2e-6, 2e-6, 1e-6);
  Matrix2 result;

  EXPECT_TRUE(a.inv(result));
  EXPECT_TRUE(feq(result(0,0), -(1.0/3.0)*1e+6));
  EXPECT_TRUE(feq(result(1,0),  (2.0/3.0)*1e+6));
  EXPECT_TRUE(feq(result(0,1),  (2.0/3.0)*1e+6));
  EXPECT_TRUE(feq(result(1,1), -(1.0/3.0)*1e+6));
}
// End Test Inverse
//==============================================================================

//=== Test Matrix2 Operators =================================================
TEST(Matrix2Operator, ParenthesesElementAssignment){
  Matrix2 a;
  
  a(0,0) = 1.0f;
  a(0,1) = 2.0f;
  a(1,0) = 3.0f;
  a(1,1) = 4.0f;

  EXPECT_TRUE(feq(a(0,0), 1.0f));
  EXPECT_TRUE(feq(a(0,1), 2.0f));
  EXPECT_TRUE(feq(a(1,0), 3.0f));
  EXPECT_TRUE(feq(a(1,1), 4.0f));
}

TEST(Matrix2Operator, ParenthesesElementAccess){
  Matrix2 a(1.0f, 2.0f, 3.0f, 4.0f);

  EXPECT_TRUE(feq(a(0,0), 1.0f));
  EXPECT_TRUE(feq(a(0,1), 2.0f));
  EXPECT_TRUE(feq(a(1,0), 3.0f));
  EXPECT_TRUE(feq(a(1,1), 4.0f));
}

TEST(Matrix2Operator, BracketsMemberAccess){
  Matrix2 a(1,2,3,4);

  EXPECT_TRUE(feq(a[0][0], 1.0f));
  EXPECT_TRUE(feq(a[0][1], 2.0f));
  EXPECT_TRUE(feq(a[1][0], 3.0f));
  EXPECT_TRUE(feq(a[1][1], 4.0f));
}

TEST(Matrix2Operator, BracketsMemberAssignment){
  Matrix2 a;

  a[0][0] = 1.0f;
  a[0][1] = 2.0f;
  a[1][0] = 3.0f;
  a[1][1] = 4.0f;

  EXPECT_TRUE(feq(a[0][0], 1.0f));
  EXPECT_TRUE(feq(a[0][1], 2.0f));
  EXPECT_TRUE(feq(a[1][0], 3.0f));
  EXPECT_TRUE(feq(a[1][1], 4.0f));
}

TEST(Matrix2Operator, MatrixAddition){
  Matrix2 a(1,2,3,4);
  Matrix2 b(5,6,7,8);

  EXPECT_EQ(6.0, (a+b)(0,0));
  EXPECT_EQ(8.0, (a+b)(0,1));
  EXPECT_EQ(10.0, (a+b)(1,0));
  EXPECT_EQ(12.0, (a+b)(1,1));
}

TEST(Matrix2Operator, MatrixAdditionAndAssignment){
  Matrix2 a(22,33,44,55);
  Matrix2 b(-1,-1,-1,-1);
  Matrix2 c;

  c = a + b;

  EXPECT_TRUE(feq(21, c(0,0)));
  EXPECT_TRUE(feq(32, c(0,1)));
  EXPECT_TRUE(feq(43, c(1,0)));
  EXPECT_TRUE(feq(54, c(1,1)));
}

TEST(Matrix2Operator, MatrixAdditionWithIdentity){
  Matrix2 a;
  Matrix2 b(-1, 0, 0, -1);
  Matrix2 c;

  c = a.setIdentity() + b;

  EXPECT_TRUE(feq(c(0,0), 0.0f));
  EXPECT_TRUE(feq(c(0,1), 0.0f));
  EXPECT_TRUE(feq(c(1,0), 0.0f));
  EXPECT_TRUE(feq(c(0,1), 0.0f));
}

TEST(Matrix2Operator, MatrixToMatrixAssignmentWithInts){
  Matrix2 a;
  Matrix2 b(-1, 0, 1, 2);

  a = b;

  EXPECT_EQ(-1, a(0,0));
  EXPECT_EQ(0, a(0,1));
  EXPECT_EQ(1, a(1,0));
  EXPECT_EQ(2, a(1,1));
}

TEST(Matrix2Operator, MatrixToMatrixAssignmentWithFloats){
  Matrix2 a;
  Matrix2 b(0x1p+0, 0x1p+1, 0x1.8p+1, 0x1p+2); // b(1,2,3,4) in floating-point hex

  a = b;

  EXPECT_EQ(0x1p+0, a(0,0));
  EXPECT_EQ(0x1p+1, a(0,1));
  EXPECT_EQ(0x1.8p+1, a(1,0));
  EXPECT_EQ(0x1p+2, a(1,1));
}

TEST(Matrix2Operator, MatrixToMatrixAssignmentWithFloats2){
  Matrix2 a;
  Matrix2 b(-123.0, 99999.9, 0.12345, 0.0000001);

  a = b;

  // Compare using float equality function feq.
  EXPECT_TRUE(feq(b(0,0), a(0,0)));
  EXPECT_TRUE(feq(b(0,1), a(0,1)));
  EXPECT_TRUE(feq(b(1,0), a(1,0)));
  EXPECT_TRUE(feq(b(1,1), a(1,1)));
}

TEST(Matrix2Operator, MatrixSubtraction1){
  Matrix2 a(11,22,33,44);
  Matrix2 b(10,20,30,40);
  Matrix2 c;

  c = a - b;

  EXPECT_TRUE(feq(1,c(0,0)));
  EXPECT_TRUE(feq(2,c(0,1)));
  EXPECT_TRUE(feq(3,c(1,0)));
  EXPECT_TRUE(feq(4,c(1,1)));
}

TEST(Matrix2Operator, MatrixSubtraction2){
  Matrix2 a(11,22,33,44);
  Matrix2 b(10,20,30,40);
  Matrix2 c;

  c = b - a;

  EXPECT_TRUE(feq(-1,c(0,0)));
  EXPECT_TRUE(feq(-2,c(0,1)));
  EXPECT_TRUE(feq(-3,c(1,0)));
  EXPECT_TRUE(feq(-4,c(1,1)));
}

TEST(Matrix2Operator, EqualityByAddress){
  Matrix2 a;
  Matrix2 *ptr;

  ptr = &a;

  EXPECT_TRUE(a == *ptr);
}

TEST(Matrix2Operator, EqualityByElements){
  Matrix2 a(-10, 99999.9, 0.1234, 0.000001);
  Matrix2 b(-10, 99999.9, 0.1234, 0.000001);

  EXPECT_TRUE(a == b);
}

TEST(Matrix2Operator, MatrixToMatrixMultiplicationWithIdentity){
  Matrix2 I;
  Matrix2 b(1,-2,-3,4);
  Matrix2 c;

  I.setIdentity();

  c = I * b;

  EXPECT_EQ(c,b);

  c.setZeros();

  c = b * I;

  EXPECT_EQ(c,b);
}

TEST(Matrix2Operator, MatrixToMatrixMultiplication){
  Matrix2 a(1, 2, 2, 1);
  Matrix2 b(3, 1, 1, 3);
  Matrix2 c;

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

TEST(Matrix2Operator, MatrixToRealMultiplication){
	Matrix2 a(-1,2,3,-4);
	Matrix2 b;

	b = a * 2.0f;

	EXPECT_TRUE(feq(b(0,0), -2.0f));
	EXPECT_TRUE(feq(b(0,1),  4.0f));
	EXPECT_TRUE(feq(b(1,0),  6.0f));
	EXPECT_TRUE(feq(b(1,1), -8.0f));
}

TEST(Matrix2Operator, RealToMatrixMultiplication){
	Matrix2 a(-1,2,3,-4);
	Matrix2 b;

	b =  2.0f * a;

	EXPECT_TRUE(feq(b(0,0), -2.0f));
	EXPECT_TRUE(feq(b(0,1),  4.0f));
	EXPECT_TRUE(feq(b(1,0),  6.0f));
	EXPECT_TRUE(feq(b(1,1), -8.0f));
}

// end Test Matrix2 Operators
//==============================================================================
