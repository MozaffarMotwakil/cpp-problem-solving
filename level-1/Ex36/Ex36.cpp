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

void ReadSimiDynamicArray(int Array[100], int& ArrayLength) {
	bool Continuation = true;

	do
	{
		AddArrayElement(Array, ArrayLength, ReadPositiveNumber("Enetr a number : "));
		
		Continuation = ReadTrueOrFalse("\nDo you want to add more numbers ? [0] : No, [1] : Yes ? ");

		cout << endl;

	} while (Continuation);
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
	int Array[100], ArrayLength = 0;

	ReadSimiDynamicArray(Array, ArrayLength);

	cout << "Araay length : " << ArrayLength << endl;
	cout << "Array elements : ";
	PrintArray(Array, ArrayLength);
}