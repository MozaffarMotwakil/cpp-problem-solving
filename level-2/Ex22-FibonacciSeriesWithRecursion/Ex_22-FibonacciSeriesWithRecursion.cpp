#include <iostream>

using namespace std;


void PrintFibonacciSeries(int Number, int N1, int N2) {
	int FibNum = 0;

	if (Number > 0)
	{
		FibNum = N1 + N2;

		cout << FibNum << " ";

		N1 = N2;
		N2 = FibNum;

		PrintFibonacciSeries(Number - 1, N1, N2);
	}
}

int main()
{
	//int Num = 10, N1 = 0, N2 = 1, FN = 0;

	cout << "Fibonacci Series :\n";
	PrintFibonacciSeries(10, 0, 1);

	system("pause > 0");
}