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
			Matrix[i][j] = RandomNumber(0, 3);
		}
	}
}

short CountNumberInMatrix(int Matrix[3][3], int NumberToSearch, int Rows, int Columns) {
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] == NumberToSearch)
			{
				Counter++;
			}
		}
	}

	return Counter;
}

bool IsSparceMatrix(int Matrix[3][3], int Rows, int Columns) {
	int ZeroCount = CountNumberInMatrix(Matrix, 0, 3, 3), MatrixSize = (Rows * Columns - ZeroCount);
	return ZeroCount >= MatrixSize;
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

	if (IsSparceMatrix(Matrix, 3, 3))
	{
		cout << "\nYes, is sparce matrix\n";
	}
	else
	{
		cout << "\nNo, is not sparce matrix\n";
	}

	return 0;
}