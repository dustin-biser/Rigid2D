#include "../vector3.h"
#include "../feq.h"
#include "gtest/gtest.h"

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

TEST(Vector3Test, EqualOp){
  Vector3 v(1,2,3);
  Vector3 v2 = v;

  EXPECT_EQ(v2.x, v.x);
  EXPECT_EQ(v2.y, v.y);
  EXPECT_EQ(v2.z, v.z);
}

TEST(Vector3Test, AddEqOp){
  Vector3 v(1.0, 2.0, 3.0);
  Vector3 v2(5.0, 6.0, 7.0);
  v2 += v;

  EXPECT_EQ(6.0, v2.x);
  EXPECT_EQ(8.0, v2.y);
  EXPECT_EQ(10.0, v2.z);
}

TEST(Vector3Test, MultEqOp){
  Vector3 v(1.0, 2.0, 3.0);
  v *= 5.0;

  EXPECT_EQ(5.0, v.x);
  EXPECT_EQ(10.0, v.y);
  EXPECT_EQ(15.0, v.z);
}

TEST(Vector3Test, DivEqOp){
  Vector3 v(5.0, 10.0, 15.0);
  v /= 5.0;

  EXPECT_EQ(1.0, v.x);
  EXPECT_EQ(2.0, v.y);
  EXPECT_EQ(3.0, v.z);
}

TEST(Vector3Test, BracketOp){
  Vector3 v(1.0, 2.0, 3.0);

  EXPECT_EQ(1.0, v[0]);
  EXPECT_EQ(2.0, v[1]);
  EXPECT_EQ(3.0, v[2]);
}

/*
TEST(Vector3DeathTest, BracketOpInvalidIndex){
  Vector3 v(1.0, 2.0, 3.0);

  EXPECT_DEATH({v[3];});
}
*/
