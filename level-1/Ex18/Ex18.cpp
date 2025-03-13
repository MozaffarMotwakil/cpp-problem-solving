#include <iostream>

using namespace std;

string OrginalNames[5], EncryptionNames[5] = {"M0051", "M0052", "M0053" ,"M0054" ,"M0055"};
int NamePosition = 0;

string ReadName(string Message) {
    string Name = "";

    cout << Message;
    cin >> Name;

    return Name;
}

string EncryptName(string OrginalName) {
    OrginalNames[NamePosition] = OrginalName;
    return EncryptionNames[NamePosition];
}

string DecryptName(string EncryptName) {
    for (int i = 0; i < 5; i++)
    {
        if (EncryptName == EncryptionNames[i])
        {
            return OrginalNames[i];
        }
    }

    return "Not Found";
}

void PrintResult(string Name) {
    cout << "Text before encryption : " << Name << endl;
    cout << "Text after encryption : " << EncryptName(Name) << endl;
    cout << "Text after decryption : " << DecryptName(EncryptName(Name)) << endl;
}

int main()
{
    string Name = "";
    do
    {
        Name = ReadName("Enter the name : ");
        PrintResult(Name);
    } while (Name != "Stop");
}
