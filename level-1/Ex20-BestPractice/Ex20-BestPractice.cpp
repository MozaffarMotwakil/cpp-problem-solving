#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharType { SmallLetter, CapitalLetter, SpecialCharacter, Digit };

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

char RandomCharacter(enCharType CharType) {
	switch (CharType)
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

int main()
{
	srand((unsigned)time(NULL));

	cout << RandomCharacter(enCharType::SmallLetter) << endl;
	cout << RandomCharacter(enCharType::CapitalLetter) << endl;
	cout << RandomCharacter(enCharType::SpecialCharacter) << endl;
	cout << RandomCharacter(enCharType::Digit) << endl;
}