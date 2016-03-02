#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool numerosDiferentes(int vect[], int tam){
	for (int i = 0; i < tam; i++){
		for (int j = i+1; j < tam; j++){
			if (vect[i] == vect[j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int tam = 10;
	int vect[tam];
	int rangoValores = 100;

	cout << "Valores de arreglo: " << endl;
	srand(time(NULL));
	for (int i = 0; i < tam; i++){
		cout << "Valor " << i << ": ";
		cin >> vect[i];
		cin.ignore();
	}
	cout << endl;
	if(numerosDiferentes(vect, tam)){
		cout << "Todos los numeros son diferentes." << endl;
	} else {
		cout << "Hay numeros repetidos en el arreglo." << endl;
	}
	return 0;
}