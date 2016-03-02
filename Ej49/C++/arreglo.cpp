#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int encontrarMenor(int vect[], int tam){
	int menor=vect[0];
	for (int i = 1; i < tam; i++){
		if (vect[i] < menor) {
			menor = vect[i];
		}
	}
	return menor;
}

int main(){
	int tam = 4;
	int vect[tam];

	cout << "Valores de arreglo: " << endl;

	srand(time(NULL));	
	for (int i = 0; i < tam; i++){
		vect[i] = rand() % 101;
		cout << "Valor " << i << ": " << vect[i] << endl;
	}
	cout << endl;
	
	cout << "Valor menor: " << encontrarMenor(vect, 4) << endl;
	return 0;
}