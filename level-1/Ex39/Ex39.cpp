#include <iostream>

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

void AddArrayElement(int Array[100], int& ArrayLength, int ElementValue) {
	Array[ArrayLength] = ElementValue;
	ArrayLength++;
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

bool IsPrimeNumber(int Number) {
	int MiddleNumber = round(Number / 2);

	for (int i = 2; i <= MiddleNumber; i++)
	{
		if (Number % i == 0)
		{
			return false;
		}
	}

	return true;
}

void CopyPrimeNumberInArrray(int ArrSource[100], int SourceArrayLength, int ArrDestination[100], int& DestinationArrayLength) {
	for (int i = 0; i < SourceArrayLength; i++)
	{
		if (IsPrimeNumber(ArrSource[i]))
		{
			AddArrayElement(ArrDestination, DestinationArrayLength, ArrSource[i]);
		}
	}
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
	int ArrSource[100], SourceArrayLength = 0;

	FillArrayWithRandomNumber(ArrSource, SourceArrayLength);

	cout << "Array #1 elements : ";
	PrintArray(ArrSource, SourceArrayLength);

	int ArrDestination[100], DestinationArrayLength = 0;

	CopyPrimeNumberInArrray(ArrSource, SourceArrayLength, ArrDestination, DestinationArrayLength);

	cout << "Array #2 elements : ";
	PrintArray(ArrDestination, DestinationArrayLength);
}