#include <iostream>

#include "pila.h"

/*
 *Autor UnoCuatro
 */

#define TORRE_INICIAL 1
#define TORRE_AUXILIAR 2
#define TORRE_FINAL 3

using namespace std;

int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal);
void iniciarDiscosTorres(int tam);
void mostrarDiscos();

Pila discosTorres[3];

int main()
{
    int cantDiscos, movimientos;
	cout << "Cantidad de discos a mover: ";
	cin >> cantDiscos;
	cin.ignore();
	cout << endl << "La serie de movimientos a realizar es: " << endl << endl;
	cout << "Discos al inicio, se muestra el diámetro delos discos: " << endl;
	iniciarDiscosTorres(cantDiscos);
	mostrarDiscos();
	movimientos = hanoi(cantDiscos, TORRE_INICIAL, TORRE_AUXILIAR, TORRE_FINAL);
	cout << endl << "Se realizaron en total " << movimientos << " movimientos" << endl << endl;

	cout << "Presionar entrar para terminar... " << endl;
	cin.get();
	return 0;
}

void iniciarDiscosTorres(int tam){
	for(int i=(tam); i > 0; i--){
		discosTorres[0].apila(i);
	}
}

void mostrarDiscos(){
    for(int i=0; i < 3; i++){
        cout << "Torre " << (i+1) << ":";
        discosTorres[i].imprimirPila();
        cout << endl;
    }
};

int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal)
{
    static int movimientos = 0;
	if(numDiscos == 1) // solo hay un disco
	{
		cout << "Mover el disco superior de la torre " << torreInicial << " a la torre " << torreFinal << endl;
		discosTorres[torreFinal-1].apila(discosTorres[torreInicial-1].desapila());
		mostrarDiscos();
		movimientos++;
	}
	else // mas de un disco
	{
		hanoi(numDiscos - 1, torreInicial, torreFinal, torreAuxiliar);
		cout << "Mover el disco superior de la torre " << torreInicial << " a la torre " << torreFinal << endl;
		discosTorres[torreFinal-1].apila(discosTorres[torreInicial-1].desapila());
		mostrarDiscos();
		movimientos++;
		hanoi(numDiscos - 1, torreAuxiliar, torreInicial, torreFinal);
	}
	return movimientos;
}
