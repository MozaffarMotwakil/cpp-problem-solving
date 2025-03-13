#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Columns) {
	int Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

bool IsNumberExistsInMatrix(int Matrix[3][3], int NumberToSearch, int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] == NumberToSearch)
			{
				return true;
			}
		}
	}

	return false;
}

void PrintMatrix(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << setw(3) << Matrix[i][j] << "      ";
		}

		cout << '\n';
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "The following are matrix elements :\n";
	PrintMatrix(Matrix, 3, 3);


	int NumberToSearch = MyInputLib::ReadPositiveNumber("\nEnter the number to look for in matrix : ");


	if (IsNumberExistsInMatrix(Matrix, NumberToSearch, 3, 3))
	{
		cout << "\nYes, it is there\n";
	}
	else
	{
		cout << "\nNo, it is not there\n";
	}

	return 0;
}