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
			Matrix[i][j] = RandomNumber(1, 10);
		}
	}
}

int SumMatrix(int Matrix[3][3], int Rows, int Columns) {
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Sum += Matrix[i][j];
		}
	}

	return Sum;
}

bool AreMatricesTypical(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Columns) {
	return SumMatrix(Matrix1, Rows, Columns) == SumMatrix(Matrix2, Rows, Columns);
}

void PrintMatrix(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			printf(" %0*d     ", 2, Matrix[i][j]);
		}

		cout << '\n';
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "The following are matrix #1 elements :\n";
	PrintMatrix(Matrix1, 3, 3);


	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "The following are matrix #2 elements :\n";
	PrintMatrix(Matrix2, 3, 3);


	if (AreMatricesTypical(Matrix1, Matrix2, 3, 3))
		cout << "\nYes, Matrices are equal\n";
	else
		cout << "\nNo, Matrices are Not equal\n";

	return 0;
}