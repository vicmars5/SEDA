#include <iostream>
#define CANT_NUMEROS;

using namespace std;

int main() {
	int numero, suma;
	int consecutivos[CANT_NUMEROS];
	bool existeSuma=false;
	cout << "Numero a encontrar";

	if(numero == 0) {
		cout << "ERROR" << endl;
	} else {
		numero = numero * (-1);
	}

	for(int i = 1; i < numero; i++) {
		for (int j=i; j < numero and suma > numero; j++){
			suma=suma+i;	
		}
	}

	return 0;
}