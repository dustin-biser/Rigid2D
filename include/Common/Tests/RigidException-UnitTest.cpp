#include "../RigidException.h"
#include "gtest/gtest.h"
#include <cstdio>
#include <string>
#include <cstring>

using namespace Rigid2D;

//=== Test Exception ==========================================================
TEST(ExceptionTest, CreationNoDescription){
  Exception e(1, "funct", "file");

  EXPECT_EQ(e.getLine(), 1);
  EXPECT_EQ(e.getFunction(), "funct");
  EXPECT_EQ(e.getFile(), "file");
  EXPECT_EQ(e.getDescription(), "");
}

TEST(ExceptionTest, CreationWithStringLiterals){
  Exception e(1, "funct", "file", "description");

  EXPECT_EQ(e.getLine(), 1);
  EXPECT_EQ(e.getFunction(), "funct");
  EXPECT_EQ(e.getFile(), "file");
  EXPECT_EQ(e.getDescription(), "description");
}

TEST(ExceptionTest, WithWhat){
  Exception e(1, "funct", "file", "description");
  EXPECT_STREQ(e.what(), "file:1 Exception occured in function 'funct' : description");
}



//=== Test InternalErrorException =============================================
TEST(InternalErrorExceptionTest, Creation){
  InternalErrorException e(1, "funct", "file", "description");

  EXPECT_EQ(e.getLine(), 1);
  EXPECT_EQ(e.getFunction(), "funct");
  EXPECT_EQ(e.getFile(), "file");
  EXPECT_EQ(e.getDescription(), "description");
}

TEST(InternalErrorExceptionTest, WithWhat){
  InternalErrorException e(1, "funct", "file", "description");
  EXPECT_STREQ(e.what(), "file:1 InternalErrorException occured in function 'funct' : description");
}


//=== Test InvalidParameterException =============================================
TEST(InvalidParameterExceptionTest, Creation){
  InvalidParameterException e(1, "funct", "file", "description");

  EXPECT_EQ(e.getLine(), 1);
  EXPECT_EQ(e.getFunction(), "funct");
  EXPECT_EQ(e.getFile(), "file");
  EXPECT_EQ(e.getDescription(), "description");
}

TEST(InvalidParameterExceptionTest, WithWhat){
  InvalidParameterException e(1, "funct", "file", "description");
  EXPECT_STREQ(e.what(), "file:1 InvalidParameterException occured in function 'funct' : description");
}


//=== Test FileNotFoundException =============================================
TEST(FileNotFoundExceptionTest, Creation){
  FileNotFoundException subject(1, "funct", "file", "description");

  EXPECT_EQ(subject.getLine(), 1);
  EXPECT_EQ(subject.getFunction(), "funct");
  EXPECT_EQ(subject.getFile(), "file");
  EXPECT_EQ(subject.getDescription(), "description");
}

TEST(FileNotFoundExceptionTest, WithWhat){
  FileNotFoundException e(1, "funct", "file", "description");
  EXPECT_STREQ(e.what(), "file:1 FileNotFoundException occured in function 'funct' : description");
}


//=== Test IOException =============================================
TEST(IOExceptionTest, Creation){
  IOException subject(1, "funct", "file", "description");

  EXPECT_EQ(subject.getLine(), 1);
  EXPECT_EQ(subject.getFunction(), "funct");
  EXPECT_EQ(subject.getFile(), "file");
  EXPECT_EQ(subject.getDescription(), "description");
}

TEST(IOExceptionTest, WithWhat){
  IOException e(1, "funct", "file", "description");
  EXPECT_STREQ(e.what(), "file:1 IOException occured in function 'funct' : description");
}
