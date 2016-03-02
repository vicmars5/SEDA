/*
 *Autor UnoCuatro
 */
#include "stdio.h"
#define TAMANIO_MATRIZ 4

int matriz[TAMANIO_MATRIZ][TAMANIO_MATRIZ];

typedef struct{
	int x,
		y,
		valor,
		iguales, //Cantidad de elementos iguales
		mayores, //Cantidad de elementos mayores
		menores; //Cantidad de elementos menores
} Elemento;

void solicitaDatos(){
	int i, j;
	for (i = 0; i < TAMANIO_MATRIZ; i++){
		for (j = 0; j < TAMANIO_MATRIZ; j++){
			printf("Valor [%d][%d]", i, j);
			scanf("%i", &matriz[i][j]);
		}
	}
	printf("\n\n");
}

void mostrarMatriz(){
	int i, j;

	printf("Matriz: \n");
	printf("y\\x");
	for (i = 0; i < TAMANIO_MATRIZ; i++){
		printf("\tX%d", (i+1));
	}
	printf("\n\n");
	for (i = 0; i < TAMANIO_MATRIZ; i++) {
		printf("Y%d", (i+1));
		for (j = 0; j < TAMANIO_MATRIZ; j++) {
			printf("\t%d", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

float promedioMatriz(){
	int i, j;
	float suma = 0;

	for(i = 0; i < TAMANIO_MATRIZ; i++){
		for(j = 0; j < TAMANIO_MATRIZ; j++){
			suma += matriz[i][j];
		}
	}

	return suma / (TAMANIO_MATRIZ*TAMANIO_MATRIZ);
}

Elemento elementoMenor(){
	Elemento elemento;
	int i,j;

	elemento.valor = matriz[0][0];
	elemento.x = 0;
	elemento.y = 0;
	
	for (i = 0; i < TAMANIO_MATRIZ; i++){
		for (j = 0; j < TAMANIO_MATRIZ; j++){
			if(elemento.valor > matriz[i][j]){
				elemento.valor = matriz[i][j];
				elemento.x = j;
				elemento.y = i;
			}
		}
	}

	//Cantidad de elementos mayores
	elemento.mayores = 0;
	for (i = 0; i < TAMANIO_MATRIZ; i++){
		for (j = 0; j < TAMANIO_MATRIZ; j++){
			if(elemento.valor < matriz[i][j]){
				elemento.mayores++;
			}
		}
	}
	elemento.iguales = (TAMANIO_MATRIZ * TAMANIO_MATRIZ) - elemento.mayores;
	return elemento;
}

Elemento elementoMayor () {
	Elemento elemento;
	int i,j;

	elemento.valor = matriz[0][0];
	elemento.x = 0;
	elemento.y = 0;
	
	//Busqueda de elemento
	for (i = 0; i < TAMANIO_MATRIZ; i++){
		for (j = 0; j < TAMANIO_MATRIZ; j++){
			if(elemento.valor < matriz[i][j]){
				elemento.valor = matriz[i][j];
				elemento.x = j;
				elemento.y = i;
			}
		}
	}

	//Cantidad de elementos menores, y apariciones
	elemento.menores = 0;
	elemento.iguales = 0;
	for (i = 0; i < TAMANIO_MATRIZ; i++){
		for (j = 0; j < TAMANIO_MATRIZ; j++){
			if(elemento.valor > matriz[i][j]){
				elemento.menores++;
			} else {
				elemento.iguales++;
			}
		}
	}
	return elemento;
}

int main () {
	Elemento elemMenor, elemMayor;

	printf("\tProyecto de Matriz\n\n");
	solicitaDatos();
	mostrarMatriz();
	printf("Promedio: %.2f\n", promedioMatriz());

	elemMenor = elementoMenor();
	printf("Elemento menor [X%d][Y%d]: %d\n", elemMenor.x + 1, elemMenor.y + 1, elemMenor.valor);
	printf("Apariciones: %d veces.\n", elemMenor.iguales);
	printf("Mayores: %d elementos.\n", elemMenor.mayores);
	
	elemMayor = elementoMayor();
	printf("Elemento mayor [X%d][Y%d]: %d\n", elemMayor.x + 1, elemMayor.y + 1, elemMayor.valor);
	printf("Apariciones: %d veces.\n", elemMayor.iguales);
	printf("Menores: %d elementos.\n", elemMayor.menores);

	return 0;
}