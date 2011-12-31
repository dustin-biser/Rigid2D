//matrix2x2_unittest.cpp
#include "../matrix2x2.h"
#include "../feq.h"
#include "gtest/gtest.h"
#include <float.h>

TEST(Matrix2x2Test, DefaultConstructin){
  Matrix2x2 m;

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

TEST(Matrix2x2Test, AssignmentWithInts){
  Matrix2x2 a;
  Matrix2x2 b(-1, 0, 1, 2);

  a = b;

  EXPECT_EQ(-1, a(0,0));
  EXPECT_EQ(0, a(0,1));
  EXPECT_EQ(1, a(1,0));
  EXPECT_EQ(2, a(1,1));
}

TEST(Matrix2x2Test, AssignmentWithFloats){
  Matrix2x2 a;
  Matrix2x2 b(0x1p+0, 0x1p+1, 0x1.8p+1, 0x1p+2); // b(1,2,3,4) in floating-point hex

  a = b;

  EXPECT_EQ(0x1p+0, a(0,0));
  EXPECT_EQ(0x1p+1, a(0,1));
  EXPECT_EQ(0x1.8p+1, a(1,0));
  EXPECT_EQ(0x1p+2, a(1,1));
}

TEST(Matrix2x2Test, AssignmentWithFloats2){
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
