#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

enum enDateCompare { After = 1, Equal = 0, Before = -1 };

short CompareBetweenTwoDates(stDate Date1, stDate Date2) {
    if (MyDateUtilsLib::IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (MyDateUtilsLib::IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

int main()
{
    cout << "Enter date #1 :\n";
    stDate Date1 = MyInputLib::ReadDate();

    cout << "\nEnter date #2 :\n";
    stDate Date2 = MyInputLib::ReadDate();

    cout << "\nCompare result is : " << CompareBetweenTwoDates(Date1, Date2) << endl;

    system("pause > 0");

    return 0;
}