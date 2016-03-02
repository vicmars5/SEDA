#include "date.h"

Date::Date() {
    dateErrorCode=-2;
}

Date::~Date() {
    //dtor
}

bool Date::isDate(const int& day, const int& month, const int& year) {
    if(month>=1 && month<=12){
        if ((((month == 4 or month==6 or month==9 or month==11) && day<=30)
            || ((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && day<=31)
            || (((year % 4) != 0) && day <=28 && month==2)
            || ((year % 4) == 0 && day<=29 && month==2))
            && day > 0) {
            dateErrorCode = 0;
            return true;
        }
        dateErrorCode = -2;
        return false;
    }
    dateErrorCode = -1;
    return false;
}

int Date::getDateErrorCode()
{
    return dateErrorCode;
}
