#include <iostream>
#include <cstdlib>

using namespace std;

int ReadPositiveNumber(string Message) {
	int Number = 0;

	do
	{
		cout << Message;
		cin >> Number;

		if (Number < 0)
		{
			cout << "Wrong number, please enter a positive number.\n";
		}
	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int Array[100], int& Length) {
	Length = ReadPositiveNumber("Enter a length of the arrray : ");

	for (int i = 0; i < Length; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void PrintAraay(int Array[100], int Length) {
	for (int i = 0; i < Length; i++)
	{
		cout << Array[i] << " ";
	}

	cout << endl;
}

int GetElementIndex(int Array[100], int Length, int NumberToSerch) {
	for (int i = 0; i < Length; i++)
	{
		if (Array[i] == NumberToSerch)
		{
			return i;
		}
	}

	return -1;
}

void PrintElementPosition(int ElementIndex) {
	if (ElementIndex == -1)
	{
		cout << "The number is not found :-(" << endl;
	}
	else
	{
		cout << "The number found at position : " << ElementIndex << endl;
		cout << "The number found at order : " << ElementIndex + 1 << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100], Length;

	FillArrayWithRandomNumbers(Array, Length);
	
	cout << "\nArray Elements : ";
	PrintAraay(Array, Length);

	int NumberToSerch = ReadPositiveNumber("\nEnter a number to serch for : ");

	cout << "\nNumber you are looking for is : " << NumberToSerch << endl;

	PrintElementPosition(GetElementIndex(Array, Length, NumberToSerch));
}