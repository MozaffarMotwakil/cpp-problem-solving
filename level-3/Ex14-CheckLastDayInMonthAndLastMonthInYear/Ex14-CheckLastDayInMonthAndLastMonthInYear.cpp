#include <iostream>
#include "../../MyLibrary/MyInputLib.h"

struct stDate {
    short Year;
    short Month;
    short Day;
};

stDate ReadDate() {
    stDate Date;

    Date.Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    Date.Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
    Date.Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");

    return Date;
}

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short GetMonthDays(short Year, short Month) {
    short MonthsDays[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : MonthsDays[Month - 1]);
}

bool IsLastDayInMonth(stDate Date) {
    return Date.Day == GetMonthDays(Date.Year, Date.Month);
}

bool IsLastMonthInYear(stDate Date) {
    return Date.Month == 12;
}

int main()
{
    stDate Date = ReadDate();

    if (IsLastDayInMonth(Date))
        cout << "\nYes, Day is last day in month" << endl;
    else    
        cout << "\nNo, Day is NOT last day in month" << endl;

    if (IsLastMonthInYear(Date))
        cout << "\nYes, Month is last month in year" << endl;
    else
        cout << "\nNo, Month is NOT last month in year" << endl;

    return 0;
}