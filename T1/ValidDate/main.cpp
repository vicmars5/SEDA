#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    int day, month, year;
    Date d;
    cout << "VERIFICADOR DE FECHA V1.0" << endl << endl;

    cout << "Dame le dia: ";
    cin >> day;
    cout << "Dame el mes: ";
    cin >> month;
    cout << "Dame el año; ";
    cin >> year;
    cin.ignore();

    if(d.isDate(day, month, year)){
        cout << "Fecha valida!" << endl;
    }
    else {
        if(d.getErrorCode() == -1){
            cout << "Mes no valido" << endl;
        }
        else {
            cout << "Dia no valido" << endl;
        }
    }

    cin.get();

    return 0;
}
