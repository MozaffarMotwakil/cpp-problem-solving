#include <iostream>
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

string ReverseString(string Text) {
	vector<string> vWords = Split(Text, " ");
	string ReverseText = "";

	for (short i = vWords.size() - 1; i >= 0; i--)
	{
		ReverseText += vWords[i] + " ";
	}

	return ReverseText.substr(0, ReverseText.length() - 1);
}

int main()
{
	string Text = "Hi my name is Mozaffar Motwakil";

	cout << "Orginal string is : " << Text << endl;
	cout << "\nReverse string is : " << ReverseString(Text);

	system("pause > 0");
}