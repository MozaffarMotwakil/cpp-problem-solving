#include <iostream>
#include <string>

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

void ReadInbutUserNumbersArray(int Array[100], int& Length) {
	bool Continuation = true;

	do
	{
		Array[Length++] = ReadPositiveNumber("Enter Element [" + to_string(Length) + "] : ");

		Continuation = ReadTrueOrFalse("\nEnter 0 to No or 1 to Yes, Do you want add another number ? ");

		cout << endl;

	} while (Continuation);
}

void CopyReversedArray(int ArraySource[100], int ArrayDestination[100], int Length) {
	for (int i = 0; i < Length; i++)
	{
		ArrayDestination[i] = ArraySource[Length - i - 1];
	}
}

bool CheckIsPalindromeArray (int ArraySource[100], int ArrayReversed[100], int Length) {
	for (int i = 0; i < Length; i++)
	{
		if (ArraySource[i] != ArrayReversed[i])
		{
			return false;
		}
	}

	return true;
}

bool IsPalindromeArray(int Array[], int Length) {
	int ReversedArr[100];
	CopyReversedArray(Array, ReversedArr, Length);

	return CheckIsPalindromeArray(Array, ReversedArr, Length);
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
	
	int Arr[100], Length = 0;

	ReadInbutUserNumbersArray(Arr, Length);

	cout << "Array element :";
	PrintArray(Arr, Length);

	if (IsPalindromeArray(Arr, Length))
	{
		cout << "\nYes, is palindrome array\n";
	}
	else
	{
		cout << "\nNo, is not palindrome array\n";
	}
}