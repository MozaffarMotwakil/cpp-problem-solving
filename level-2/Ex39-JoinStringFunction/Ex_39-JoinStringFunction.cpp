#include <iostream>
#include <vector>

using namespace std;

string JoinString(vector<string> vWords, string Dilimeter) {
	string Text = "";

	for (short i = 0; i < vWords.size(); i++)
	{
		Text += vWords.at(i) + Dilimeter;
	}

	return Text.substr(0, Text.length() - Dilimeter.length());
}

int main()
{
	vector<string> vWords{ "Mozaffar", "Asad", "Anas", "Ahmed" };

	cout << "Vector after join function : " << JoinString(vWords, ",");

	system("pause > 0");
}