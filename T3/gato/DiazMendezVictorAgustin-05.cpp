#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void mostrarGato(char tablero[3][3]){
	int cont;
	string margen, ganador="";

	for(cont=0; cont<37; cont++){
		margen+=" ";
	}
	cout << margen << "  1 2 3" << endl;
	cout << margen << "1 " << tablero[0][0] << "|" << tablero[1][0] << "|" << tablero[2][0] << endl;
	cout << margen << "  -----" << endl;
	cout << margen << "2 " << tablero[0][1] << "|" << tablero[1][1] << "|" << tablero[2][1] << endl;
	cout << margen << "  -----" << endl;
	cout << margen << "3 " << tablero[0][2] << "|" << tablero[1][2] << "|" << tablero[2][2] << endl;
}

bool buscarGanador(char tablero[3][3], char signo){
	bool gano=false;
	int encFila, encColumna, diagonalA=0, diagonalB=0;
	int cont, subCont;
	for(cont=0; cont<3; cont++){
		if(tablero[cont][cont]==signo){
			diagonalA++;
			if(diagonalA==3){
				gano=true;
				break;
			}
		}
		if(tablero[cont][2-cont]==signo){
			diagonalB++;
			if(diagonalB==3){
				gano=true;
				break;
			}
		}
		encFila=0;
		encColumna=0;
		for(subCont=0; subCont<3; subCont++){
			if(tablero[subCont][cont]==signo){
				encFila++;
				if(encFila==3){
					gano=true;
					break;
				}
			}
			if(tablero[cont][subCont]==signo){
				encColumna++;
				if(encColumna==3){
					gano=true;
					break;
				}
			}
		}
	}
	return gano;
}

int main (){
	char tablero[3][3], signo[]={'X','O'};
	string nombre[2];
	int tiros=0;
	int eleccionX, eleccionY;
	int cont, subCont;
	int otroJuego;
	srand(time(NULL));
	for(cont=0; cont<2; cont++){
		cout << "Jugador " << (cont+1) << " dime tu nombre: ";
		getline(cin,nombre[cont]);
	}
	do{
		for(cont=0; cont<3; cont++){
			for(subCont=0; subCont<3;subCont++){
				tablero[subCont][cont]=' ';
			}
		}
		cont=0+rand()%(2-0);
		cout << nombre[cont] << " tu empiezas" << endl;
		do{

			mostrarGato(tablero);
			cout << nombre[cont] << " posicion de tu signo en x";
			cin >> eleccionX;
			cout << nombre[cont] << " posicion de tu signo en y";
			cin >> eleccionY;

			if(eleccionX<=3 && eleccionY<=3 && tablero[eleccionX-1][eleccionY-1]==' '){
				tiros++;
				if(cont==0){
					tablero[eleccionX-1][eleccionY-1]='O';
					if(buscarGanador(tablero,'O')==true){
						tiros=10;
						break;
					}
					else{
						cont++;	
					}
				}
				else{
					tablero[eleccionX-1][eleccionY-1]='X';
					if(buscarGanador(tablero, 'X')){
						tiros=10;
						break;
					}
					else {
						cont=0;
					}

				}
			} else {
				cout << "ERROR, cordenadas no validas" << endl;
			}
		}while(tiros<9);

		if(tiros==10){
			cout << "Gano " << nombre[cont] << "!!! "<< endl;
			mostrarGato(tablero);	
		}else{
			cout << "Nadie gana :(" << endl;
		}

		cout << "Quieres jugar otra partida? 1.-si 0.-no " << endl;
		cin >> otroJuego;
		tiros=0;
	}while(otroJuego==1);

	cout << "Adios " << endl;

	return 0;
}

 /*
	<<<Gato>>>
 1-Me pregunta el nombre de cada jugador
 2-Pregunta el nombre del jugador
 3-Si no se forma la diagonal y se forman los nueve tiros decir EMPATE
 4-Decir quien gano la mayoria de partidas


 */
