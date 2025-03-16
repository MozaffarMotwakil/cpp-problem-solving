#include <iostream>
#include <iomanip>
#include <string>
#include "..\..\MyLibrary\MyInputLib.h"

using namespace std;

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short GetMonthDays(short Year, short Month) {
    short MonthsDay[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : MonthsDay[Month - 1]);
}

short GetTotalDaysFromBeginningYear(short Year, short Month, short Day) {
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += GetMonthDays(Year, i);
    }

    return TotalDays += Day;
}

string DayNumberInYearToDate(short Year, short DayNumberInYear) {
    short MonthDays = 0;
    short Month = 1;

    while (DayNumberInYear > (MonthDays = GetMonthDays(Year, Month)))
    {
        DayNumberInYear -= MonthDays;
        Month++;
    }

    return to_string(DayNumberInYear) + '/' + to_string(Month) + '/' + to_string(Year);
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    short Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
    short Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");

    short DayNumberInYear = GetTotalDaysFromBeginningYear(Year, Month, Day);

    cout << "\nThe day number from beginning of year is : " << DayNumberInYear << endl;
    cout << "\nDate for [" << DayNumberInYear << "] is : " << DayNumberInYearToDate(Year, DayNumberInYear) << endl;

    return 0;
}