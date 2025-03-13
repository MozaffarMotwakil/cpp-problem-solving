#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Matrix[i][j] = RandomNumber(0, 1);
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			printf("%d     ", Matrix[i][j]);
		}

		cout << '\n';
	}
}

bool IsIdentityMatrix(int Matrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (i == j && Matrix[i][j] != 1)
			{
				return false;
			}
			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	
	// in case the matrix is identity 
	return true;
}

int main() {
	srand((unsigned)time(NULL));
	
	int Matrix[3][3];

	FillMatrixWithRandomNumber(Matrix, 3, 3);

	cout << "The following are matrix elements :\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsIdentityMatrix(Matrix, 3, 3))
	{
		cout << "\nYes, is identity matrix\n";
	}
	else
	{
		cout << "\nNo, is not identity matrix\n";
	}

	return 0;
}