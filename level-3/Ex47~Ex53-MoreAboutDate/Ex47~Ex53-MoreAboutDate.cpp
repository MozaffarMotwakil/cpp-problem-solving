#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include <iostream>

using namespace std;

short WeekDayOrder(stDate Date) {
    short a = (14 - Date.Month) / 12;
    short y = Date.Year - a;
    short m = Date.Month + (12 * a) - 2;

    // Sunday = 0, Monday = 1, ...etc
    return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool IsEndOfWeek(stDate Date) {
    return WeekDayOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date) {
    short DayOrder = WeekDayOrder(Date);
    return (DayOrder == 5 || DayOrder == 6);
}

bool IsBusinessDay(stDate Date) {
    return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(stDate Date) {
    return 6 - WeekDayOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date) {
    return MyDateUtilsLib::GetMonthDays(Date.Year, Date.Month) - Date.Day;
}

short DaysUntilTheEndOfYear(stDate Date) {
    return MyDateUtilsLib::GetYearDays(Date.Year) - MyDateUtilsLib::NumberOfDaysFromBeginingYear(Date);
}

int main()
{
    stDate Date = MyDateUtilsLib::GetLocalDate();

    cout << "Today is " << MyDateUtilsLib::GetShortDayName(WeekDayOrder(Date)) << " , " << MyDateUtilsLib::DateToString(Date);

    cout << "\n\nIs it end of week ?";

    if (IsEndOfWeek(Date))
        cout << "\nYes, is end of week.";
    else
        cout << "\nNo, is NOT end of week.";

    cout << "\n\nIs it week end ?";
    
    if (IsWeekEnd(Date))
        cout << "\nYes, is week end.";
    else
        cout << "\nNo, is NOT week end.";

    cout << "\n\nIs it Business day ?";

    if (IsBusinessDay(Date))
        cout << "\nYes, is business day.";
    else
        cout << "\nNo, is NOT business day.";

    cout << "\n\nDays until end of week  : " << DaysUntilTheEndOfWeek(Date);
    cout << "\nDays until end of month : " << DaysUntilTheEndOfMonth(Date);
    cout << "\nDays until end of year  : " << DaysUntilTheEndOfYear(Date);

    system("pause > 0");

    return 0;
}