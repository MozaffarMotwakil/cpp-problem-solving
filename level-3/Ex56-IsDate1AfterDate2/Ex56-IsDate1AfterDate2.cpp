#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return (!MyDateUtilsLib::IsDate1BeforeDate2(Date1, Date2) && !MyDateUtilsLib::IsDate1EqualDate2(Date1, Date2));
}

int main()
{
    cout << "Enter date #1 :\n";
    stDate Date1 = MyInputLib::ReadDate();

    cout << "\nEnter date #2 :\n";
    stDate Date2 = MyInputLib::ReadDate();

    if (IsDate1AfterDate2(Date1, Date2))
        cout << "\nYes, date1 is after date2\n";
    else
        cout << "\nNo, date1 is NOT after date2\n";

    system("pause > 0");

    return 0;
}