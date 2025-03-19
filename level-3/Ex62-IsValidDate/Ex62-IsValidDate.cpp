#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

bool IsValidDate(stDate Date) {
    return !(Date.Month < 1 || Date.Month > 12 || Date.Day < 1 || Date.Day > MyDateUtilsLib::GetMonthDays(Date));
}

int main()
{
    stDate Date = MyInputLib::ReadDate();

    if (IsValidDate(Date))
        cout << "\nYes, is valid date";
    else
        cout << "\nNo, is not valid date";

    return 0;
}