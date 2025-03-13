#include <iostream>

using namespace std;


int ReadPositiveNumber(string Message) {
    int Num = 0;

    do
    {
        cout << Message;
        cin >> Num;

        if (Num < 0)
        {
            cout << "Wrong number, please enter a positive number.\n";
        }

    } while (Num < 0);

    return Num;
}

void PrintNumberDigits(int Number) {
    int Remainder = 0;

	while (Number != 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		cout << Remainder << endl;
	}
}


int main()
{
    int Num = ReadPositiveNumber("Enter a number : ");
    PrintNumberDigits(Num);
}
