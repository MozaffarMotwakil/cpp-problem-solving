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

void ReadArrayWithRandomNumbers(int Array[100], int& Length) {
	Length = ReadPositiveNumber("Enter a length of the arrray : ");

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

void CopyReversedArray(int OrginalArray[100], int NewArray[100], int Length) {
	for (int i = 0; i < Length; i++)
	{
		NewArray[i] = OrginalArray[Length - i - 1];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int OrginalArray[100], NewArray[100], Length;

	ReadArrayWithRandomNumbers(OrginalArray, Length);

	cout << "Array #1 elements : ";
	PrintAraay(OrginalArray, Length);

	CopyReversedArray(OrginalArray, NewArray, Length);

	cout << "Array #2 elements after copying Array #1 reversed elements : ";
	PrintAraay(NewArray, Length);
}