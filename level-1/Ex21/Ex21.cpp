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
			cout << "Wrong number, please enter positive number." << endl;
		}

	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

string GeneratePartOfKay() {
	string Part = "";

	for (int i = 1; i <= 4; i++)
	{
		Part += char(RandomNumber(65, 90));
	}

	return Part;
}

string GenerateKay() {
	string Part1 = GeneratePartOfKay();
	string Part2 = GeneratePartOfKay();
	string Part3 = GeneratePartOfKay();
	string Part4 = GeneratePartOfKay();

	string Kay = Part1 + '-' + Part2 + '-' + Part3 + '-' + Part4;

	return Kay;
}

void PrintManyKays(int KaysCount) {
	for (int i = 1; i <= KaysCount; i++)
	{
		cout << "Kay [" << i << "] : " << GenerateKay << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int KaysCount = ReadPositiveNumber("Enter a number of kays that you want print : ");
	PrintManyKays(KaysCount);
}
