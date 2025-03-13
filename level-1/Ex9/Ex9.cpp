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

bool IsDigitAvailable(int Number, int Digit) {
    int Remainder = 0;

    while (Number != 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        
        if (Digit == Remainder)
        {
            return true;
        }
    }

    // in case the digit is not available after don't found its.
    return false;
}

void PrintResult(int Number) {
    for (int i = 0; i <= 9; i++)
    {
        if (IsDigitAvailable(Number, i))
        {
            cout << "Digit " << i << " frequency is " << FrequencyDigitInNumber(Number, i) << " time(s)" << endl;
        }
    }
}

int main()
{
    int Num = ReadPositiveNumber("Enter a number : ");
    PrintResult(Num);
}