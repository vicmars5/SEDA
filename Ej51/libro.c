/*
 * Autor UnoCuatro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOMBRE 30
#define MAX_LIBROS 128

int ultimo;

typedef struct {
	char nombre[TAM_NOMBRE];
	char autor[TAM_NOMBRE];
	float precio;
	int anioPublicacion;
} Libro;

Libro libros[MAX_LIBROS];

int elegirOpcionMenu();
void alta();
void modificar(int);
void baja();
void listar();
void inicializa();
void limpiarRegistro(int);

int main() {
	inicializa();
	int repetir;
	do{
		switch(elegirOpcionMenu()){
			case 1:
				alta();
				break;
			case 2:
				baja();
				break;
			case 3:
				consulta();
				break;
			case 5:
				listar();
				break;
			case 0:
				repetir = 0;
				break;
		}
	}while(repetir == 1);
	return 0;
}

int elegirOpcionMenu(){
	int opcion;

	printf("REGISTRO DE LIBROS\n");
    printf("1.-Alta de nuevo libro\n");
    printf("2.-Baja de libro\n");
    printf("3.-Consulta de un libro\n");
    printf("4.-Cambio de datos de un libro\n");
    printf("5.-Listado de libros\n");
    printf("0.-Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
}

void alta(){
	int i;
	i=ultimo+1;
	if(i < MAX_LIBROS){
		modificar(i);
		ultimo++;
	}
}

void modificar (int indice) {
	int i = indice;

	printf("\tLIBRO \n");
	printf("Nombre: ");
	gets(libros[i].nombre);
	printf("Autor: ");
	gets(libros[i].autor);
	printf("Precio: ");
	scanf("%f", &libros[i].precio);
	printf("Año publicación: ");
	scanf("%d", &libros[i].anioPublicacion);
}

void baja () {
	int indice;
	int i;

	printf("\tBAJA\n");
	printf("Indice del registro: ");
	scanf("%d", &indice);

	if(indice < ultimo){
		for (i = indice; i < ultimo; i++) {
			libros[i] = libros[i+1];
		}
		ultimo--;
	}
}

void listar(){
	int i;
	for (i = 0; i <= ultimo; i++){
		printf("Nombre%s\n", libros[i].nombre);
		printf("Nombre%s\n", libros[i].autor);
		printf("Nombre%f\n", libros[i].precio);
		printf("Nombre%d\n", libros[i].anioPublicacion);
	}
}
void limpiarRegistro(int indice) {
	int i =  indice;

	strcpy(libros[i].nombre, "");
	strcpy(libros[i].autor, "");
	libros[i].precio = 0;
	libros[i].anioPublicacion = 0;
}

void inicializa(){
	ultimo = -1;
}