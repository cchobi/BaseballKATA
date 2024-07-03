#include "pch.h"
#include "../Baseball/baseball.cpp"

class BasballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber)
	{
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BasballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}
