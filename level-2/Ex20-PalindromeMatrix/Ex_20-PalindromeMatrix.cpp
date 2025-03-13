#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

bool IsPalindromeMatrix(int Matrix[3][3], int Rows, int Columns) {
	for (short RowNumber = 0; RowNumber < Rows; RowNumber++)
	{
		for (short ColumnNumber = 0; ColumnNumber <= Columns / 2; ColumnNumber++)
		{
			if (Matrix[RowNumber][ColumnNumber] != Matrix[RowNumber][--Columns])
			{
				return false;
			}
		}
	}

	return true;
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

	int Matrix[3][3]{
		{1, 2, 1},
		{1, 5, 1},
		{1, 2, 1}
	};

	cout << "The following are matrix elements :\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsPalindromeMatrix(Matrix, 3, 3))
	{
		cout << "\nYes, is palindrome matrix\n";
	}
	else
	{
		cout << "\nNo, is not palindrome matrix\n";
	}

	return 0;
}