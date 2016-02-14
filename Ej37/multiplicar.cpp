#include <iostream>

#define TAM 10

using namespace std;

int main() {
	int entrada[TAM], resultado[TAM];
	int multiplicador;
	int i;

	for (i=0; i<TAM; i++){
		cout << "Valor " << i << " del vector: ";
		cin >> entrada[i];
		cin.ignore();
	}
	cout << endl;
	cout << "Multiplicador: ";
	cin >> multiplicador;
	cin.ignore();
	cout << endl;

	i=0;
	do {
		resultado[i] = entrada[i] * multiplicador;
		i++;
	}while(i < TAM);

	i=0;
	while(i < TAM) {
		cout << entrada[i] << " X " << multiplicador << " = " << resultado[i] << endl;
		i++;
	}
	return 0;
}