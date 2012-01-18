#include "../Vector2.h"
#include "../feq.h"
#include "gtest/gtest.h"
#include <stdio.h>

using namespace Rigid2D;

TEST(Vector2Test, ConstructorXY){
  Vector2 v(1,2);

  EXPECT_FLOAT_EQ(1.0, v.x);
  EXPECT_FLOAT_EQ(2.0, v.y);
}

TEST(Vector2OperationTest, DivsionByZeroAssert){
//TODO: implement test.
	EXPECT_TRUE(false);
}

TEST(Vector2OperationTest, MemberAssignment){
//TODO: implement test.
// - Test vector member assignment using the form vec[0] = 2.0f.
	EXPECT_TRUE(false);
}

//TODO implement more tests. Need full code coverage.

