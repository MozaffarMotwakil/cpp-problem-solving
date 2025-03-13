#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Columns) {
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

		cout << endl;
	}
}

int SumColumnInMatrix(int Matrix[3][3], int ColumnNumber, int Rows) {
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		Sum += Matrix[i][ColumnNumber];
	}

	return Sum;
}

void PrintSumColumnsInMatrix(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Columns; i++)
	{
		printf(" Column %d Sum = %d\n", i + 1, SumColumnInMatrix(Matrix, i, Rows));
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "The following are elements of the matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nThe following are sum of each coloumn in the matrix :\n";
	PrintSumColumnsInMatrix(Matrix, 3, 3);

	return 0;
}