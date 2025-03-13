#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

bool IsVowel(char Letter) {
	Letter = toupper(Letter);
	return ((Letter == 'A') || (Letter == 'E') || (Letter == 'I') || (Letter == 'O') || (Letter == 'U'));
}

int main()
{
	char Letter = MyInputLib::ReadChar("Enter a letter to search : ");

	if (IsVowel(Letter))
	{
		printf("Yes, the letters '%c' is Vowel", Letter);
	}
	else
	{
		printf("No, the letters '%c' is Not Vowel", Letter);
	}

	system("pause > 0");
}