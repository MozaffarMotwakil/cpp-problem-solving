#include "..\..\MyLibrary\MyDateUtilsLib.h"
#include "..\..\MyLibrary\MyInputLib.h"
#include <iostream>

using namespace std;

short PeriodLength(stPeriod Period, bool IncludeEndDay = false) {
    return MyDateUtilsLib::DiffirentBetweenTwoDates(Period.StartDate, Period.EndDate, IncludeEndDay);
}

int main()
{
    stPeriod Period = MyInputLib::ReadPeriod();

    cout << "\n\nPeriod length is : " << PeriodLength(Period);
    cout << "\nPeriod length (include end day) is : " << PeriodLength(Period, true) << endl;

    return 0;
}
