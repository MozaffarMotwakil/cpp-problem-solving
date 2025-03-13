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

void PrintInvertedLetterPattern(int Number) {
	for (int i = 64 + Number; i >= 65; i--)
	{
		for (int j = i; j >= 65; j--)
		{
			cout << char(i);
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedLetterPattern(ReadPositiveNumber("Enter a maximum number to print inverted pattern : "));
}
