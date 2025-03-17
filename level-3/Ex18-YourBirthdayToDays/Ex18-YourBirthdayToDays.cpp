#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "../../MyLibrary/MyInputLib.h"

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

short BirthdayToDays(stDate BirthdayDate) {
    time_t Time = time(0);
    tm* LocalTime = localtime(&Time);

    stDate LocalDate;
    LocalDate.Year = LocalTime->tm_year + 1900;
    LocalDate.Month = LocalTime->tm_mon + 1;
    LocalDate.Day = LocalTime->tm_mday;

    return DiffirentBetweenTwoDates(BirthdayDate, LocalDate, true);
}

int main()
{
    cout << "Enter Your Birthday date :\n";
    stDate BirthdayDate = ReadDate();

    cout << "\nYour Age is : " << BirthdayToDays(BirthdayDate) << " day(s)" << endl;
    return 0;
}