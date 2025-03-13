#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

bool IsVowel(char Letter) {
	Letter = toupper(Letter);
	return ((Letter == 'A') || (Letter == 'E') || (Letter == 'I') || (Letter == 'O') || (Letter == 'U'));
}

void PrintVowelLetters(string Text) {
	for (char& Letter : Text) {
		if (IsVowel(Letter))
		{
			cout << Letter << "     ";
		}
	}
}

int main()
{
	string Text = MyInputLib::ReadString("Enter a Text : ");

	cout << "The vowel letters in the text are  : ";
	PrintVowelLetters(Text);

	system("pause > 0");
}