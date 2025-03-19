#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

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
		else if (CompareStartDate)
		{
			DaysCount = MyDateUtilsLib::DiffirentBetweenTwoDates(SecondPeriod.StartDate, FirstPeriod.EndDate);
		}
		else
		{
			DaysCount = MyDateUtilsLib::DiffirentBetweenTwoDates(FirstPeriod.StartDate, SecondPeriod.EndDate);
		}
	}

	return DaysCount;
}

int main()
{
	cout << "Enter the first period :\n";
	stPeriod FirstPeriod = MyInputLib::ReadPeriod();

	cout << "\n\nEnter the second period :\n";
	stPeriod SecondPeriod = MyInputLib::ReadPeriod();

	cout << "\nOverlap period count : " << CountOverlapDays(FirstPeriod, SecondPeriod) << endl;

	return 0;
}
