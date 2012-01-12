#include "../Vector3.h"
#include "../feq.h"
#include "gtest/gtest.h"
#include <stdio.h>

using namespace Rigid2D;

TEST(Vector3Test, ConstructorXYZ){
  Vector3 v(1,2,3);

  EXPECT_EQ(1.0, v.x);
  EXPECT_EQ(2.0, v.y);
  EXPECT_EQ(3.0, v.z);
}

TEST(Vector3Test, ConstructorArr3){
  float arr[] = {1,2,3};
  Vector3 v(arr);

  EXPECT_EQ(1.0, v.x);
  EXPECT_EQ(2.0, v.y);
  EXPECT_EQ(3.0, v.z);
}

TEST(Vector3OperationTest, DeepCopy){
  Vector3 v1(1,2,3);
  Vector3 v2 = v1;

  EXPECT_EQ(v2.x, v1.x);
  EXPECT_EQ(v2.y, v1.y);
  EXPECT_EQ(v2.z, v1.z);
}

TEST(Vector3OperationTest, AddEquals){
  Vector3 v1(1.0, 2.0, 3.0);
  Vector3 v2(5.0, 6.0, 7.0);
  v2 += v1;

  EXPECT_EQ(6.0, v2.x);
  EXPECT_EQ(8.0, v2.y);
  EXPECT_EQ(10.0, v2.z);
}

TEST(Vector3OperationTest, MultEquals){
  Vector3 v(1.0, 2.0, 3.0);
  v *= 5.0;

  EXPECT_EQ(5.0, v.x);
  EXPECT_EQ(10.0, v.y);
  EXPECT_EQ(15.0, v.z);
}

TEST(Vector3OperationTest, DivEquals){
  Vector3 v(5.0, 10.0, 15.0);
  v /= 5.0;

  EXPECT_EQ(1.0, v.x);
  EXPECT_EQ(2.0, v.y);
  EXPECT_EQ(3.0, v.z);
}

TEST(Vector3OperationTest, isEqual){
  Vector3 v1(5.0, 10.0, 15.0);
  Vector3 v2(5.0, 10.0, 15.0);
  Vector3 v3(5.1, 10.0, 15.0);
  EXPECT_TRUE(v1 == v2);
  EXPECT_FALSE(v1 == v3);
}

TEST(Vector3OperationTest, BracketNotation){
  Vector3 v(1.0, 2.0, 3.0);

  EXPECT_EQ(1.0, v[0]);
  EXPECT_EQ(2.0, v[1]);
  EXPECT_EQ(3.0, v[2]);
}

TEST(Vector3DeathTest, BracketsInvalidIndex){
  Vector3 v(1.0, 2.0, 3.0);

  EXPECT_DEATH({v[3];}, "Assertion `i < 3' failed");
}

TEST(Vector3MethodTest, getLengthSquared) {
  Vector3 v(1.0, 2.0, 2.0);
  EXPECT_EQ(v.getLengthSquared(), 9.0);
}

TEST(Vector3MethodTest, getLength) {
  Vector3 v(1.0, 2.0, 2.0);
  EXPECT_EQ(v.getLength(), 3.0);
}

TEST(Vector3MethodTest, dotProduct) {
  Vector3 v1(1.0, 2.0, 2.0);
  Vector3 v2(5.0, 10.0, 15.0);
  EXPECT_EQ(v1.dotProduct(v2), 55.0);
}

TEST(Vector3MethodTest, crossProduct) {
  Vector3 v1(3.0, -3.0, 1.0);
  Vector3 v2(4.0, 9.0, 2.0);
  Vector3 v3 = v1.crossProduct(v2);
  EXPECT_EQ(v3.x, -15.0);
  EXPECT_EQ(v3.y, -2.0);
  EXPECT_EQ(v3.z, 39.0);
}

TEST(Vector3MethodTest, normalize) {
  Vector3 v(2.0, -2.0, 1.0);
  v.normalize();
  EXPECT_TRUE(feq(v.x, 2.0 / 3));
  EXPECT_TRUE(feq(v.y, -2.0 / 3));
  EXPECT_TRUE(feq(v.z, 1.0 / 3));
}




