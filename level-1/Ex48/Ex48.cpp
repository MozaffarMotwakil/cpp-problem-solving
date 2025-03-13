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

float Floor(float Number) {
    if (Number >= 0)
    {
       return int(Number);
    }
    else
    {
        if (Franction(Number) == 0)
            return Number;
        else
            return int(Number) - 1;
    }
}

int main()
{
    float Number = ReadNumber("Enter a number : ");

    cout << "\nMy Floor Function : " << Floor(Number) << endl;
    cout << "C++ floor Function : " << floor(Number) << endl;
}
