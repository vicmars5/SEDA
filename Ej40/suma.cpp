#include <iostream>

using namespace std;

int main() {
	int numero, suma;
	bool existeSuma=false;
	bool positivo;
	int i,j,n; //Contadores
	
	cout << "Numero a encontrar";
	cin >> numero;

	if(numero < 0) {

		numero = numero * (-1);
		positivo=false;
	} else {
		if(numero == 0) {
			cout << "ERROR, numero numero no valido";
		} else {
			positivo=true;
		}
	}

	for(i = 1; i < numero; i++) {

		suma=0;

		for (j=i; j < numero and suma < numero; j++) {
			
			suma=suma+j;

			if(suma == numero){
				existeSuma=true;
				
				cout << numero << " = " << i;
				for (n=i+1; n <= j; n++) {
					if(positivo){
						cout << " + " << n;
					}
					else {
						cout << " - " << n;
					}
				}
				cout << endl;

				break;
			}
			else {
				if (suma > numero) {
					break;
				}
			}
		}
	}

	if(!existeSuma) {
		cout << "No es posible obtener la suma de los numeros";
	}

	return 0;
}