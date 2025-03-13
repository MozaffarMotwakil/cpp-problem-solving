#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

short CountSmallLetters(string Text) {
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (islower(Text[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

short CountCapitalLetters(string Text) {
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (isupper(Text[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	string Text = MyInputLib::ReadString("Enter a Text : ");

	cout << "\nString length : " << Text.length();
	cout << "\nCapital letters count : " << CountCapitalLetters(Text);
	cout << "\nSmall letters count : " << CountSmallLetters(Text);

	system("pause > 0");
}