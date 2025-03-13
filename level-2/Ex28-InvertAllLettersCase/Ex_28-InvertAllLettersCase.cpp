#include <iostream>
#include <cctype>
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyInputLib.h"
#include "C:\Users\mozaf\C++ Projacts\MyLibrary\MyTextUtilsLib.h"

using namespace std;

string InvertAllLettersCase(string Text) {
    for (unsigned short i = 0; i < Text.length(); i++)
    {
        Text[i] = MyTextUtilsLib::InvertLetterCase(Text[i]);
    }

    return Text;
}

int main()
{
    string Text = MyInputLib::ReadString("Enter a Sentence : ");

    cout << "\nThe text after inverting case : " << InvertAllLettersCase(Text);

    system("pause > 0");
}