#include <iostream>
#include "..\..\..\MyLibrary\MyInputLib.h"

using namespace std;

string DigitToWord(short Digit) {
	string DigitsName[]{ "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	return DigitsName[Digit - 1];
}

string DigitToTensWord(short Digit) {
	string TensName[]{ "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	return TensName[Digit - 2];
}

string GetScaleName(short DigitPosition) {
	return DigitPosition == 4 ? "Thousents" : DigitPosition == 7 ? "Millions" : "Billions";
}

string NumberToText(int Number, short DigitPosition = 1) {
	string Text = "";

	if (Number != 0)
	{
		short Mod = Number % 10;
		Number /= 10;
		
		Text += NumberToText(Number, DigitPosition + 1) + " ";

		if (DigitPosition % 3 == 1 && DigitPosition != 1)
			Text += DigitToWord(Mod) + " " + GetScaleName(DigitPosition);
		else if (DigitPosition % 3 == 0)
			Text += DigitToWord(Mod) + " " + "Handerits";
		else if (DigitPosition % 3 == 2)
			Text += DigitToTensWord(Mod);
		else
			Text += DigitToWord(Mod);

	}

	return Text;
}

int main() {
	int Number = MyInputLib::ReadPositiveNumber("Enter a number : ");

	cout << NumberToText(Number) << endl;

	return 0;
}