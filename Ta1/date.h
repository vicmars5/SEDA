#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date {
    public:
        Date();
        virtual ~Date();
        void setDate(int&, int&, int&);
        int getDay();
        int getMonth();
        int getYear();
    protected:
        int day;
        int month;
        int year;
        void saveDate(int &, int&, int&);
        bool isDate();
    private:
    };

#endif // DATE_H
