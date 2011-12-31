#include "../r2error.h"
#include "gtest/gtest.h"

TEST(R2ErrorTest, Basic){
  R2Error index_exception("Error Description", MatrixIndexOutOfBoundsError);
  EXPECT_THROW(throw (index_exception), R2Error);
}

TEST(R2ErrorTest, VerifyDescription){
  char str[] = "Error Description";
  R2Error error(str, MatrixIndexOutOfBoundsError);

  EXPECT_EQ(error.describe(), str);
}

TEST(R2ErrorTest, VerifyErrorType){
  R2Error e1("Error Description", MatrixIndexOutOfBoundsError);
  R2Error e2("Error Description", VectorIndexOutOfBoundsError);

  EXPECT_EQ(e1.type(), MatrixIndexOutOfBoundsError);
  EXPECT_EQ(e2.type(), VectorIndexOutOfBoundsError);
}
