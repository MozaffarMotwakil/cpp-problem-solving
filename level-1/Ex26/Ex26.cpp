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
			cout << "Wrong number, please enter a positive number." << endl;
		}

	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FiilArrayWithRandomNumber(int Array[], int& ArrayLength) {
	ArrayLength = ReadPositiveNumber("Enter a number of the array's Elements : ");

	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}

}

void PrintArray(int Array[], int ArrayLength) {
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i] << ' ';
	}

	cout << endl;
}

int SumNumbersInArray(int Array[], int Length) {
	int Sum = 0;

	for (int i = 0; i < Length; i++)
	{
		Sum += Array[i];
	}

	return Sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100], ArrayLength;

	FiilArrayWithRandomNumber(Array, ArrayLength);

	cout << "Array Elements : ";
	PrintArray(Array, ArrayLength);

	cout << "Sum of numbers is : " << SumNumbersInArray(Array, ArrayLength) << endl;
}