#include <iostream>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

void PrintEachWord(string Text) {
	string Dilimeter = " ";
	string Word = "";
	short Position = 0;

	while ((Position = Text.find(Dilimeter)) != (string::npos))
	{
		Word = Text.substr(0, Position);

		if (Word != "")
		{
			cout << Word << endl;
		}

		Text.erase(0, Position + Dilimeter.length());
	}
	
	if (Word != "")
	{
		cout << Text << endl;
	}

}

int main()
{
	string Text = MyInputLib::ReadString("Enetr a text : ");

	cout << "\nYour string words are :\n\n";
	PrintEachWord(Text);

	system("pause > 0");
}