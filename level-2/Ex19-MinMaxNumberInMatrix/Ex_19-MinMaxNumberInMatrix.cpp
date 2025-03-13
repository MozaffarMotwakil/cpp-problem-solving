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

int MaxNumberInMatrix(int Matrix[3][3], int Rows, int Columns) {
	int MaxNumber = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] > MaxNumber)
			{
				MaxNumber = Matrix[i][j];
			}
		}
	}

	return MaxNumber;
}

int MinNumberInMatrix(int Matrix[3][3], int Rows, int Columns) {
	int MinNumber = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] < MinNumber)
			{
				MinNumber = Matrix[i][j];
			}
		}
	}

	return MinNumber;
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

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "The following are matrix1 elements :\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMaximum Numbers is : " << MaxNumberInMatrix(Matrix, 3, 3) << endl;
	cout << "\nMinimum Numbers is : " << MinNumberInMatrix(Matrix, 3, 3) << endl;

	return 0;
}