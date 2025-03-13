#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void FillOrderedMatrix(int Matrix[3][3], int Rows, int Columns) {
	int Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Matrix[i][j] = ++Counter;
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Columns) {
	cout << "The following are matrix elements :\n";

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << Matrix[i][j] << "     ";
		}

		cout << '\n';
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillOrderedMatrix(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	return 0;
}
