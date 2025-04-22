#pragma once

#include "..\MyLibrary\StructGroup.h"
#include "MyValidationLib.h"
#include <iostream>
#include <string>

using namespace std;

namespace MyInputLib {

	char ReadChar(string Message) {
		char Char;

		cout << Message;
		cin >> Char;

		return Char;
	}

	string ReadString(string Message, bool CleanBuffer = false) {
		string Text;

		cout << Message;
		getline((CleanBuffer ? cin >> ws : cin), Text);

		return Text;
	}

	template<typename T> T ReadNumber(string Message) {
		T Number = 0;

		cout << Message;
		cin >> Number;

		while (!MyValidationLib::IsNumber(cin))
		{
			cout << "Wrong input, please enter only a number." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;
			cin >> Number;
		}

		return Number;
	}

	template<typename T> T ReadPositiveNumber(string Message) {
		T Number = 0;

		do
		{
			Number = ReadNumber(Message);

			if (!MyValidationLib::IsPositiveNumber(Number))
				cout << "Wrong number, please enter a positive number." << endl;

		} while (!MyValidationLib::IsPositiveNumber(Number));

		return Number;
	}

	template<typename T> T ReadPositiveNumberInRange(T From, T To, string Message) {
		T PositiveNumber = 0;

		do
		{
			PositiveNumber = ReadPositiveNumber(Message);

			if (!MyValidationLib::IsNumberInRange(PositiveNumber, From, To))
				cout << "Wrong number, please enter a number from " << From << " to " << To << "." << endl;

		} while (!MyValidationLib::IsNumberInRange(PositiveNumber, From, To));

		return PositiveNumber;
	}

	stDate ReadDate() {
		stDate Date;

		Date.Year = MyInputLib::ReadPositiveNumber("Enter a year : ");
		Date.Month = MyInputLib::ReadPositiveNumber("\nEnter a month : ");
		Date.Day = MyInputLib::ReadPositiveNumber("\nEnter a day : ");

		return Date;
	}

	stPeriod ReadPeriod() {
		stPeriod Period;

		cout << "Enter start date :\n";
		Period.StartDate = MyInputLib::ReadDate();

		cout << "\nEnter end date :\n";
		Period.EndDate = MyInputLib::ReadDate();

		return Period;
	}

}