#include <iostream>

using namespace std;

string Replace(string Text, string OrginalPart, string NewPart) {
	int OrginalPartPosition = 0;

	while ((OrginalPartPosition = Text.find(OrginalPart)) != string::npos)
	{
		Text.replace(OrginalPartPosition, OrginalPart.length(), NewPart);
	}
	
	return Text;
}

int main()
{
	string Text = "Welcome to sudan, sudan is a nice country.";

	cout << "Orginal Text : " << Text << endl;
	cout << "Replace Text : " << Replace(Text, "sudan", "ksa") << endl;

	system("pause > 0");
}