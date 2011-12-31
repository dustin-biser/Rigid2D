#include "../r2error.h"
#include "gtest/gtest.h"

TEST(R2ErrorTest, Basic){
  R2Error index_exception(MatrixIndexOutOfBoundsError);
  EXPECT_THROW(throw (index_exception), R2Error);
}

TEST(R2ErrorTest, VerifyDescription){
  char str[] = "Error Description";
  R2Error error(MatrixIndexOutOfBoundsError, str);

  EXPECT_EQ(error.describe(), str);
}

TEST(R2ErrorTest, VerifyErrorType){
  R2Error e1(MatrixIndexOutOfBoundsError);
  R2Error e2(VectorIndexOutOfBoundsError);

  EXPECT_EQ(e1.type(), MatrixIndexOutOfBoundsError);
  EXPECT_EQ(e2.type(), VectorIndexOutOfBoundsError);
}
