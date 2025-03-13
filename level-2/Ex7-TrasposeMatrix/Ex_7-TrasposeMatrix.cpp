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
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << Matrix[i][j] << "     ";
		}

		cout << '\n';
	}
}

void TrasposeMatrix(int Matrix[3][3], int TrasposeMatrix[3][3], int Rows, int Columns) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			TrasposeMatrix[i][j] = Matrix[j][i];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3], arrTrasposeMatrix[3][3];

	FillOrderedMatrix(Matrix, 3, 3);

	cout << "The following are matrix elements :\n";
	PrintMatrix(Matrix, 3, 3);
	
	TrasposeMatrix(Matrix, arrTrasposeMatrix, 3, 3);

	cout << "The following are matrix traspose elements :\n";
	PrintMatrix(arrTrasposeMatrix, 3, 3);

	return 0;
}