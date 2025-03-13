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

void MultiplyTwoMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResult[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j];
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


	MultiplyTwoMatrix(Matrix1, Matrix2, MatrixResult, 3, 3);
	cout << "\nThe following are matrix result elements :\n";
	PrintMatrix(MatrixResult, 3, 3);

	return 0;
}