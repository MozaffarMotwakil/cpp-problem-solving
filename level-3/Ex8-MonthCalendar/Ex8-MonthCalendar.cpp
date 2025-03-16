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

void DisplayMonthCalendar(short Year, short Month) {
    short MonthDayCount = GetMonthDays(Year, Month);
    short FirstDayOrderInWeek = ConvertDateToWeakDayNumber(Year, Month, 1);

    printf("\n  _______________%s_______________\n\n", GetShortMonthName(Month).c_str());
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    short i;

    for (i = 0; i < FirstDayOrderInWeek; i++)
    {
        cout << "     ";
    }

    for (short Day = 1; Day <= MonthDayCount; Day++)
    {
        printf("%5d", Day);

        if (++i == 7)
        {
            i = 0;
            cout << endl;
        }

    }
   
    cout << "\n  _________________________________\n";
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    short Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");

    DisplayMonthCalendar(Year, Month);
    
    return 0;
}