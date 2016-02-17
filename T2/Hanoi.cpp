#include <iostream>
#include <cstdlib>

#define TORRE_INICIAL 1
#define TORRE_AUXILIAR 2
#define TORRE_FINAL 3

using namespace std;

int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal);

void iniciarDiscosTorres(int tam);

int discosTorres[3][5];

int main()
{
    int cantDiscos, movimientos;
	cout << "Cantidad de discos a mover: ";
	cin >> cantDiscos;
	iniciarDiscosTorres(cantDiscos);
	cout << endl << "La serie de movimientos a realizar es: " << endl << endl;
	movimientos = hanoi(cantDiscos, TORRE_INICIAL, TORRE_AUXILIAR, TORRE_FINAL);
	cout << endl << "Se realizaron en total " << movimientos << " movimientos" << endl;
	return 0;
}

void iniciarDiscosTorres(int tam){
	for(int i=(tam-1); i >= 0; i--){
		discosTorres[0][i]=(i+1);
		cout << discosTorres[0][i] << endl;
	}
}

int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal)
{
    static int movimientos = 0;
	if(numDiscos == 1) // solo hay un disco
	{
		cout << "Mover el disco superior de la torre " << torreInicial << " a la torre " << torreFinal << endl;
		movimientos++;
	}
	else // mas de un disco
	{
		hanoi(numDiscos - 1, torreInicial, torreFinal, torreAuxiliar);
		cout << "Mover el disco superior de la torre " << torreInicial << " a la torre " << torreFinal << endl;
		movimientos++;
		hanoi(numDiscos - 1, torreAuxiliar, torreInicial, torreFinal);
	}
	return movimientos;
}
