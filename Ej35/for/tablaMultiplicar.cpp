#include <iostream>

using namespace std;

/*
 *Autor:  UnoCuatro
 *15 minutos
*/

int main(){
	int multiplicando, ultMultiplicador;

	do{
		cout << "Dame el multiplicando = ";
		cin >> multiplicando;
		cout << "Dame hasta cual multiplicador = ";
		cin >> ultMultiplicador;

		if(ultMultiplicador >= 0){
			cout << "Tabla de multiplicar del " << multiplicando << endl;
			for (int i=1; i <= ultMultiplicador; i++){
				cout << multiplicando << "\tX\t" << i << "\t=\t" << (multiplicando*i) << endl;
			}
			break;
		}
	}while(ultMultiplicador < 0);
	return 0;
}