#include "../Vector2.h"
#include "../feq.h"
#include "gtest/gtest.h"
#include <stdio.h>

using namespace Rigid2D;

TEST(Vector2Test, ConstructorXYZ){
  Vector2 v(1,2);

  EXPECT_FLOAT_EQ(1.0, v.x);
  EXPECT_FLOAT_EQ(2.0, v.y);
}

TEST(Vector2Test, ConstructorArr2){
  float arr[] = {1,2};
  Vector2 v(arr);

  EXPECT_FLOAT_EQ(1.0, v.x);
  EXPECT_FLOAT_EQ(2.0, v.y);
}

TEST(Vector2OperationTest, DeepCopy){
  Vector2 v1(1,2);
  Vector2 v2 = v1;

  EXPECT_FLOAT_EQ(v2.x, v1.x);
  EXPECT_FLOAT_EQ(v2.y, v1.y);
	EXPECT_FALSE(&v1 == &v2);
}

TEST(Vector2OperationTest, Add){
  Vector2 v1(1.0, 2.0);
  Vector2 v2(5.0, 6.0);
  Vector2 v3 = v1 + v2;

  EXPECT_FLOAT_EQ(6.0, v3.x);
  EXPECT_FLOAT_EQ(8.0, v3.y);

  v3 = v2 + v1;

  EXPECT_FLOAT_EQ(6.0, v3.x);
  EXPECT_FLOAT_EQ(8.0, v3.y);
}

TEST(Vector2OperationTest, Subtract){
  Vector2 v1(1.0, 2.0);
  Vector2 v2(5.0, 6.0);
  Vector2 v3 = v2 - v1;

  EXPECT_FLOAT_EQ(4.0, v3.x);
  EXPECT_FLOAT_EQ(4.0, v3.y);

  v3 = v2 - v1;

  EXPECT_FLOAT_EQ(4.0, v3.x);
  EXPECT_FLOAT_EQ(4.0, v3.y);
}

TEST(Vector2OperationTest, SubtEquals){
  Vector2 v1(1.0, 2.0);
  Vector2 v2(5.0, 6.0);
  v2 -= v1;

  EXPECT_FLOAT_EQ(4.0, v2.x);
  EXPECT_FLOAT_EQ(4.0, v2.y);
}

TEST(Vector2OperationTest, MultEquals){
  Vector2 v(1.0, 2.0);
  v *= 5.0;

  EXPECT_FLOAT_EQ(5.0, v.x);
  EXPECT_FLOAT_EQ(10.0, v.y);
}

TEST(Vector2OperationTest, DivEquals){
  Vector2 v(5.0, 10.0);
  v /= 5.0;

  EXPECT_FLOAT_EQ(1.0, v.x);
  EXPECT_FLOAT_EQ(2.0, v.y);
}

TEST(Vector2OperationTest, isEqual){
  Vector2 v1(5.0, 10.0);
  Vector2 v2(5.0, 10.0);
  Vector2 v3(5.1, 10.0);
  EXPECT_TRUE(v1 == v2);
  EXPECT_FALSE(v1 == v3);
}

TEST(Vector2OperationTest, BracketNotation){
  Vector2 v(1.0, 2.0);

  EXPECT_FLOAT_EQ(1.0, v[0]);
  EXPECT_FLOAT_EQ(2.0, v[1]);
}

TEST(Vector2OperationTest, ScalarDivision){
  Vector2 v(24.0, 24.0);
  Vector2 v2 = v / 6;
  EXPECT_FLOAT_EQ(v2.x, 4.0);
  EXPECT_FLOAT_EQ(v2.y, 4.0);
}

TEST(Vector2OperationTest, RealToVectorMult){
  Vector2 v(24.0, 24.0);
  Vector2 v2 = 2 * v;
  EXPECT_FLOAT_EQ(v2.x, 48.0);
  EXPECT_FLOAT_EQ(v2.y, 48.0);
}

TEST(Vector2DeathTest, DivsionByZeroAssert){
  Vector2 v(24.0, 24.0);
  EXPECT_DEATH({v/0;}, "");
}

TEST(Vector2OperationTest, MemberAssignment){
  Vector2 v(24.0, 24.0);
  v[0] = 48.0;
  v[1] = 48.0;
  EXPECT_FLOAT_EQ(v.x, 48.0);
  EXPECT_FLOAT_EQ(v.y, 48.0);
}

TEST(Vector2DeathTest, BracketsInvalidIndex){
  Vector2 v(1.0, 2.0);
  EXPECT_DEATH({v[2];}, "");
}

TEST(Vector2MethodTest, getLengthSquared) {
  Vector2 v(1.0, 2.0);
  EXPECT_FLOAT_EQ(v.getLengthSquared(), 5.0);
}

TEST(Vector2MethodTest, getLength) {
  Vector2 v(3.0, 4.0);
  EXPECT_FLOAT_EQ(v.getLength(), 5.0);
}

TEST(Vector2MethodTest, dotProduct) {
  Vector2 v1(1.0, 2.0);
  Vector2 v2(5.0, 10.0);
  EXPECT_FLOAT_EQ(v1.dot(v2), 25.0);
}

TEST(Vector2MethodTest, normalize) {
  Vector2 v(3.0, 4.0);
  v.normalize();
  EXPECT_FLOAT_EQ(v.x, 3.0 / 5);
  EXPECT_FLOAT_EQ(v.y, 4.0 / 5);
}

