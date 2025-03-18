#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

stDate VacationEndDate(stDate VacationStart, short VacationPeriod) {
	stDate VacationEnd = VacationStart;
	
	do
	{
		if (MyDateUtilsLib::IsBusinessDay(VacationEnd))
		{
			VacationPeriod--;
		}

		VacationEnd = MyDateUtilsLib::IncreaseDateByOneDay(VacationEnd);

	} while (VacationPeriod != 0 || MyDateUtilsLib::IsWeekEnd(VacationEnd));

	return VacationEnd;
}

int main()
{
	stDate VacationStart = MyInputLib::ReadDate();

	short VacationPeriod = MyInputLib::ReadPositiveNumber("\nEnter the vacation period : ");

	cout << "\nVacation end in : " << MyDateUtilsLib::DateToString(VacationEndDate(VacationStart, VacationPeriod), true) << endl;

	system("pause > 0");

	return 0;
}