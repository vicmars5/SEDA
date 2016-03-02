#include <iostream>
#include "date.h"

using namespace std;

void prueba(int day, int month, int year){
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

    prueba(12, 9, 1979);
    prueba(0, 1, 2011);
    prueba(1, 13, 2011);
    prueba(12, -1, 2011);
    prueba(31, 4, 2011);
    prueba(29, 2, 2011);
    prueba(29, 2, 2016);
    prueba(28, 2, 2011);
    prueba(21, 3, -34);
    prueba(0, 0, 0);
    prueba(14, 2, 2016);

    return 0;
}
