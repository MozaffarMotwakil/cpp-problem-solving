#include <iostream>
#include <cstdlib>
#include <iomanip>

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

void PrintMatrix(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << setw(3) << Matrix[i][j] << "     ";
		}

		cout << '\n';
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


void PrintIntersectedNumbersInTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (IsNumberExistsInMatrix(Matrix2, Matrix1[i][j], 3, 3))
			{
				cout << Matrix1[i][j] << "     ";
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3], MatrixResult[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "The following are matrix1 elements :\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nThe following are matrix1 elements :\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nItersected numbers in the two matrices are :\n";
	PrintIntersectedNumbersInTwoMatrices(Matrix1, Matrix2, 3, 3);

	return 0;
}