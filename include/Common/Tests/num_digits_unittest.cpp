#include "../num_digits.h"
#include "gtest/gtest.h"

using namespace Rigid2D;

TEST(numberOfDigits, PositiveDigits){
		EXPECT_TRUE(numberOfDigits(11) == 2);
		EXPECT_TRUE(numberOfDigits(111) == 3);
		EXPECT_TRUE(numberOfDigits(1111) == 4);
		EXPECT_TRUE(numberOfDigits(11111) == 5);
		EXPECT_TRUE(numberOfDigits(111111) == 6);
}

TEST(numberOfDigits, NegativeDigits){
		EXPECT_TRUE(numberOfDigits(-11) == 2);
		EXPECT_TRUE(numberOfDigits(-111) == 3);
		EXPECT_TRUE(numberOfDigits(-1111) == 4);
		EXPECT_TRUE(numberOfDigits(-111111) == 6);
}

TEST(numberOfDigits, OneDigitPositives){
	for(int i = 1; i < 10; i++){
		EXPECT_TRUE(numberOfDigits(i) == 1);
	}
}

TEST(numberOfDigits, OneDigitNegatives){
	for(int i = -1; i > -10; i--){
		EXPECT_TRUE(numberOfDigits(i) == 1);
	}
}

TEST(numberOfDigits, OneDigitZero){
	EXPECT_TRUE(numberOfDigits(0) == 1);
}

