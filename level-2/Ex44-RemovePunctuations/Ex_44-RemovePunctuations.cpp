#include <iostream>

using namespace std;

string RemovePunctuations(string Text) {
	for (short i = 0; i < Text.length(); i++)
	{
		if (ispunct(Text[i]))
		{
			Text[i] = '\0';
		}
	}

	return Text;
}

int main()
{
	string Text = " Hi my name is Mozaffar, i'm 21 years old... i love su:da:n;";

	cout << "Orginal Text : " << Text << endl;
	cout << "edited  Text : " << RemovePunctuations(Text) << endl;

	system("pause > 0");
}