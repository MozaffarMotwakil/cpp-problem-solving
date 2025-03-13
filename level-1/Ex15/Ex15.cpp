#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message) {
	int Num = 0;

	do
	{
		cout << Message;
		cin >> Num;

		if (Num < 0)
		{
			cout << "Wrong number, please enter a positive number.\n";
		}

	} while (Num < 0);

	return Num;
}

void PrintLetterPattern(int Number) {
	for (int i =65; i <= 64 + Number; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}

int main()
{
	PrintLetterPattern(ReadPositiveNumber("Enter a maximum number to print inverted pattern : "));
}