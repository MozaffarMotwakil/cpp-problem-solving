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
			cout << "Wrong number, please enter a positive number." << endl;
		}

	} while (Number < 0);

	return Number;
}

void ReadArray(int Array[], short& ArrayLength) {
	ArrayLength = ReadPositiveNumber("Enter a number of the array's Elements : ");

	cout << "Enter array elements :\n";

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Element[" << i + 1 << "] : ";
		cin >> Array[i];
	}

}

void PrintArray(int Array[], short ArrayLength) {
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i] << ' ';
	}

	cout << endl;
}

int TimesRepeated(int Array[], short ArrayLength, short NumberToCheck) {
	int RepeationCount = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (NumberToCheck == Array[i])
		{
			RepeationCount++;
		}
	}

	return RepeationCount;
}

int main()
{
	int Array[100];
	short ArrayLength;
	
	cout << "Orginal array : ";
	ReadArray(Array, ArrayLength);

	int NumberToCheck = ReadPositiveNumber("Enter the number you want to check : ");

	PrintArray(Array, ArrayLength);
	cout << NumberToCheck << " is repeated " << TimesRepeated(Array, ArrayLength, NumberToCheck) << " time(s)" << endl;
}