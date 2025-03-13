#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharacterStatus { SmallLetter = 97, CapitalLetter = 65, SpecialCharacter = 33, Digit = 48 };

int GetMaxLimitForStatus(enCharacterStatus CharacterStatus) {
	switch (CharacterStatus)
	{
	case SmallLetter:
		return 122;
	case CapitalLetter:
		return 90;
	case SpecialCharacter:
		return 47;
	case Digit:
		return 57;
	default:
		return 0;
	}
}

char RandomNumber(enCharacterStatus CharacterStatus) {
	int To = GetMaxLimitForStatus(CharacterStatus);

	return rand() % (To - CharacterStatus + 1) + CharacterStatus;
}


int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(SmallLetter) << endl;
	cout << RandomNumber(CapitalLetter) << endl;
	cout << RandomNumber(SpecialCharacter) << endl;
	cout << RandomNumber(Digit) << endl;
}
