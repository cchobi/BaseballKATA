#include <iostream>
#include <stdexcept>

using namespace std;

class Baseball {
public:
	bool isDuplicatedNumber(string guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (auto ch : guessNumber) {
			if (ch < '0' || ch > '9') continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}

	void guess(const string guessNumber)
	{
		assertIllegalArgument(guessNumber);
	}
};