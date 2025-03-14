#include <iostream>
#include "..\..\..\MyLibrary\MyInputLib.h"

using namespace std;

string NumberToText(int Number) {
	string Text = "";

	if (Number == 0)
	{
		return Text;
	}

	if (Number >= 1 && Number <= 19)
	{
		string NumbersName[]{
			"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
			"Eight", "Nine" ,"Ten" , "Eleven", "Twelve", "Fourteen",
			"Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
		};

		return NumbersName[Number];
	}

	if (Number >= 20 && Number <= 99)
	{
		string TensName[]{ "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		return TensName[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number >= 100 && Number <= 199)
	{
		return "One Hundreds " + NumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999)
	{
		return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100);
	}


	if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousent " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999)
	{
		return NumberToText(Number / 1000) + " Thousents " + NumberToText(Number % 1000);
	}

	if (Number >= 1000000 && Number <= 1999999)
	{
		return "One Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 2000000 && Number <= 999999999)
	{
		return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
	}

	if (Number >= 1000000000 && Number <= 1999999999)
	{
		return "One Billion " + NumberToText(Number % 1000000000);
	}
	else
	{
		return NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000);
	}

}

int mani() {
	
	int Number = MyInputLib::ReadPositiveNumber("Enter a number : ");

	cout << NumberToText(Number) << endl;

	return 0;
}