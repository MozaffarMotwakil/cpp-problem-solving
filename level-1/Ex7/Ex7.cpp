#include <iostream>
#include <string>

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

int ReverseNumber(int Number) {
    int Remainder = 0, NewNumber = 0;

    while (Number != 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        NewNumber = NewNumber * 10 + Remainder;
    }

    return NewNumber;
}

int main()
{
    int Num = ReadPositiveNumber("Enter a number : ");
    cout << "The reverse of a number is : " << ReverseNumber(Num) << endl;
}
