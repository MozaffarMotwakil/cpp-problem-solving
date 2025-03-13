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

void CopyArray(int OrginalArray[], int NewArray[], int Length) {
	for (int i = 0; i < Length; i++)
	{
		NewArray[i] = OrginalArray[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int OrginalArray[100], NewArray[100], ArrayLength;

	FiilArrayWithRandomNumber(OrginalArray, ArrayLength);

	cout << "Orginal Array Elements : ";
	PrintArray(OrginalArray, ArrayLength);

	CopyArray(OrginalArray, NewArray, ArrayLength);

	cout << "New Array Elements : ";
	PrintArray(NewArray, ArrayLength);

}