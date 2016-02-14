#include "date.h"

Date::Date() {
    errorCode=-2;
}

Date::~Date() {
    //dtor
}

bool Date::isDate(const int& day, const int& month, const int& year) {
    if(day <= 0) {
        errorCode = -2;
        return false;
    }

    if(month<1 || month >12) {
        errorCode = -1;
        return false;
    }

    if((month == 4 or month==6 or month==9 or month==11) && day<=30) {
        errorCode = 0;
        return true;
    }

    if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && day<=31) {
        errorCode = 0;
        return true;
    }

    if(((year % 4) != 0) && day <=28 && month==2) {
        errorCode = 0;
        return true;
    }

    if((year % 4) == 0 && day<=29 && month==2) {
        errorCode = 0;
        return true;
    }

    errorCode = -2;
    return false;
}

int Date::getErrorCode()
{
    return errorCode;
}
