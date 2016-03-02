#include <iostream>
#include "date.h"

using namespace std;

/**
 *
 * Autor UnoCuatro
 */
int test(int day, int month, int year){
    Date d;
    cout << "Dame el dia: " << day << endl;
    cout << "Dame el mes: " << month << endl;
    cout << "Dame el año: " << year << endl;

    if(d.isDate(day, month, year)){
        cout << "Fecha valida!" << endl;
    }
    else {
        switch(d.getDateErrorCode()){
            case -1:
                cout << "Mes no valido!" << endl << endl;
                break;
            case -2:
                cout << "Dia no valido!" << endl << endl;
                break;
        }
    }

    cout << "Presione ENTRAR para continuar... ";
    cin.get();
    cout << endl << endl;
}
int main()
{
    cout << "VERIFICADOR DE FECHA V1.0" << endl << endl;

    test(12, 9, 1979);
    test(0, 1, 2011);
    test(1, 13, 2011);
    test(12, -1, 2011);
    test(31, 4, 2011);
    test(29, 2, 2011);
    test(29, 2, 2016);
    test(28, 2, 2011);
    test(21, 3, -34);
    test(0, 0, 0);
    test(14, 2, 2016);

    return 0;
}
