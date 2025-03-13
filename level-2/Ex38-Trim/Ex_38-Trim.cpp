#include <iostream>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

string TrimLeft(string Text) {
	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
			return Text.substr(i, Text.length());
	}
	return Text;
}

string TrimRight(string Text) {
	for (short i = Text.length() - 1; i >= 0; i--)
	{
		if (Text[i] != ' ')
			return Text.substr(0, i + 1);
	}

	return Text;
}

string Trim(string Text) {
	return TrimLeft(TrimRight(Text));
}

int main()
{
	string Text = MyInputLib::ReadString("Enter a text : ");

	cout << "Trim Left : " << TrimLeft(Text) << endl;
	
	cout << "Trim Right : " << TrimRight(Text) << endl;
	
	cout << "Trim : " << Trim(Text);

	system("pause > 0");
}