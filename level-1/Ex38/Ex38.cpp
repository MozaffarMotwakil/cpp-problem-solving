#include <iostream>

using namespace std;

int ReadTrueOrFalse(string Message) {
	int Result;

	do
	{
		cout << Message;
		cin >> Result;

		if (Result != 0 && Result != 1)
		{
			cout << "Wrong number, please enter \'0\' to \"No\" or \'1\' to \"Yes\"\n ";
		}

	} while (Result != 0 && Result != 1);

	return Result;
}

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

bool IsOddNumber(int Number) {
	return Number % 2 != 0;
}

void CopyOddNumberInArrray(int ArrSource[100], int SourceArrayLength, int ArrDestination[100], int& DestinationArrayLength) {
	for (int i = 0; i < SourceArrayLength; i++)
	{
		if (IsOddNumber(ArrSource[i]))
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

	CopyOddNumberInArrray(ArrSource, SourceArrayLength, ArrDestination, DestinationArrayLength);

	cout << "Array #2 elements : ";
	PrintArray(ArrDestination, DestinationArrayLength);
}