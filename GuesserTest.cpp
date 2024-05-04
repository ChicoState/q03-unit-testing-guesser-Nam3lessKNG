/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, GuessConstructer){
	Guesser guess = Guesser("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbb");
	bool actual = guess.match("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, Bruteforce){
	Guesser guess = Guesser("abcd");
	bool brute = guess.match("abcdefghijk"); //false
	bool actual = guess.match("abcd"); //true
	ASSERT_EQ(true, (brute == actual));
}

TEST(GuesserTest, DisOf2){
	Guesser guess = Guesser("aa");
	guess.match("b");
	int actual = guess.remaining();
	ASSERT_EQ(2, actual);
}