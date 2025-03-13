#include <iostream>
#include <vector>
#include <fstream>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

struct stClient
{
    string AccountNumber;
    string PIN;
    string FullName;
    string Phone;
    float Salary;
};

stClient GetPersonInfo() {
    stClient PersonInfo;

    PersonInfo.AccountNumber = MyInputLib::ReadString("Enter the acount number : ", true);
    PersonInfo.PIN = MyInputLib::ReadString("Enter the PIN code : ");
    PersonInfo.FullName = MyInputLib::ReadString("Enter the name : ");
    PersonInfo.Phone = MyInputLib::ReadString("Enter the phone number : ");
    PersonInfo.Salary = MyInputLib::ReadPositiveNumber("Enter the salary : ");

    return PersonInfo;
}

string RecordToString(stClient Record, string Seperator = "#//#") {
    return Record.AccountNumber + Seperator + Record.PIN + Seperator + Record.FullName
        + Seperator + Record.Phone + Seperator + to_string(Record.Salary);
}

void SaveStringRecordInFile(string FilePath, string RecordInString) {
    fstream File;

    File.open(FilePath, ios::out | ios::app);

    if (File.is_open())
    {
        File << RecordInString << endl;
    }

    File.close();
}

void SaveRecordInFile(stClient PersonInfo) {
    string RecordInString = RecordToString(PersonInfo);
    SaveStringRecordInFile("PersonsInfo.txt", RecordInString);
}

void ReadPersons() {
    stClient PersonInfo;
    char AddAgain = 'Y';

    do
    {
        system("cls");
        SaveRecordInFile(GetPersonInfo());
        AddAgain = MyInputLib::ReadChar("\nSeccessfully adding, Do you want to add more person ? (Y/N) : ");
       
    } while (AddAgain == 'Y' || AddAgain == 'y');
}

int main()
{
    ReadPersons();

    system("pause > 0");
}