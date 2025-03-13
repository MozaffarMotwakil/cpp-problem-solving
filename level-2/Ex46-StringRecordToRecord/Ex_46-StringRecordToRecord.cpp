#include <iostream>
#include <vector>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

struct stClinte
{
    string AcountNumber;
    string PIN;
    string FullName;
    string Phone;
    float Salary;
};

vector<string> Split(string Text, string Dilimeter) {
	string Word = "";
	int Position = 0;
	vector<string> vWords;

	while ((Position = Text.find(Dilimeter)) != string::npos)
	{
		Word = Text.substr(0, Position);

		if (Word != "")
		{
			vWords.push_back(Word);
		}

		Text.erase(0, Position + Dilimeter.length());
	}

	if (Word != "")
	{
		vWords.push_back(Text);
	}

	return vWords;
}

stClinte ConvertStringToRecord(string RecordInString) {
	vector<string> vRecordFields = Split(RecordInString, "#//#");
	stClinte PersonInfo;

	PersonInfo.AcountNumber = vRecordFields[0];
	PersonInfo.PIN = vRecordFields[1];
	PersonInfo.FullName = vRecordFields[2];
	PersonInfo.Phone = vRecordFields[3];
	PersonInfo.Salary = stof(vRecordFields[4]);

	return PersonInfo;
}

void PrintRecord(stClinte PersonInfo) {
    cout << "Accout Name  : " << PersonInfo.AcountNumber << endl;
    cout << "PIN code     : " << PersonInfo.PIN << endl;
    cout << "Full Name    : " << PersonInfo.FullName << endl;
    cout << "Phone Number : " << PersonInfo.Phone << endl;
    cout << "Salary       : " << PersonInfo.Salary << endl;
}

int main()
{
    string RecordInString = "M123#//#12345#//#Mozaffar Motwakil#//#0117579457#//#5000.000000";

    stClinte PersonInfo = ConvertStringToRecord(RecordInString);
    PrintRecord(PersonInfo);

    system("pause > 0");
}