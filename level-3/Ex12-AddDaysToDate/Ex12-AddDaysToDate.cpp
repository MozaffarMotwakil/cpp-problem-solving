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

short NumberOfDaysFromBeginingYear(stDate Date) {
    short NumberOfDay = 0;

    for (short Month = 1; Month <= Date.Month - 1; Month++)
    {
        NumberOfDay += GetMonthDays(Date.Year, Month);
    }
    
    return NumberOfDay += Date.Day;
}


stDate AddDaysToDate(stDate Date, short DaysToAdd) {
    short RemainingDays = DaysToAdd + NumberOfDaysFromBeginingYear(Date);
    Date.Month = 1;

    while (true)
    {
        short MonthDays = GetMonthDays(Date.Year, Date.Month);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Year++;
                Date.Month = 1;
            }

        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    
    return Date;
}

stDate ReadDate() {
    stDate Date;

    Date.Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    Date.Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
    Date.Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");

    return Date;
}

int main()
{
    stDate Date = ReadDate();
    
    short NumberOfDaysToAdd = MyInputLib::ReadPositiveNumber("\nHow many days you want to add ? ");

    Date = AddDaysToDate(Date, NumberOfDaysToAdd);
    cout << "\nDate after adding [" << NumberOfDaysToAdd << "] is : " << Date.Day << '/' << Date.Month << '/' << Date.Year << endl;

    return 0;
}