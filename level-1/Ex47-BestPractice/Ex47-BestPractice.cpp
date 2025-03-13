#include <iostream>

using namespace std;

float ReadNumber(string Message) {
    float Number;

    cout << Message;
    cin >> Number;

    return Number;
}

float Franction(float Number) {
    return Number - int(Number);
}

int Round(float Number) {
    int IntegerPart = int(Number);
    float FranctionPart = Franction(Number);

    if (abs(FranctionPart) >= .5)
    {
        if (Number >= 0)
            return ++IntegerPart;
        else
            return --IntegerPart;
    }
    else
    {
        return IntegerPart;
    }
}

int main()
{
    float Number = ReadNumber("Enter a number : ");

    cout << "\nMy ABS Function : " << Round(Number) << endl;
    cout << "C++ ABS Function : " << round(Number) << endl;
}
