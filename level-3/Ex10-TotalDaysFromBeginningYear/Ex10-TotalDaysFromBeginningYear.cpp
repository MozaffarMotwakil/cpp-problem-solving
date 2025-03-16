#include <iostream>
#include <iomanip>
#include "..\..\MyLibrary\MyInputLib.h"

using namespace std;

short ConvertDateToWeakDayNumber(short Year, short Month, short Day) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;

    // Sunday = 0, Monday = 1, ...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetShortDayName(short Day) {
    string WeekDays[7]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return WeekDays[Day];
}

string GetShortMonthName(short Month) {
    string MonthsName[12]{ "Jun", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec" };
    return MonthsName[Month - 1];
}

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short GetMonthDays(short Year, short Month) {
    short MonthsDay[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : MonthsDay[Month - 1]);
}

short GetTotalDaysFromBeginningYear(short Year, short Month, short Day) {
    short TotalDays = 0;
    
    for (short i = 1; i <= 12; i++)
    {
        if (Month == i)
        {
            return TotalDays += Day;
        }

        TotalDays += GetMonthDays(Year, i);
    }
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    short Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
    short Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");

    cout << "\nTotal of days from beginning of year is : " << GetTotalDaysFromBeginningYear(Year, Month, Day) << endl;

    return 0;
}