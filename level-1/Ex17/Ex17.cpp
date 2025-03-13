#include <iostream>

using namespace std;

string ReadString(string Message) {
	string Str = "";
	
	cout << Message;
	cin >> Str;

	return Str;
}

bool CheckPassword(string Password, string Guess) {
	return Password == Guess;
}

void GuessPassword(string OrginalPassword) {
	int TrialCount = 0;
	string Guess = "";

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Guess += char(i);
				Guess += char(j);
				Guess += char(k);

				TrialCount++;
				cout << "Trial[" << TrialCount << "] : " << Guess << endl;

				if (CheckPassword(OrginalPassword, Guess))
				{
					cout << "Password is : " << OrginalPassword << endl;
					cout << "Found after " << TrialCount << " Trial(s)" << endl;
					return;
				}

				Guess = "";
			}
		}
	}
}

int main()
{
	string Password = ReadString("Enter a 3-letters passwoed (All Capital) : ");
	GuessPassword(Password);
}