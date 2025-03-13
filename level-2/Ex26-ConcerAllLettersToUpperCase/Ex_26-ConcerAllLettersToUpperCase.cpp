#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

string LowerAllString(string Sentence) {

	for (short i = 0; i < Sentence.length(); i++)
	{
			Sentence[i] = tolower(Sentence[i]);
	}

	return Sentence;
}

string UppperAllString(string Sentence) {

	for (short i = 0; i < Sentence.length(); i++)
	{
			Sentence[i] = toupper(Sentence[i]);
	}

	return Sentence;
}

int main()
{
	string Sentence = MyInputLib::ReadString("Enter a Sentence : ");

	cout << "\nString after conversion letters to lower case : " << LowerAllString(Sentence);
	
	cout << "\nString after conversion letters to upper case : " << UppperAllString(Sentence);
	
	system("pause > 0");
}