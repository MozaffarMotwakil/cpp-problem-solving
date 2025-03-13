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


string JoinString(string vWords[], short ArrLength, string Dilimeter) {
	string Text = "";

	for (short i = 0; i < ArrLength; i++)
	{
		Text += vWords[i] + Dilimeter;
	}

	return Text.substr(0, Text.length() - Dilimeter.length());
}

int main()
{
	vector<string> vWords{ "Mozaffar", "Asad", "Anas", "Ahmed" };
	cout << "Vector after join function : " << JoinString(vWords, ",");
	
	string arrWords[4] { "Mozaffar", "Asad", "Anas", "Ahmed" };
	cout << "\nArray after join function : " << JoinString(arrWords, 4, ",");

	system("pause > 0");
}