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

//TODO implement more tests.
