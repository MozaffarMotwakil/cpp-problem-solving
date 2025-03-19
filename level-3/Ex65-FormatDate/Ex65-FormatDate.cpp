#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include "..\..\MyLibrary\MyTextUtilsLib.h"
#include <iostream>
#include <vector>

using namespace std;

string FormatDate(stDate Date, string Format = "dd/mm/yyyy") {
	Format = MyTextUtilsLib::Replce(Format, "dd", to_string(Date.Day));
	Format = MyTextUtilsLib::Replce(Format, "mm", to_string(Date.Month));
	Format = MyTextUtilsLib::Replce(Format, "yyyy", to_string(Date.Year));

	return Format;
}

int main()
{
	string DateInString = MyInputLib::ReadString("Enter the date by this format -> dd/mm/yyyy : ");
	
	stDate Date;

	Date = MyDateUtilsLib::StringToDate(DateInString);

	cout << "\n" << FormatDate(Date) << "\n";

	cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
	
	cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
	
	cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
	
	cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";
	
	cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";

	cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

	return 0;
}