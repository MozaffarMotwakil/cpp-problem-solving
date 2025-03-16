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
    string MonthsName[12]{ "Jun", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Des" };
    return MonthsName[Month];
}

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short GetMonthDays(short Year, short Month) {
    short MonthsDay[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : MonthsDay[Month - 1]);
}

void DisplayMonthCalendar(short Year, short Month) {
    cout << "\n\n__________________" << GetShortMonthName(Month) << "__________________\n\n";
    cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;

    switch (ConvertDateToWeakDayNumber(Year, Month, 1))
    {
    case 0:
        cout << setw(3) << 1;
        break;
    case 1:
        cout << setw(9) << 1;
        break;
    case 2:
        cout << setw(15) << 1;
        break;
    case 3:
        cout << setw(21) << 1;
        break;
    case 4:
        cout << setw(27) << 1;
        break;
    case 5:
        cout << setw(33) << 1;
        break;
    case 6:
        cout << setw(39) << 1 << endl;
        break;
    }
    
    for (short i = 2; i <= GetMonthDays(Year, Month); i++)
    {
        switch (ConvertDateToWeakDayNumber(Year, Month, i))
        {
        case 0:
            cout << setw(3) << i;
            break;
        case 6:
            cout << setw(6) << i << endl;
            break;
        default :
            cout << setw(6) << i; 
        }
    }

    cout << "\n_______________________________________\n";
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
    short Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");

    DisplayMonthCalendar(Year, Month);
    
    return 0;
}