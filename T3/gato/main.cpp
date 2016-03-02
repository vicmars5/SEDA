/*
 * Gato
 * Autor UnoCuatro
 * Tiempo=02:10
 */

#include <iostream>
#include <cstdlib>

#ifdef __unix__
 #define CLEAR "clear"
#else
 #define CLEAR "cls"
#endif

using namespace std;

char tablero[3][3];
const char signo[]={'X','O'};

void mostrarGato();
bool buscarGanador(char);
void limpiarTablero();

int main (){
	string nombre[2];
	
	int eleccionX,
		eleccionY,
		otroJuego;

	bool turno,
		gano;

	int puntaje[] = {0.0};

	for(int i=0; i<2; i++){
		cout << "Jugador " << signo[i] << " dime tu nombre: ";
		getline(cin,nombre[i]);
	}

	turno = 0;

	do{

		limpiarTablero();
		cout << nombre[turno] << " tu empiezas" << endl;

		for (int tiros = 0; tiros < 9; tiros++){

			mostrarGato();

			cout << nombre[turno] << " dime la fila (1 a 3): ";
			cin >> eleccionY;
			cin.ignore();
			cout << nombre[turno] << " dime la columna (1 a 3): ";
			cin >> eleccionX;
			cin.ignore();

			if(eleccionX <= 3 && eleccionY <= 3	&& eleccionX > 0 && eleccionY > 0
				&& tablero[eleccionX-1][eleccionY-1] == ' '){

				tablero[eleccionX-1][eleccionY-1] = signo[turno];
				if(buscarGanador(signo[turno])){
					gano = true;
					break;
				} else {
					turno = !turno;
				}

			} else {
				cout << "ERROR, cordenadas no validas" << endl;
			}
		}

		if(!gano){
			cout << "Nadie gana :(" << endl;
		}else{
			cout << "Gano " << nombre[turno] << "!!! "<< endl;
			puntaje[turno]++;
			mostrarGato();
			turno = !turno;
		}

		cout << "Quieres jugar otra partida? 1.-si 0.-no " << endl;
		cin >> otroJuego;
	} while(otroJuego == 1);

	cout << "Adios " << endl;

	return 0;
}

void mostrarGato () {
	string margen,
		ganador = "";

	for(int i = 0; i < 3; i++){
		margen+=" ";
	}

	cout << margen << "  1 2 3" << endl;
	cout << margen << "1 " << tablero[0][0] << "|"
			<< tablero[1][0] << "|" 
			<< tablero[2][0] << endl;
	cout << margen << "  -----" << endl;
	cout << margen << "2 " << tablero[0][1] << "|" 
			<< tablero[1][1] << "|" 
			<< tablero[2][1] << endl;
	cout << margen << "  -----" << endl;
	cout << margen << "3 " << tablero[0][2] 
			<< "|" << tablero[1][2] << "|" 
			<< tablero[2][2] << endl;
}

bool buscarGanador(char signo){
	bool gano = false;
	int encFila,
		encColumna,
		diagonalA = 0,
		diagonalB = 0;
	int i,
		j;

	for(i = 0; i < 3; i++){
		if(tablero[i][i] == signo){
			diagonalA++;
			if(diagonalA == 3){
				gano = true;
				break;
			}
		}
		if(tablero[i][2-i] == signo){
			diagonalB++;
			if(diagonalB == 3){
				gano = true;
				break;
			}
		}
		encFila=0;
		encColumna=0;
		for(j=0; j<3; j++){
			if(tablero[j][i] == signo){
				encFila++;
				if(encFila == 3){
					gano = true;
					break;
				}
			}
			if(tablero[i][j] == signo){
				encColumna++;
				if(encColumna == 3){
					gano = true;
					break;
				}
			}
		}
	}
	return gano;
}

void limpiarTablero(){
	int i,
		j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			tablero[j][i]=' ';
		}
	}
}