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

void ReadArray(int Array[], short ArrayLength) {
	cout << "Enter array elements :\n";

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Element[" << i + 1 << "] : ";
		cin >> Array[i];
	}

}

void PrintArrayElements(int Array[], short ArrayLength) {
	cout << "Orginal array : ";

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i] << ' ';
	}

	cout << endl;
}

int GetRepeationNumberInArray(int Array[], short ArrayLength, short NumberForCheck) {
	int RepeationCount = 0;
	
	for (int i = 0; i < ArrayLength; i++)
	{
		if (NumberForCheck == Array[i])
		{
			RepeationCount++;
		}
	}

	return RepeationCount;
}

int main()
{
	int Array[100];
	short ArrayLength = ReadPositiveNumber("Enter a number of the array's Elements : ");
	ReadArray(Array, ArrayLength);

	int NumberForCheck = ReadPositiveNumber("Enter the number you want to check : ");
	
	PrintArrayElements(Array, ArrayLength);
	cout << NumberForCheck << " is repeated " << GetRepeationNumberInArray(Array, ArrayLength, NumberForCheck) << " time(s)" << endl;
}