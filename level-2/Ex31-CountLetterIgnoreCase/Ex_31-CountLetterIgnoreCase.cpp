#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyTextUtilsLib.h"

using namespace std;

short CountLetter(string Text, char Letter, bool MatchCase = true) {
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (MatchCase)
		{
			if (Text[i] == Letter)
			{
				Counter++;
			}
		}
		else
		{
			if (toupper(Text[i]) == toupper(Letter))
			{
				Counter++;
			}
		}
	}

	return Counter;
}

//
//short CountLetterIgnoreCase(string Text, char Letter) {
//	short Counter = 0;
//
//	Letter = toupper(Letter);
//	Text = MyTextUtilsLib::UppperAllString(Text);
//
//
//	for (short i = 0; i < Text.length(); i++)
//	{
//		if (Text[i] == Letter)
//		{
//			Counter++;
//		}
//	}
//
//	return Counter;
//}

int main()
{
	string Text = MyInputLib::ReadString("Enter a Text : ");

	char Letter = MyInputLib::ReadChar("\nEnter a letter to search : ");


	cout << "\nLetter '" << Letter << "' Count : " << CountLetter(Text, Letter);
	cout << "\nLetter '" << Letter << "' or '" << MyTextUtilsLib::InvertLetterCase(Letter) << "' Count : " << CountLetter(Text, Letter, false);

	system("pause > 0");
}