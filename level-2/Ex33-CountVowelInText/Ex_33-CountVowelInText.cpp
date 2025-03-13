#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

bool IsVowel(char Letter) {
	Letter = toupper(Letter);
	return ((Letter == 'A') || (Letter == 'E') || (Letter == 'I') || (Letter == 'O') || (Letter == 'U'));
}

short CountVowelLetters(string Text) {
	short Counter = 0;

	for (char& Letter : Text) {
		if (IsVowel(Letter))
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	string Text = MyInputLib::ReadString("Enter a Text : ");

	cout << "Count of vowel letters in the text is : " << CountVowelLetters(Text);

	system("pause > 0");
}