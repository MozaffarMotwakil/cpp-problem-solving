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

stDate AddDaysToDay(stDate Date, short DaysToAdd) {
    for (DaysToAdd; DaysToAdd > 0; DaysToAdd--)
    {
        if (Date.Day < GetMonthDays(Date.Year, Date.Month))
        {
            Date.Day++;
        }
        else
        {
            if (Date.Month < 12)
            {
                Date.Month++;
                Date.Day = 1;
            }
            else
            {
                Date.Year++;
                Date.Month = 1;
                Date.Day = 1;
            }
        }
    }

    return Date;
}

int main()
{
    stDate Date;

    Date.Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    Date.Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
    Date.Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");

    short NumberOfDaysToAdd = MyInputLib::ReadPositiveNumber("\nHow many days you want to add ? ");

    stDate NewDate = AddDaysToDay(Date, NumberOfDaysToAdd);
    cout << "\nDate after adding [" << NumberOfDaysToAdd << "] is : " << NewDate.Day << '/' << NewDate.Month << '/' << NewDate.Year << endl;

    return 0;
}