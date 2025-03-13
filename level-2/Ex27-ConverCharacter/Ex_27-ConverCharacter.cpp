#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"

using namespace std;

char InvertLetterCase(char Character) {
    return islower(Character) ? toupper(Character) : tolower(Character);
}

int main()
{
    char Charracter = MyInputLib::ReadChar("Enter a charracter : ");

    cout << "\nThe character after inverting case : " << InvertLetterCase(Charracter);

    system("pause > 0");
}