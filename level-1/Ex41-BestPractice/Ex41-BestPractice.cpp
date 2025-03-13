#include <iostream>

using namespace std;

void FillArray(int Arr[], int& Length) {
	Length = 6;

	Arr[0] = 10;
	Arr[1] = 20;
	Arr[2] = 30;
	Arr[3] = 30;
	Arr[4] = 20;
	Arr[5] = 10;
}

void PrintArray(int Araay[100], int ArrayLength) {
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Araay[i] << " ";
	}

	cout << endl;
}

bool IsPalindromeArray(int Array[], int Length) {
	for (int i = 0; i < Length; i++)
	{
		if (Array[i] != Array[Length - i - 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Length = 0;

	FillArray(Arr, Length);

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