#include <iostream>
#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question{question}
	{}

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
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Mus be number.");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		return { true, getStrikes(guessNumber), getBalls(guessNumber) };
	}

	int getStrikes(const string& guessNumber)
	{
		if (guessNumber == question) {
			return 3;
		}

		int numStrikes = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) numStrikes++;
		}

		return numStrikes;
	}

	int getBalls(const string& guessNumber)
	{
		int numBalls = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != j && guessNumber[i] == question[j]) numBalls++;
			}
		}

		return numBalls;
	}

private:
	string question;
};