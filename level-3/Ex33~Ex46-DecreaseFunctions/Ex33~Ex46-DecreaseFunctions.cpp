#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

stDate DecreaseDateByOneDay(stDate Date) {
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Year--;
			Date.Month = 12;
			Date.Day = 31;
		}
		else
		{
			Date.Month--;
			Date.Day = MyDateUtilsLib::GetMonthDays(Date.Year, Date.Month);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

stDate DecreaseDateByXDays(stDate Date, int Days) {
	for (int i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date) {
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByXWeeks(stDate Date, int Weeks) {
	for (int i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date) {
	if (Date.Month == 1)
	{
		Date.Year--;
		Date.Month = 12;
	}
	else
	{
		Date.Month--;
	}

	short MonthDays = MyDateUtilsLib::GetMonthDays(Date.Year, Date.Month);

	if (Date.Day > MonthDays)
	{
		Date.Day = MonthDays;
	}

	return Date;
}

stDate DecreaseDateByXMonths(stDate Date, int Months) {
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate DecreaseDateByOneYear(stDate Date) {
	Date.Year--;
	return Date;
}

stDate DecreaseDateByXYears(stDate Date, int Years) {
	for (int i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, int Years) {
	Date.Year -= Years;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) {
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecades(stDate Date, int Decodes) {
	for (int i = 1; i <= Decodes; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}

	return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, int Decodes) {
	Date.Year -= 10 * Decodes;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date) {
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMellennium(stDate Date) {
	Date.Year -= 1000;
	return Date;
}

string DateToString(stDate Date) {
	return to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year);
}

int main()
{
	stDate Date = MyInputLib::ReadDate();

	cout << "\nDate after :\n";

	Date = DecreaseDateByOneDay(Date);
	cout << "\n01- Subtracting one day is : " << DateToString(Date);

	Date = DecreaseDateByXDays(Date, 10);
	cout << "\n02- Subtracting 10 days is : " << DateToString(Date);

	Date = DecreaseDateByOneWeek(Date);
	cout << "\n03- Subtracting one week is : " << DateToString(Date);

	Date = DecreaseDateByXWeeks(Date, 10);
	cout << "\n04- Subtracting 10 weeks is : " << DateToString(Date);

	Date = DecreaseDateByOneMonth(Date);
	cout << "\n05- Subtracting one month is : " << DateToString(Date);

	Date = DecreaseDateByXMonths(Date, 5);
	cout << "\n06- Subtracting 5 months is  : " << DateToString(Date);

	Date = DecreaseDateByOneYear(Date);
	cout << "\n07- Subtracting one year is : " << DateToString(Date);

	Date = DecreaseDateByXYears(Date, 10);
	cout << "\n08- Subtracting 10 years is : " << DateToString(Date);

	Date = DecreaseDateByXYearsFaster(Date, 10);
	cout << "\n09- Subtracting 10 years (faster) is : " << DateToString(Date);

	Date = DecreaseDateByOneDecade(Date);
	cout << "\n10- Subtracting one decade is : " << DateToString(Date);

	Date = DecreaseDateByXDecades(Date, 10);
	cout << "\n11- Subtracting 10 decades is : " << DateToString(Date);

	Date = DecreaseDateByXDecadesFaster(Date, 10);
	cout << "\n12- Subtracting 10 decades (faster) is : " << DateToString(Date);

	Date = DecreaseDateByOneCentury(Date);
	cout << "\n13- Subtracting one century is : " << DateToString(Date);

	Date = DecreaseDateByOneMellennium(Date);
	cout << "\n14- Subtracting one mellennium is : " << DateToString(Date);

	system("pause > 0");

	return 0;
}