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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    if (Date1.Year != Date2.Year)
        return Date1.Year < Date2.Year;

    if (Date1.Month != Date2.Month)
        return Date1.Month < Date2.Month;

    return Date1.Day < Date2.Day;
}

bool IsLastDayInMonth(stDate Date) {
    return Date.Day == GetMonthDays(Date.Year, Date.Month);
}

bool IsLastMonthInYear(stDate Date) {
    return Date.Month == 12;
}

void IncreaseDateByOneDay(stDate& Date) {
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date))
        {
            Date.Year++;
            Date.Month = 1;
            Date.Day = 1;
        }
        else
        {
            Date.Month++;
            Date.Day = 1;
        }
    }
    else
    {
        Date.Day++;
    }
}

short DiffirentBetweenTwoDates(stDate Date1, stDate Date2, bool InclodingEndDay = false) {
    short Days = 0;

    if (IsDate1BeforeDate2(Date1, Date2))
    {
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            IncreaseDateByOneDay(Date1);
            Days++;
        }
        
        return InclodingEndDay ? Days + 1 : Days;
    }
    else
    {
        while (IsDate1BeforeDate2(Date2, Date1))
        {
            IncreaseDateByOneDay(Date2);
            Days++;
        }

        return InclodingEndDay ? (Days * -1) - 1 : Days * -1;
    }

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