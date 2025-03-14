#include <iostream>
#include "..\..\..\MyLibrary\MyInputLib.h"

using namespace std;

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a year : ");

    if (IsLeapYear(Year))
        cout << "\nYes, year " << Year << " is leap year" << endl;
    else
        cout << "\nNo, year " << Year << " is not leap year" << endl;

    return 0;
}