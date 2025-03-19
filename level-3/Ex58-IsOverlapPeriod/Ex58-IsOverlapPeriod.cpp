#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};

// First Way //

bool IsOverlapPeriod(stPeriod FirstPeriod, stPeriod SecondPeriod) {
    if (MyDateUtilsLib::IsDate1EqualDate2(FirstPeriod.StartDate, SecondPeriod.StartDate) || MyDateUtilsLib::IsDate1EqualDate2(FirstPeriod.StartDate, SecondPeriod.EndDate))
        return true;
    else if (MyDateUtilsLib::IsDate1AfterDate2(FirstPeriod.StartDate, SecondPeriod.StartDate) && MyDateUtilsLib::IsDate1BeforeDate2(FirstPeriod.StartDate, SecondPeriod.EndDate))
        return true;
    else if (MyDateUtilsLib::IsDate1EqualDate2(FirstPeriod.EndDate, SecondPeriod.StartDate) || MyDateUtilsLib::IsDate1EqualDate2(FirstPeriod.EndDate, SecondPeriod.EndDate))
        return true;
    else if (MyDateUtilsLib::IsDate1AfterDate2(FirstPeriod.EndDate, SecondPeriod.StartDate) && MyDateUtilsLib::IsDate1BeforeDate2(FirstPeriod.EndDate, SecondPeriod.EndDate))
        return true;
    else
        false;
}

// Second Way //

bool IsDateOverlapWithPeriod(stDate Date, stPeriod Period) {
    short CompareWithStartDate = MyDateUtilsLib::CompareBetweenTwoDates(Date, Period.StartDate);
    short CompareWithEndtDate = MyDateUtilsLib::CompareBetweenTwoDates(Date, Period.EndDate);

    return ((CompareWithStartDate == 0 || CompareWithEndtDate == 0) || (CompareWithStartDate == 1 && CompareWithEndtDate == -1));
}

bool ArePeriodsOverlap(stPeriod FirstPeriod, stPeriod SecondPeriod) {
    return (IsDateOverlapWithPeriod(FirstPeriod.StartDate, SecondPeriod) || IsDateOverlapWithPeriod(FirstPeriod.EndDate, SecondPeriod));
}

// Mentor solution //

bool IsOverlapPeriods(stPeriod FirstPeriod, stPeriod SecondPeriod) {
    if (MyDateUtilsLib::CompareBetweenTwoDates(SecondPeriod.EndDate, FirstPeriod.StartDate) == -1 || MyDateUtilsLib::CompareBetweenTwoDates(SecondPeriod.StartDate, FirstPeriod.EndDate) == 1)
        return false;
    else
        return true;
}


// Update of Mentor solution //

bool IsOverlapPeriods(stPeriod FirstPeriod, stPeriod SecondPeriod) {
    return !(MyDateUtilsLib::CompareBetweenTwoDates(SecondPeriod.EndDate, FirstPeriod.StartDate) == -1 || MyDateUtilsLib::CompareBetweenTwoDates(SecondPeriod.StartDate, FirstPeriod.EndDate) == 1);
}


stPeriod ReadPeriod() {
    stPeriod Period;

    cout << "Enter start date :\n";
    Period.StartDate = MyInputLib::ReadDate();
    
    cout << "\nEnter end date :\n";
    Period.EndDate = MyInputLib::ReadDate();

    return Period;
}

int main()
{
    cout << "Enter the first period :\n";
    stPeriod FirstPeriod = ReadPeriod();

    cout << "\n\nEnter the second period :\n";
    stPeriod SecondPeriod = ReadPeriod();

    if (IsOverlapPeriods(FirstPeriod, SecondPeriod))
        cout << "\nYes, periods is overlap\n";
    else
        cout << "\nNo, periods is NOT overlap\n";


    system("pause > 0");

    return 0;
}