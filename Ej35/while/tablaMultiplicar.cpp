#include <iostream>

using namespace std;

/*
 *Autor:  UnoCuatro
 *5 minutos
*/

int main(){
	int multiplicando, ultMultiplicador, i;

	do{
		cout << "Dame el multiplicando = ";
		cin >> multiplicando;
		cout << "Dame hasta cual multiplicador = ";
		cin >> ultMultiplicador;

		if(ultMultiplicador >= 0){
			cout << "Tabla de multiplicar del " << multiplicando << endl;
			i=1;
			while(i <= ultMultiplicador){
				cout << multiplicando << "\tX\t" << i << "\t=\t" << (multiplicando*i) << endl;
				i++;
			}
			break;
		}
	}while(ultMultiplicador < 0);
	return 0;
}