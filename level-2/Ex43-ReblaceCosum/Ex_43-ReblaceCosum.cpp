#include <iostream>
#include <vector>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyTextUtilsLib.h"

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

string JoinString(vector<string> vWords, string Dilimeter) {
	string Text = "";

	for (short i = 0; i < vWords.size(); i++)
	{
		Text += vWords.at(i) + Dilimeter;
	}

	return Text.substr(0, Text.length() - Dilimeter.length());
}

string Replace(string Text, string PartToReplace, string ReplaceTo, bool MatchCase = true) {
	vector<string> vTextWords = Split(Text, " ");

	for (string& Word : vTextWords) 
	{
		if (MatchCase)
		{
			if (Word == PartToReplace)
			{
				Word = ReplaceTo;
			}
		}
		else
		{
			if (MyTextUtilsLib::UppperAllString(Word) == MyTextUtilsLib::UppperAllString(PartToReplace))
			{
				Word = ReplaceTo;
			}
		}
	}

	return JoinString(vTextWords, " ");
}

int main()
{
	string Text = "Welcome to sudan , sudan is a nice country.";

	cout << "Orginal Text                    : " << Text << endl;
	cout << "Replace Text with match case    : " << Replace(Text, "Sudan", "ksa") << endl;
	cout << "Replace Text Without match case : " << Replace(Text, "Sudan", "ksa", false) << endl;

	system("pause > 0");
}