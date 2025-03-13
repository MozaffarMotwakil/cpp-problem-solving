#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharType { SmallLetter, CapitalLetter, SpecialCharacter, Digit};

int ReadPositiveNumber(string Message) {
	int Number = 0;

	do
	{
		cout << Message;
		cin >> Number;

		if (Number < 0)
		{
			cout << "Wrong number, please enter positive number." << endl;
		}

	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

char RandomCharacter(enCharType CharTypr) {
	switch (CharTypr)
	{
	case SmallLetter:
		return RandomNumber(97, 122);
	case CapitalLetter:
		return RandomNumber(65, 90);
	case SpecialCharacter:
		return RandomNumber(33, 47);
	case Digit:
		return RandomNumber(48, 57);
	default:
		return 0;
	}
}

string GenerateWord(enCharType CharType, short Length) {
	string Part = "";

	for (int i = 1; i <= Length; i++)
	{
		Part += RandomCharacter(CharType);
	}

	return Part;
}

string GenerateKay() {
	string Kay = "";

	Kay += GenerateWord(enCharType::CapitalLetter, 4) + '-';
	Kay += GenerateWord(enCharType::CapitalLetter, 4) + '-';
	Kay += GenerateWord(enCharType::CapitalLetter, 4) + '-';
	Kay += GenerateWord(enCharType::CapitalLetter, 4);

	return Kay;
}

void PrintKays(int KaysCount) {
	for (int i = 1; i <= KaysCount; i++)
	{
		cout << "Kay [" << i << "] : " << GenerateKay() << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int KaysCount = ReadPositiveNumber("Enter a number of kays that you want print : ");
	PrintKays(KaysCount);
}
