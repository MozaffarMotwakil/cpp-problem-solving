#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

bool IsDateOverlapWithPeriod(stDate Date, stPeriod Period) {
	short CompareWithStartDate = MyDateUtilsLib::CompareBetweenTwoDates(Date, Period.StartDate);
	short CompareWithEndtDate = MyDateUtilsLib::CompareBetweenTwoDates(Date, Period.EndDate);

	return ((CompareWithStartDate == 0 || CompareWithEndtDate == 0) || (CompareWithStartDate == 1 && CompareWithEndtDate == -1));
}

bool IsDateWithinPeriod(stDate Date, stPeriod Period) {
	return !(MyDateUtilsLib::CompareBetweenTwoDates(Date, Period.StartDate) == -1 || MyDateUtilsLib::CompareBetweenTwoDates(Date, Period.EndDate) == 1);
}


int main()
{
	cout << "Enter period :\n";
	stPeriod Period = MyInputLib::ReadPeriod();

	cout << "\nEnter date to check :\n";
	stDate Date = MyInputLib::ReadDate();

	if (IsDateWithinPeriod(Date, Period))
		cout << "\nYes, date within the period\n";
	else	
		cout << "\nNo, date isn't within the period\n";

	return 0;
}