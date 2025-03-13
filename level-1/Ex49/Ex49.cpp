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

float Ceil(float Number) {
    if (Number >= 0)
    {
        if (Franction(Number) == 0)
            return Number;
        else
            return int(Number) + 1;
    }
    else
    {
        return int(Number);
    }
}

int main()
{
    float Number = ReadNumber("Enter a number : ");

    cout << "\nMy Floor Function : " << Ceil(Number) << endl;
    cout << "C++ floor Function : " << ceil(Number) << endl;
}