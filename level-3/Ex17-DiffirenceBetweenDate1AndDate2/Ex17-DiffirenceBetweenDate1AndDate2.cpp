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
    short MonthsDay[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : MonthsDay[Month - 1]);
}

short NumberOfDaysFromBeginingYear(stDate Date) {
    short TotalOfDays = 0;

    for (short Month = 1; Month <= Date.Month - 1; Month++)
    {
        TotalOfDays += GetMonthDays(Date.Year, Month);
    }

    return TotalOfDays += Date.Day;
}

short DiffirentBetweenTwoDates(stDate Date1, stDate Date2, bool InclodingEndDay = false) {
    short TotalOfDiffirentDays = NumberOfDaysFromBeginingYear(Date2) - NumberOfDaysFromBeginingYear(Date1);
    return InclodingEndDay ? TotalOfDiffirentDays + 1 : TotalOfDiffirentDays;
}

int main()
{
    cout << "The First Date :\n";
    stDate Date1 = ReadDate();

    cout << "\nThe Second Date :\n";
    stDate Date2 = ReadDate();

    cout << "Difference is : " << DiffirentBetweenTwoDates(Date1, Date2) << " Day(s)" << endl;
    cout << "Difference (Including End Day) is : " << DiffirentBetweenTwoDates(Date1, Date2, true) << " Day(s)" << endl;

    return 0;
}