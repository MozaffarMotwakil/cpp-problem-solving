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
	Length = ReadPositiveNumber("Enter a length of the array : ");

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

void CopyPrimeNumberInArray(int OrginalArray[100], int OrginalArrayLength, int NewArray[100], int& NewArrayLength) {
	NewArrayLength = 0;

	for (int i = 0; i < OrginalArrayLength; i++)
	{
		if (IsPrimeNumber(OrginalArray[i]))
		{
			NewArray[NewArrayLength] = OrginalArray[i];
			NewArrayLength++;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int OrginalArray[100], NewArray[100], OrginalAraayLength, NewAraayLength;

	ArrayWithRandomNumbers(OrginalArray, OrginalAraayLength);

	cout << "Orginal array elements : ";
	PrintAraay(OrginalArray, OrginalAraayLength);

	CopyPrimeNumberInArray(OrginalArray, OrginalAraayLength, NewArray, NewAraayLength);

	cout << "New array elements : ";
	PrintAraay(NewArray, NewAraayLength);
}