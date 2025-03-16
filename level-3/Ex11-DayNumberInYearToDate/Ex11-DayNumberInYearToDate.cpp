#include <iostream>
#include <iomanip>
#include <string>
#include "..\..\MyLibrary\MyInputLib.h"

using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

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

stDate ConvertDayOrderToDate(short Year, short DayNumberInYear) {
    short RemaindingDays = DayNumberInYear;
    stDate Date;
    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        short MonthDays = GetMonthDays(Year, Date.Month);

        if (RemaindingDays > MonthDays)
        {
            RemaindingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemaindingDays;
            break;
        }
    }
    
    return Date;
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    short Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
    short Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");

    short DayOrder = GetTotalDaysFromBeginningYear(Year, Month, Day);
    cout << "\nThe day number from beginning of year is : " << DayOrder << endl;

    stDate Date = ConvertDayOrderToDate(Year, DayOrder);
    cout << "\nDate for [" << DayOrder << "] is : " << Date.Day << '/' << Date.Month << '/' << Date.Year << endl;

    return 0;
}