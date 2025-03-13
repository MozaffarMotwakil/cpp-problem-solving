#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

short CountLetter(string Text, char Letter) {
	short Counter = 0;
	
	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] == Letter)
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	string Text = MyInputLib::ReadString("Enter a Text : ");
	
	char Letter = MyInputLib::ReadChar("\nEnter a letter to search : ");

	cout << "\nLetter '" << Letter << "' Count : " << CountLetter(Text, Letter);

	system("pause > 0");
}