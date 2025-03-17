#include <iostream>
#include "../../MyLibrary/MyInputLib.h"

using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
}

stDate ReadDate() {
    stDate Date;

    Date.Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    Date.Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
    Date.Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");
    cout << "\n\n";

    return Date;
}

int main()
{
    stDate Date1 = ReadDate();
    stDate Date2 = ReadDate();

    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\n\nYes, Date1 is equal than date2" << endl;
    else
        cout << "\n\nNo, Date1 is not equal than date2" << endl;

    return 0;
}