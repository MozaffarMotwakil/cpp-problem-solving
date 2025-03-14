#include <iostream>
#include "..\..\..\MyLibrary\MyInputLib.h"

using namespace std;

bool IsLeapYear(short Year) {
    return Year % 400 == 0 ? true : (Year % 4 == 0 && Year % 100 != 0);
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    
    if (IsLeapYear(Year))
        printf("\nYes, year %d is leap year", Year);
    else
        printf("\nNo, year %d is not leap year", Year);

    return 0;
}