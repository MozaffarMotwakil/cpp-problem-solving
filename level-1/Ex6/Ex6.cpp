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

int SumNumberDigits(int Number) {
    int Remainder = 0, Sum = 0;

    while (Number != 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Sum += Remainder;
    }

    return Sum;
}


int main()
{
    int Num = ReadPositiveNumber("Enter a number : ");
    cout << "Sum of digits is : " << SumNumberDigits(Num) << endl;
}
