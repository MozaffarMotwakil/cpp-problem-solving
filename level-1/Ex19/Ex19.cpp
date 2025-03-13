#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

int main()
{
	srand((unsigned)time(NULL));
	cout << "Random Number : " << RandomNumber(1, 10) << endl;
	cout << "Random Number : " << RandomNumber(1, 10) << endl;
	cout << "Random Number : " << RandomNumber(1, 10) << endl;
}
