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

bool IsPerfectNumber(int Number) {
    int Sum = 0;

    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum += i;
        }
    }

    return Number == Sum;
}

void PrintResult(int Number) {
    if (IsPerfectNumber(Number))
        cout << Number << " is prefect number" << endl;
    else
        cout << Number << " is not prefect number" << endl;
}

int main()
{
    int Num = ReadPositiveNumber("Enter a positive number : ");
    PrintResult(Num);
}
