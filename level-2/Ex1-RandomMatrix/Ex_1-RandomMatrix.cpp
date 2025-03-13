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

int main() {
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	Fill3x3MatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "The following is 3*3 Random Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	return 0;
}