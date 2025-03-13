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

void FillArrayWithRandomNumber(int Array[], int& ArrayLength) {
	ArrayLength = ReadPositiveNumber("Enter a number of the array's Elements : ");

	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}

}

int CountOddNumbersInArray(int Array[100], int Length) {
	int Counter = 0;

	for (int i = 0; i < Length; i++)
	{
		if (Array[i] % 2 != 0)
		{
			Counter++;
		}
	}

	return Counter;
}

void PrintArray(int Araay[100], int ArrayLength) {
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Araay[i] << " ";
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100], Length = 0;

	FillArrayWithRandomNumber(Array, Length);

	cout << "\nArray elements : ";
	PrintArray(Array, Length);

	cout << "\nCount of odd numbers in the array : " << CountOddNumbersInArray(Array, Length) << endl;
}