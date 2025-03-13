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

void ArrayWithRandomNumbers(int Array[100], int& Length) {
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

void SumTwoArray(int FirstArray[100], int SecondArray[100], int NewArray[100], int Length) {
	for (int i = 0; i < Length; i++)
	{
		NewArray[i] = FirstArray[i] + SecondArray[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int FirstArray[100], SecondArray[100], NewArray[100];

	int Length = ReadPositiveNumber("Enter a length of the arrays : ");

	ArrayWithRandomNumbers(FirstArray, Length);
	cout << "\nArray #1 elements : ";
	PrintAraay(FirstArray, Length);
	
	ArrayWithRandomNumbers(SecondArray, Length);
	cout << "\nArray #2 elements : ";
	PrintAraay(SecondArray, Length);

	SumTwoArray(FirstArray, SecondArray, NewArray, Length);
	cout << "\nSum of Array #1 and Array #2 elements : ";
	PrintAraay(NewArray, Length);
}