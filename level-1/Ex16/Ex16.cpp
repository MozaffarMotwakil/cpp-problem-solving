#include <iostream>

using namespace std;

void PrintLettersFromAAAtoZZZ() {
	for (int a = 65; a <= 90; a++)
	{
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				cout << char(a) << char(i) << char(j) << endl;
			}
		}
	}
}

int main()
{
	PrintLettersFromAAAtoZZZ();
}
