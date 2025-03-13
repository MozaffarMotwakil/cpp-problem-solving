#include <iostream>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"
#include <vector>

using namespace std;

vector<string> Split(string Text, string Dilimeter) {
	string Word = "";
	int Position = 0;
	vector<string> vWords;

	while ((Position = Text.find(Dilimeter)) != string::npos)
	{
		Word = Text.substr(0, Position);

		if (Word != "")
		{
			vWords.push_back(Word);
		}

		Text.erase(0, Position + Dilimeter.length());
	}

	if (Word != "")
	{
		vWords.push_back(Text);
	}

	return vWords;
}

int main() {
	string Text = MyInputLib::ReadString("Enter a text : ");
	vector<string> vWords = Split(Text, " ");

	cout << "\nTokens = " << vWords.size() << endl;

	for (string& Word : vWords)
	{
		cout << Word << endl;
	}

	system("pause > 0");
}