#include <iostream>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

struct stClient
{
    string AccountNumber;
    short PIN;
    string FullName;
    string Phone;
    float Salary;
};

stClient GetPersonInfo() {
    stClient PersonInfo;

    PersonInfo.AccountNumber = MyInputLib::ReadString("Enter the acount number : ");
    PersonInfo.PIN = MyInputLib::ReadPositiveNumber("Enter the PIN code : ");
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    PersonInfo.FullName = MyInputLib::ReadString("Enter the name : ");
    PersonInfo.Phone = MyInputLib::ReadString("Enter the phone number : ");
    PersonInfo.Salary = MyInputLib::ReadPositiveNumber("Enter the salary : ");

    return PersonInfo;
}

string RecordToString(stClient Record, string Seperator = "#//#") {
    return Record.AccountNumber + Seperator + to_string(Record.PIN) + Seperator 
        + Record.FullName + Seperator + Record.Phone + Seperator + to_string(Record.Salary);
}

int main()
{
    stClient PersonInfo = GetPersonInfo();

    cout << "\nPerson Info in string :\n" << RecordToString(PersonInfo, "#//#") << endl;

    system("pause > 0");
}