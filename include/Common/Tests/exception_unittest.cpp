#include "../exception.h"
#include "gtest/gtest.h"
#include <cstdio>

using namespace Rigid2D;

TEST(ExceptionTest, Creation){
  Exception e(1, "funct", "file", "description");

  EXPECT_EQ(e.getLine(), 1);
  EXPECT_EQ(e.getFunction(), "funct");
  EXPECT_EQ(e.getFile(), "file");
  EXPECT_EQ(e.getDescription(), "description");
}
