#include <iostream>

using namespace std;

float ReadNumber(string Message) {
    float Number;

    cout << Message;
    cin >> Number;

    return Number;
}

float Sqrt(float Number) {
    return pow(Number, 0.5);
}

int main()
{
    float Number = ReadNumber("Enter a number : ");

    cout << "\nMy Sqrt Function : " << Sqrt(Number) << endl;
    cout << "C++ sqrt Function : " << sqrt(Number) << endl;
}