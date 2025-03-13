#include <iostream>

using namespace std;

enum enNumberType { Prime, NotPrime };

int ReadPositiveNumber(string Message) {
	int Number = 0;

	do
	{
		cout << Message;
		cin >> Number;

		if (Number <= 0)
			cout << "Wrong number, please enter a positive number.\n";

	} while (Number <= 0);

	return Number;
}

enNumberType CheckNumberType(int Number) {
	int MeddleNumber = ceil(Number / 2);

	for (int i = 2; i <= MeddleNumber; i++)
	{
		if (Number % i == 0)
		{
			return NotPrime;
		}
	}

	return Prime;
}

void PrintPrimeNumbersFrom1toN(int N) {
	cout << "Prime numbers from 1 to " << N << " is :\n";
	for (int i = 1; i <= N; i++)
	{
		if (CheckNumberType(i) == Prime)
			cout << i << endl;
	}
}

int main()
{
	int Num = ReadPositiveNumber("Enter a number : ");
	PrintPrimeNumbersFrom1toN(Num);
}