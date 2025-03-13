#include <iostream>
#include <cstdlib>

using namespace std;

int ReadPositiveNumber(string Message) {
	int Number = 0;

	do
	{
		cout << Message;
		cin >> Number;

		if (Number < 0)
		{
			cout << "Wrong number, please enter a positive number.\n";
		}
	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void ReadOrderedArray(int Array[100], int& Length) {
	Length = ReadPositiveNumber("Enter a length of the arrray : ");

	for (int i = 0; i < Length; i++)
	{
		Array[i] = i + 1;
	}
}

void PrintAraay(int Array[100], int Length) {
	for (int i = 0; i < Length; i++)
	{
		cout << Array[i] << " ";
	}

	cout << endl;
}

void Swap(int& N1, int& N2) {
	int Temp;

	Temp = N1;
	N1 = N2;
	N2 = Temp;
}

void ShuffleArray(int Array[100], int Length) {

	for (int i = 0; i < Length; i++)
	{
		Swap(Array[RandomNumber(0, Length - 1)], Array[RandomNumber(0, Length - 1)]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100], Length;

	ReadOrderedArray(Array, Length);

	cout << "Array elements before shuffle : ";
	PrintAraay(Array, Length);

	ShuffleArray(Array, Length);

	cout << "Array elements after shuffle : ";
	PrintAraay(Array, Length);
}