#include <iostream>

using namespace std;

void AddArrayElement(int Array[100], int& ArrayLength, int ElementValue) {
	Array[ArrayLength] = ElementValue;
	ArrayLength++;
}

bool IsDistinctNumber(int Array[], int ArrayLength, int NumberToCheck) {
	for (int i = 0; i < ArrayLength; i++)
	{
		if (NumberToCheck == Array[i])
		{
			return false;
		}
	}

	return true;
}

void CopyDistinctNumberInArrray(int ArrSource[100], int ArraySourceLength, int ArrDestination[100], int& ArrayDestinationLength) {
	for (int i = 0; i < ArraySourceLength; i++)
	{
		if (IsDistinctNumber(ArrDestination, ArrayDestinationLength, ArrSource[i]))
		{
			AddArrayElement(ArrDestination, ArrayDestinationLength, ArrSource[i]);
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
	int ArrSource[] = { 10, 10, 10, 50, 50, 70, 70, 70, 90 };
	int ArraySourceLength = 9;

	cout << "Array #1 elements : ";
	PrintArray(ArrSource, ArraySourceLength);

	int ArrDestination[100], ArrayDestinationLength = 0;

	CopyDistinctNumberInArrray(ArrSource, ArraySourceLength, ArrDestination, ArrayDestinationLength);

	cout << "Array #2 elements : ";
	PrintArray(ArrDestination, ArrayDestinationLength);
}