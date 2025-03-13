#include <iostream>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

void PrintFirstLetter(string Sentence) {
	cout << Sentence[0] << endl;

	for (short i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == ' ')
		{
			cout << Sentence[i + 1] << endl;
		}
	}
}

int main()
{
	string Sentence = MyInputLib::ReadString("Enter a Sentence : ");
	PrintFirstLetter(Sentence);

	system("pause > 0");
}
