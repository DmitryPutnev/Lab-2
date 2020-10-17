#include "pch.h"
#include "C:\Users\79817\source\repos\Lab(2.1)\Lab(2.1)\function.c"

TEST(TestLab21, TestSymbol)
{
	EXPECT_EQ(glas('A'), 1);
	EXPECT_EQ(glas('I'), 1);
	EXPECT_EQ(glas('n'), 0);
	EXPECT_EQ(glas('p'), 0);
}
TEST(TestLab22, TestNumber)
{
	EXPECT_EQ(glas('5'), 0);
	EXPECT_EQ(glas('-2'), 0);
	EXPECT_EQ(glas('100'), 0);
	EXPECT_EQ(glas('0'), 0);
}