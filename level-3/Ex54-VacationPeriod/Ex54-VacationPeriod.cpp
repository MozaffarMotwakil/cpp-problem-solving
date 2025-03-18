#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

short ActualVacationDays(stDate VacationStart, stDate VacationEnd) {
	short TotalVacationDays = 0;

	while (MyDateUtilsLib::IsDate1BeforeDate2(VacationStart, VacationEnd))
	{
		if (!MyDateUtilsLib::IsBusinessDay(VacationStart))
		{
			TotalVacationDays++;
		}

		VacationStart = MyDateUtilsLib::IncreaseDateByOneDay(VacationStart);
	}

	return TotalVacationDays;
}

int main()
{
	cout << "Vacation starts :\n";
	stDate VacationStart = MyInputLib::ReadDate();

	cout << "\nVacation ends :\n";
	stDate VacationEnd = MyInputLib::ReadDate();

	cout << "\nVacation From : " << MyDateUtilsLib::DateToString(VacationStart, true);
	cout << "\nVacation To : " << MyDateUtilsLib::DateToString(VacationEnd, true);

	cout << "\nActual vacation date is : " << ActualVacationDays(VacationStart, VacationEnd) << endl;

	system("pause > 0");

	return 0;
}