#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include "..\..\MyLibrary\MyTextUtilsLib.h"
#include <iostream>
#include <vector>

using namespace std;

stDate StringToDate(string DateInString) {
    vector<string> vDateParts = MyTextUtilsLib::Split(DateInString, "/");

    stDate Date;
    Date.Day = stoi(vDateParts[0]);
    Date.Month = stoi(vDateParts[1]);
    Date.Year = stoi(vDateParts[2]);

    return Date;
}

int main()
{
    string DateInString = MyInputLib::ReadString("Enter date dd/mm/yyyy : ");

    stDate Date = StringToDate(DateInString);

    cout << "\nDay  : " << Date.Day;
    cout << "\nMonth : " << Date.Month;
    cout << "\nYear : " << Date.Year << endl;

    cout << "\nYou entered : " << MyDateUtilsLib::DateToString(Date) << endl;

    return 0;
}