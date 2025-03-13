#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void Fill3x3MatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Columns) {
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

int RowSum(int Matrix[3][3], int RowNumber, int Columns) {
	int Sum = 0;

	for (short j = 0; j < Columns; j++)
	{
		Sum += Matrix[RowNumber][j];
	}

	return Sum;
}

void SumEachRowInMatrixInArray(int Matrix[3][3], int Array[3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		Array[i] = RowSum(Matrix, i, Columns);
	}
}

void PrintArray(int Array[3]) {
	cout << "\nThe following are the sum of each row in the matrix :\n";
	for (short i = 0; i < 3; i++)
	{
		printf(" Row %d Sum = %d\n", i + 1, Array[i]);
	}
}

int main() {
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	Fill3x3MatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "The following is 3*3 Random Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	int Array[3];
	SumEachRowInMatrixInArray(Matrix, Array, 3, 3);
	PrintArray(Array);

	return 0;
}