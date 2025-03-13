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

void PrintMiddleRowInMatrix(int Matrix[3][3], int Rows, int Columns) {
	int MiddleRow = Rows / 2;

	for (short i = 0; i < Columns; i++)
	{
		printf(" %0*d     ", 2, Matrix[MiddleRow][i]);
	}
}

void PrintMiddleColumnInMatrix(int Matrix[3][3], int Rows, int Columns) {
	int MiddleColumn = Columns / 2;

	for (short i = 0; i < Rows; i++)
	{
		printf(" %0*d     ", 2, Matrix[i][MiddleColumn]);
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{

			printf(" %0*d     ", 2, Matrix[i][j]);
			//cout << setw(3) << Matrix[i][j] << "     ";
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

	cout << "\nMiddle Row of the matrix is :\n";
	PrintMiddleRowInMatrix(Matrix, 3, 3);

	cout << "\nMiddle Column of the matrix is :\n";
	PrintMiddleColumnInMatrix(Matrix, 3, 3);

	return 0;
}