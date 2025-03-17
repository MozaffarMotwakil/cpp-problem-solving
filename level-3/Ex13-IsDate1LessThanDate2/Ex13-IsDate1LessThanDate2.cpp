#include <iostream>
#include "../../MyLibrary/MyInputLib.h"

using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    if (Date1.Year != Date2.Year)
        return Date1.Year < Date2.Year;

    if (Date1.Month != Date2.Month)
        return Date1.Month < Date2.Month;

    return Date1.Day < Date2.Day;

    /* return ((Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
              (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day)); */
}

stDate ReadDate() {
    stDate Date;

    Date.Year = MyInputLib::ReadPositiveNumber("\nEnter a year : ");
    Date.Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
    Date.Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");

    return Date;
}

int main()
{
    stDate Date1 = ReadDate();
    stDate Date2 = ReadDate();

    if (IsDate1BeforeDate2(Date1, Date2))
        cout << "\n\nYes, Date1 is less than date2" << endl;
    else
        cout << "\n\nNo, Date1 is not less than date2" << endl;

    return 0;
}