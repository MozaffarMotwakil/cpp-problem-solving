#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <ctime>
#include "..\MyLibrary\StructGroup.cpp"

using namespace std;

namespace MyDateUtilsLib {
	
	bool IsLeapYear(short Year) {
		return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
	}

	short GetMonthDays(short Year, short Month) {
		short MonthsDay[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : MonthsDay[Month - 1]);
	}

	bool IsLastDayInMonth(stDate Date) {
		return Date.Day == GetMonthDays(Date.Year, Date.Month);
	}

	bool IsLastMonthInYear(stDate Date) {
		return Date.Month == 12;
	}

	stDate IncreaseDateByOneDay(stDate Date) {
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date))
			{
				Date.Year++;
				Date.Month = 1;
				Date.Day = 1;
			}
			else
			{
				Date.Month++;
				Date.Day = 1;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}

	stDate GetLocalDate() {
		time_t Time = time(0);
		tm* LocalTime = localtime(&Time);

		stDate LocalDate;
		LocalDate.Year = LocalTime->tm_year + 1900;
		LocalDate.Month = LocalTime->tm_mon + 1;
		LocalDate.Day = LocalTime->tm_mday;

		return LocalDate;
	}

    short ConvertDateToWeakDayNumber(short Year, short Month, short Day) {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;

        // Sunday = 0, Monday = 1, ...etc
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    string GetDayName(short Day) {
        string WeekDays[7]{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        return WeekDays[Day];
    }

	string GetShortDayName(short Day) {
		string WeekDays[7]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return WeekDays[Day];
	}

	string GetShortMonthName(short Month) {
		string MonthsName[12]{ "Jun", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec" };
		return MonthsName[Month - 1];
	}

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
		if (Date1.Year != Date2.Year)
			return Date1.Year < Date2.Year;

		if (Date1.Month != Date2.Month)
			return Date1.Month < Date2.Month;

		return Date1.Day < Date2.Day;
	}

	short DiffirentBetweenTwoDates(stDate Date1, stDate Date2, bool InclodingEndDay = false) {
		short Days = 0;

		if (IsDate1BeforeDate2(Date1, Date2))
		{
			while (IsDate1BeforeDate2(Date1, Date2))
			{
				IncreaseDateByOneDay(Date1);
				Days++;
			}

			return InclodingEndDay ? Days + 1 : Days;
		}
		else
		{
			while (IsDate1BeforeDate2(Date2, Date1))
			{
				IncreaseDateByOneDay(Date2);
				Days++;
			}

			return InclodingEndDay ? (Days * -1) - 1 : Days * -1;
		}

	}

	short NumberOfDaysFromBeginingYear(stDate Date) {
		short NumberOfDays = 0;

		for (short Month = 1; Month <= Date.Month - 1; Month++)
		{
			NumberOfDays += GetMonthDays(Date.Year, Month);
		}

		return NumberOfDays += Date.Day;
	}

	stDate AddDaysToDate(stDate Date, short DaysToAdd) {
		short RemainingDays = DaysToAdd + NumberOfDaysFromBeginingYear(Date);
		Date.Month = 1;

		while (true)
		{
			short MonthDays = GetMonthDays(Date.Year, Date.Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12)
				{
					Date.Year++;
					Date.Month = 1;
				}

			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

}