#include <iostream>
#include <string>

using namespace std;

string ReadName(string Message) {
    string Name = "";

    cout << Message;
    getline(cin, Name);

    return Name;
}

string EncryptName(string OrginalName, short EncryptKay) {
    for (int i = 0; i <= OrginalName.length(); i++)
    {
        OrginalName[i] = ((int)OrginalName[i] + EncryptKay);
    }

    return OrginalName;
}

string DecryptName(string EncryptName, short EncryptKay) {
    for (int i = 0; i <= EncryptName.length(); i++)
    {
        EncryptName[i] = ((int)EncryptName[i] - EncryptKay);
    }

    return EncryptName;
}

void PrintResult(string Name) {
    
}

int main()
{
    string Name = ReadName("Enter a name : ");
    short EncryptKay = 2;
    cout << "Text before encryption : " << Name << endl;
    cout << "Text after encryption : " << EncryptName(Name, EncryptKay) << endl;
    cout << "Text after decryption : " << DecryptName(EncryptName(Name, EncryptKay), EncryptKay) << endl;
}