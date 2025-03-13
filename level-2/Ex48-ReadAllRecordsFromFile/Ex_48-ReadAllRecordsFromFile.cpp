#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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

void PrintClintes(vector<stClient> vClintes) {
    for (short i = 0; i < vClintes.size(); i++)
    {
        cout << "\n|" << setw(15) << vClintes[i].AccountNumber << "|" << setw(11) << vClintes[i].PIN << "|" << setw(45) << 
            vClintes[i].FullName << "|" << setw(15) << vClintes[i].Phone << "|" << setw(10) << vClintes[i].Salary;
    }
}

void DisplayClintes(vector<stClient> vClintes) {
    cout << left;
    cout << "\t\t\t\t\tClinte List (" << vClintes.size() << ") Clinte(s).";
    cout << "\n_____________________________________________________________________________________________________\n";
    cout << "\n|" << setw(15) << " Acount Number" << "|" << setw(11) << " PIN Code" << "|" << setw(45) <<
        " Clinte Name" << "|" << setw(15) << " Phone" << "|" << setw(10) << " Balance";
    cout << "\n_____________________________________________________________________________________________________\n";
    PrintClintes(vClintes);
    cout << "\n_____________________________________________________________________________________________________\n";
}

int main()
{
    DisplayClintes(LoadClintesFromFile("C:\\Users\\mozaf\\C++ Projacts\\CourseSaven\\Ex_47-SaveRecordToFile\\PersonsInfo.txt"));
    system("pause > 0");
}