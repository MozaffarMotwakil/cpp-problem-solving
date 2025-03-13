#include <iostream>
#include <cstdlib>

using namespace std;

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

bool IsScalarMatrix(int Matrix[3][3], int Rows, int Columns) {
	int FirstDiagonalNumber = Matrix[0][0];
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (i == j && Matrix[i][j] != FirstDiagonalNumber)
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

	int Matrix[3][3]{
		{5, 0, 0},
		{0, 5, 0},
		{0, 0, 5}
	};

	cout << "The following are matrix elements :\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsScalarMatrix(Matrix, 3, 3))
	{
		cout << "\nYes, is scalar matrix\n";
	}
	else
	{
		cout << "\nNo, is not scalar matrix\n";
	}

	return 0;
}