#include <iostream>

using namespace std;

float ReadNumber(string Message) {
    float Number;

    cout << Message;
    cin >> Number;

    return Number;
}

float ABS(float Number) {
    if (Number >= 0)
        return Number;
    else
        return Number * -1;
}

int main()
{
    float Number = ReadNumber("Enter a number : ");

    cout << "\nMy ABS Function : " << ABS(Number) << endl;
    cout << "C++ ABS Function : " << abs(Number) << endl;
}
