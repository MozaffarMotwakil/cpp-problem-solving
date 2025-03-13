#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

struct stClient
{
    string AccountNumber;
    string PIN;
    string FullName;
    string Phone;
    float Salary;
    bool MarkForDelete = false;
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

bool IsClientExists(vector<stClient>& vClients, stClient& Client, string AccountNumber) {
   for (stClient& CopyClient : vClients)
    {
        if (CopyClient.AccountNumber == AccountNumber)
        {
            Client = CopyClient;
            return true;
        }
    }

    return false;
}

void PrintClinteDatails(stClient Clinte) {
    cout << "\nThe following are the client datails :\n\n";

    cout << "Accout Name  : " << Clinte.AccountNumber << endl;
    cout << "PIN code     : " << Clinte.PIN << endl;
    cout << "Full Name    : " << Clinte.FullName << endl;
    cout << "Phone Number : " << Clinte.Phone << endl;
    cout << "Salary       : " << Clinte.Salary << endl;
}

string RecordToString(stClient Client, string Separator) {
    return Client.AccountNumber + Separator + Client.PIN + Separator + Client.FullName
        + Separator + Client.Phone + Separator + to_string(Client.Salary);
}

void SavaClientsToFileAfterDelete(vector<stClient> vClients, string FilePath) {
    fstream File;
    File.open(FilePath, ios::out);

    if (File.is_open())
    {
        for (stClient Client : vClients)
        {
            if (Client.MarkForDelete != true)
            {
                File << RecordToString(Client, "#//#") << endl;
            }
        }
    }

    File.close();
}

void UpdateClientInformation(vector<stClient>& vClients, string AccountNumber) {
    for (stClient& Client : vClients) {
        if (Client.AccountNumber == AccountNumber)
        {
            Client.MarkForDelete = true;
            return; // Getout
        }
    }
}

void UpdateClientByAccountNumber(vector<stClient>& vClients, string AccountNumber) {
    stClient Client;
    
    if (IsClientExists(vClients, Client, AccountNumber))
    {
        PrintClinteDatails(Client);

        char UserAnswer = MyInputLib::ReadChar("\nDo you want delete this Client ? (Y/N) : ");

        if (toupper(UserAnswer) == 'Y')
        {
            UpdateClientInformation(vClients, AccountNumber);
            SavaClientsToFileAfterDelete(vClients, "Clients.txt");

            vClients = LoadClintesFromFile("Clients.txt"); // update vClients data after delete one record
            cout << "\nSeccessfil Delete";
        }
    }
    else
    {
        cout << "\nClient with account number (" << AccountNumber << ") Not found!";
    }
}

int main()
{
    vector<stClient> vClients = LoadClintesFromFile("Clients.txt");
    string AccountNumber = MyInputLib::ReadString("Enter Account number : ");

    UpdateClientByAccountNumber(vClients, AccountNumber);

    system("pause > 0");
    return 0;
}