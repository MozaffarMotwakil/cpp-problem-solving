#include <iostream>

using namespace std;

void PrintFibonacciSeries(int Number) {
	int Element1 = 0, Element2 = 1, FibonacciNumber;

	for (short i = 2; i <= Number; i++)
	{
		FibonacciNumber = Element1 + Element2;
		
		cout << FibonacciNumber << " ";

		Element1 = Element2;
		Element2 = FibonacciNumber;
	}
}

int main()
{
	cout << "Fibonacci Series :\n";
	PrintFibonacciSeries(15);
	
	system("pause > 0");
}