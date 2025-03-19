#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

// First way //

short CountOverlapDays(stPeriod FirstPeriod, stPeriod SecondPeriod) {
    short DaysCount = 0;

	if (MyDateUtilsLib::IsOverlapPeriods(FirstPeriod, SecondPeriod))
	{
		bool StartInsideFirst = MyDateUtilsLib::IsDateWithinPeriod(SecondPeriod.StartDate, FirstPeriod);
		bool EndInsideFirst = MyDateUtilsLib::IsDateWithinPeriod(SecondPeriod.EndDate, FirstPeriod);

		if (StartInsideFirst && EndInsideFirst)
		{
			DaysCount = MyDateUtilsLib::PeriodLength(SecondPeriod);
		}
		else if (StartInsideFirst)
		{
			DaysCount = MyDateUtilsLib::DifferenceBetweenTwoDates(SecondPeriod.StartDate, FirstPeriod.EndDate);
		}
		else
		{
			DaysCount = MyDateUtilsLib::DifferenceBetweenTwoDates(FirstPeriod.StartDate, SecondPeriod.EndDate);
		}
	}

	return DaysCount;
}

// Second way //

stDate GetLargestDate(stDate FirstDate, stDate SecondDate) {
	return (MyDateUtilsLib::CompareBetweenTwoDates(FirstDate, SecondDate) == 1 ? FirstDate : SecondDate);
}

stDate GetSmallestDate(stDate FirstDate, stDate SecondDate) {
	return (MyDateUtilsLib::CompareBetweenTwoDates(FirstDate, SecondDate) == -1 ? SecondDate : FirstDate);
}

short OverlapDays(stPeriod FirstPeriod, stPeriod SecondPeriod) {
	if (MyDateUtilsLib::IsOverlapPeriods(FirstPeriod, SecondPeriod))
	{
		stPeriod NewPeriod;
		NewPeriod.StartDate = GetLargestDate(FirstPeriod.StartDate, SecondPeriod.StartDate);
		NewPeriod.EndDate = GetSmallestDate(FirstPeriod.EndDate, SecondPeriod.EndDate);
		return MyDateUtilsLib::PeriodLength(NewPeriod);
	}

	return 0;
}

int main()
{
	cout << "Enter the first period :\n";
	stPeriod FirstPeriod = MyInputLib::ReadPeriod();

	cout << "\n\nEnter the second period :\n";
	stPeriod SecondPeriod = MyInputLib::ReadPeriod();

	cout << "\nOverlap period count : " << OverlapDays(FirstPeriod, SecondPeriod) << endl;

	return 0;
}
