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

void IncreaseDateByOneDay(stDate& Date) {
    if (IsLastMonthInYear(Date) && IsLastDayInMonth(Date))
    {
        Date.Year++;
        Date.Month = 1;
        Date.Day = 1;
    }
    else if (IsLastDayInMonth(Date))
    {
        Date.Month++;
        Date.Day = 1;
    }
    else
    {
        Date.Day++;
    }
}

int main()
{
    stDate Date = ReadDate();

    IncreaseDateByOneDay(Date);

    cout << "\nDate after adding one day : " << Date.Day << '/' << Date.Month << '/' << Date.Year << endl;

    return 0;
}