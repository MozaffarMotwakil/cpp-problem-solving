#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../MyLibrary/MyInputLib.h"

using namespace std;

struct stClient
{
    string AccountNumber;
    string PIN;
    string FullName;
    string Phone;
    float Salary;
};

vector<string> Split(string Text, string Dilimeter) {
    vector<string> vTextParts;
    string Part = "";
    short Positiom = 0;

    while ((Positiom = Text.find(Dilimeter)) != string::npos)
    {
        Part = Text.substr(0, Positiom);

        if (Part != "")
        {
            vTextParts.push_back(Part);
        }

        Text.erase(0, Positiom + Dilimeter.length());
    }

    if (Part != "")
    {
        vTextParts.push_back(Text);
    }

    return vTextParts;
}

stClient ConvertLineToCline(string ClineLine) {
    vector<string> vClinteParts = Split(ClineLine, "#//#");
    stClient Clinte;

    Clinte.AccountNumber = vClinteParts[0];
    Clinte.PIN = vClinteParts[1];
    Clinte.FullName = vClinteParts[2];
    Clinte.Phone = vClinteParts[3];
    Clinte.Salary = stof(vClinteParts[4]);

    return Clinte;
}

vector<stClient> LoadClintesFromFile(string FilePath) {
    vector<stClient> vClintes;
    fstream File;

    File.open(FilePath, ios::in);

    if (File.is_open())
    {
        string ClinteLine = "";

        while (getline(File, ClinteLine))
        {
            vClintes.push_back(ConvertLineToCline(ClinteLine));
        }
    }

    return vClintes;
}

void PrintClinteDatails(stClient Clinte) {
    cout << "Accout Name  : " << Clinte.AccountNumber << endl;
    cout << "PIN code     : " << Clinte.PIN << endl;
    cout << "Full Name    : " << Clinte.FullName << endl;
    cout << "Phone Number : " << Clinte.Phone << endl;
    cout << "Salary       : " << Clinte.Salary << endl;
}

bool IsClientExists(string FilePath, string AccountNumber, stClient& Client) {
    vector<stClient> vClients = LoadClintesFromFile(FilePath);

    for (stClient& CopyClient : vClients) {
        if (CopyClient.AccountNumber == AccountNumber)
        {
            Client = CopyClient;
            return true;
        }
    }
    
    return false;
}

int main()
{
    string AccountNumber = MyInputLib::ReadString("Enter Account number : ");
    stClient Client;

   
    if (IsClientExists("C:\\Users\\mozaf\\C++ Projacts\\CourseSaven\\Ex_47-SaveRecordToFile\\PersonsInfo.txt", AccountNumber, Client))
    {
        cout << "\nThe following are the client datails :\n\n";
        PrintClinteDatails(Client);
    }
    else
    {
        cout << "\nClient with account number (" << AccountNumber << ") Not found!";
    }

    system("pause > 0");
}