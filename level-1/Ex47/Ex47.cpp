#include <iostream>

using namespace std;

float ReadNumber(string Message) {
    float Number;

    cout << Message;
    cin >> Number;

    return Number;
}

int Round(float Number) {
    if (Number >= 0)
        return Number + 0.5;
    else
        return Number - 0.5;
}

int main()
{
    float Number = ReadNumber("Enter a number : ");

    cout << "\nMy ABS Function : " << Round(Number) << endl;
    cout << "C++ ABS Function : " << round(Number) << endl;
}
