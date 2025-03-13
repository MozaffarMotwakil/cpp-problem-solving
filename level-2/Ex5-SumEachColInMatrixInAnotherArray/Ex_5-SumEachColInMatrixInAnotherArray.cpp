#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Columns) {
	cout << "The following are matrix elements :\n";

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << setw(3) << Matrix[i][j] << "     ";
		}

		cout << '\n';
	}
}

int SumColumnInMatrix(int Matrix[3][3], int ColumnNumber, int Rows) {
	int Sum = 0;

	for (short RowNumber = 0; RowNumber < Rows; RowNumber++)
	{
		Sum += Matrix[RowNumber][ColumnNumber];
	}

	return Sum;
}

void SumMatrixColumnInArray(int Matrix[3][3], int Array[3], int Rows, int Columns) {
	for (short index = 0; index < Columns; index++)
	{
		Array[index] = SumColumnInMatrix(Matrix, index, Rows);
	}
}

void PrintArray(int Array[3], int Length) {
	cout << "\nThe following are sum of each column :\n";

	for (short i = 0; i < Length; i++)
	{
		printf(" Column %d Sum = %d\n", i + 1, Array[i]);
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3], Array[30];
	
	FillMatrixWithRandomNumber(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);
	SumMatrixColumnInArray(Matrix, Array, 3, 3);
	PrintArray(Array, 3);

	return 0;
}