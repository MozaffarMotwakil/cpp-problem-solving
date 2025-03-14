#include <iostream>
#include "..\..\..\MyLibrary\MyInputLib.h"

using namespace std;

bool IsLeapYear(short Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short YearToDays(short Year) {
    return IsLeapYear(Year) ? 366 : 365;
}

short YearToHours(short Year) {
    return YearToDays(Year) * 24;
}

int YearToMinutes(short Year) {
    return YearToHours(Year) * 60;
}

int YearToSeconds(short Year) {
    return YearToMinutes(Year) * 60;
}

int main()
{
    short Year = MyInputLib::ReadPositiveNumber("Enter a year : ");

    cout << "\nNumber of Days in Year    [" << Year << "] is : " << YearToDays(Year) << endl;
    cout << "Number of Hours in Year   [" << Year << "] is : " << YearToHours(Year) << endl;
    cout << "Number of Minutes in Year [" << Year << "] is : " << YearToMinutes(Year) << endl;
    cout << "Number of Seconds in Year [" << Year << "] is : " << YearToSeconds(Year) << endl;

    return 0;
}