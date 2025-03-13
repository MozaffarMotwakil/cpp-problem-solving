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

int FrequencyDigitInNumber(int Number, int Digit) {
    int Remainder = 0, FrequancyCount = 0;

    while (Number != 0)
    {
        Remainder = Number % 10;
        Number /= 10;

        if (Digit == Remainder)
        {
            FrequancyCount++;
        }
    }

    return FrequancyCount;
}

int main()
{
    int Num = ReadPositiveNumber("Enter a number : ");
    int Digit = ReadPositiveNumber("Enter a digit : ");
    cout << "Digit " << Digit << " frequency is " << FrequencyDigitInNumber(Num, Digit) << " time(s)" << endl;
}
