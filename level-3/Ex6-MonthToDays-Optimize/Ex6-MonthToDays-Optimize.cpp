#include <iostream>
#include "..\..\..\MyLibrary\MyInputLib.h"

using namespace std;

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short MonthToDays(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;

    int MonthDaysCount[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : MonthDaysCount[Month - 1]);
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a Year : ");
    short Month = MyInputLib::ReadPositiveNumber("\nEnter a Month : ");

    cout << "\nNumber of Days in Month [" << Month << "] is : " << MonthToDays(Year, Month) << endl;

    return 0;
}