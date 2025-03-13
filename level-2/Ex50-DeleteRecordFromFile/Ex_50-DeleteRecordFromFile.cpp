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

short IsClientExists(string FilePath, string AccountNumber, stClient& Client) {
    vector<stClient> vClients = LoadClintesFromFile(FilePath);
    int Counter = 0;

    for (stClient& CopyClient : vClients)
    {
        if (CopyClient.AccountNumber == AccountNumber)
        {
            Client = CopyClient;
            return Counter;
        }

        Counter++;
    }

    return -1;
}

void PrintClinteDatails(stClient Clinte) {
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

void DeleteClient(string FilePath, int Position) {
    char Delete = MyInputLib::ReadChar("\nDo you want delete this Client ? (Y / N) : ");

    if (toupper(Delete) == 'Y')
    {
        vector<stClient> vClients = LoadClintesFromFile(FilePath);
        vClients.erase(vClients.begin() + Position);
        fstream File;
        File.open(FilePath, ios::out);

        if (File.is_open())
        {
            for (stClient Client : vClients) 
            {
                File << RecordToString(Client, "#//#") << endl;
            }
        }

        File.close();
        cout << "\nSeccessfult delete";
    }

}

int main()
{
    string AccountNumber = MyInputLib::ReadString("Enter Account number : ");
    stClient Client;
    short Position = IsClientExists("Clients.txt", AccountNumber, Client);

    if (Position != -1)
    {
        cout << "\nThe following are the client datails :\n\n";
        PrintClinteDatails(Client);
       
        DeleteClient("Clients.txt", Position);
    }
    else
    {
        cout << "\nClient with account number (" << AccountNumber << ") Not found!";
    }

    system("pause > 0");

    return 0;
}