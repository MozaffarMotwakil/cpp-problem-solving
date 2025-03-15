#include <iostream>
#include "..\..\..\MyLibrary\MyInputLib.h"

using namespace std;

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short MonthToDays(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;

	if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
		return 30;
	else if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;
	else
		return 31;
}

short MonthToHours(short Year, short Month) {
    return MonthToDays(Year, Month) * 24;
}

int MonthToMinutes(short Year, short Month) {
    return MonthToHours(Year, Month) * 60;
}

int MonthToSeconds(short Year, short Month) {
    return MonthToMinutes(Year, Month) * 60;
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a Year : ");
    short Month = MyInputLib::ReadPositiveNumber("\nEnter a Month : ");

    cout << "\nNumber of Days in Month    [" << Month << "] is : " << MonthToDays(Year, Month) << endl;
    cout << "Number of Hours in Month   [" << Month << "] is : " << MonthToHours(Year, Month) << endl;
    cout << "Number of Minutes in Month [" << Month << "] is : " << MonthToMinutes(Year, Month) << endl;
    cout << "Number of Seconds in Month [" << Month << "] is : " << MonthToSeconds(Year, Month) << endl;

    return 0;
}