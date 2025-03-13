#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

string FirstLetterToUpperCase(string Sentence) {
	bool IsFirstLetter = true;

	for (short i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] != ' ' && IsFirstLetter)
		{
			Sentence[i] = tolower(Sentence[i]);
		}

		IsFirstLetter = (Sentence[i] == ' ') ? true : false;
	}

	return Sentence;
}

int main()
{
	string Sentence = MyInputLib::ReadString("Enter a Sentence : ");

	Sentence = FirstLetterToUpperCase(Sentence);

	cout << "String after conversion : " << Sentence;

	system("pause > 0");
}