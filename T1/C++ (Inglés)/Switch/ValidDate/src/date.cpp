#include "date.h"

Date::Date() {
    dateErrorCode=-2;
}

Date::~Date() {
    //dtor
}

bool Date::isDate(const int& day, const int& month, const int& year) {
    if(day > 0){
        switch(month) {
            case 4:
            case 6:
            case 9:
            case 11:
                if(day<=30){
                    dateErrorCode=0;
                    return true;
                }
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(day<=31){
                    dateErrorCode=0;
                    return true;
                }
                break;
            case 2:
                if ((year%4)!=0 && day<=28){
                    dateErrorCode=0;
                    return true;
                }
                if ((year%4)==0 && day<=29){
                    dateErrorCode=0;
                    return true;
                }
                break;
            default:
                dateErrorCode=-1;
                return false;
        }
    }
    dateErrorCode=-2;
    return false;
}

int Date::getDateErrorCode()
{
    return dateErrorCode;
}
