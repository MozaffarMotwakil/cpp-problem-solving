#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

stDate IncreaseDateByXDays(stDate Date, int DaysToAdd) {
    int RemaindingDays = DaysToAdd + MyDateUtilsLib::NumberOfDaysFromBeginingYear(Date);
	short MonthDays = MyDateUtilsLib::GetMonthDays(Date.Year, Date.Month);

	Date.Month = 1;
	Date.Day = 1;

	while (true)
	{
		MonthDays = MyDateUtilsLib::GetMonthDays(Date.Year, Date.Month);

		if (RemaindingDays > MonthDays)
		{
			RemaindingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Year++;
				Date.Month = 1;
			}

		}
		else
		{
			Date.Day = RemaindingDays;
			break;
		}
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {
	short MonthDays = MyDateUtilsLib::GetMonthDays(Date.Year, Date.Month);

	if (Date.Day <= MonthDays - 7)
	{
		Date.Day += 7;
	}
	else
	{
		if (MyDateUtilsLib::IsLastMonthInYear(Date))
		{
			Date.Year++;
			Date.Month = 1;
			Date.Day = (7 - (MonthDays - Date.Day));
		}
		else
		{
			Date.Month++;
			Date.Day = (7 - (MonthDays - Date.Day));
		}
	}

	return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, int WeeksToAdd) {
	for (int i = 1; i <= WeeksToAdd; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {
	if (MyDateUtilsLib::IsLastMonthInYear(Date))
	{
		Date.Year++;
		Date.Month = 1;
	}
	else
	{
		Date.Month++;
	}

	short MonthDays = MyDateUtilsLib::GetMonthDays(Date.Year, Date.Month);

	if (Date.Day > MonthDays)
	{
		Date.Day = MonthDays;
	}

	return Date;
}

stDate IncreaseDateByXMonths(stDate Date, int MonthsToAdd) {
	for (short i = 1; i <= MonthsToAdd ; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYears(stDate Date, int YearsToAdd) {
	for (int i = 1; i <= YearsToAdd; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, int YearsToAdd) {
	Date.Year += YearsToAdd;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecades(stDate Date, int DecodesToAdd) {
	for (int i = 1; i <= DecodesToAdd; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, int DecodesToAdd) {
	Date.Year += 10 * DecodesToAdd;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMellennium(stDate Date) {
	Date.Year += 1000;
	return Date;
}

string DateToString(stDate Date) {
	return to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year);
}

int main()
{
	stDate Date = MyInputLib::ReadDate();
	
	cout << "\nDate after :\n";

	Date = MyDateUtilsLib::IncreaseDateByOneDay(Date);
	cout << "\n01- Adding one day is : " << DateToString(Date);
	
	Date = IncreaseDateByXDays(Date, 10);
	cout << "\n02- Adding 10 days is : " << DateToString(Date);

	Date = IncreaseDateByOneWeek(Date);
	cout << "\n03- Adding one week is : " << DateToString(Date);

	Date = IncreaseDateByXWeeks(Date, 10);
	cout << "\n04- Adding 10 weeks is : " << DateToString(Date);

	Date = IncreaseDateByOneMonth(Date);
	cout << "\n05- Adding one month is : " << DateToString(Date);

	Date = IncreaseDateByXMonths(Date, 5);
	cout << "\n06- Adding 5 months is  : " << DateToString(Date);

	Date = IncreaseDateByOneYear(Date);
	cout << "\n07- Adding one year is : " << DateToString(Date);

	Date = IncreaseDateByXYears(Date, 10);
	cout << "\n08- Adding 10 years is : " << DateToString(Date);

	Date = IncreaseDateByXYearsFaster(Date, 10);
	cout << "\n09- Adding 10 years (faster) is : " << DateToString(Date);

	Date = IncreaseDateByOneDecade(Date);
	cout << "\n10- Adding one decade is : " << DateToString(Date);

	Date = IncreaseDateByXDecades(Date, 10);
	cout << "\n11- Adding 10 decades is : " << DateToString(Date);

	Date = IncreaseDateByXDecadesFaster(Date, 10);
	cout << "\n12- Adding 10 decades (faster) is : " << DateToString(Date);

	Date = IncreaseDateByOneCentury(Date);
	cout << "\n13- Adding one century is : " << DateToString(Date);

	Date = IncreaseDateByOneMellennium(Date);
	cout << "\n14- Adding one mellennium is : " << DateToString(Date);

	system("pause > 0");

	return 0;
}