#include <iostream>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

short CountStringWords(string Text) {
	string Dilimeter = " ";
	string Word = "";
	short Counter = 0;
	int Position = 0;

	while ((Position = Text.find(Dilimeter)) != string::npos)
	{
		Word = Text.substr(0, Position);

		if (Word != "")
		{
			Counter++;
		}

		Text.erase(0, Position + Dilimeter.length());
	}

	if (Word != "")
	{
		Counter++;
	}

	return Counter;
}

int main() {
	string Text = MyInputLib::ReadString("Enter a text : ");

	cout << "Count of words in the text are : " << CountStringWords(Text);

	system("pause > 0");
}