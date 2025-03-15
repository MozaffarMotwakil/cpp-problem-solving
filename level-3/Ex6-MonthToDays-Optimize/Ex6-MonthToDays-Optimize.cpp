#include <iostream>
#include "..\..\..\MyLibrary\MyInputLib.h"

using namespace std;

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short MonthToDays(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;

    return (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30
           : Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : 31;
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a Year : ");
    short Month = MyInputLib::ReadPositiveNumber("\nEnter a Month : ");

    cout << "\nNumber of Days in Month [" << Month << "] is : " << MonthToDays(Year, Month) << endl;

    return 0;
}