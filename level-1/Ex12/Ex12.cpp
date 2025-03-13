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

void PrintInvertedPattern(int Number) {
	for (int i = Number; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << i;
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedPattern(ReadPositiveNumber("Enter a maximum number to print inverted pattern : "));
}