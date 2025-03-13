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

void PrintNumberPattern(int Number) {
	for (int i = 1; i <= Number; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}

int main()
{
	PrintNumberPattern(ReadPositiveNumber("Enter a maximum number to print inverted pattern : "));
}
