#include <stdio.h>

#define LARGO_CADENA 40
#define VACIO '\0'
/*
 * Ejercicio 52
 * Autor UnoCuatro
 * Tiempo 00:30
 */
int main () {

	char cadena[LARGO_CADENA];
	int largo;

	printf("Escribe el nombre de la cadena: \n");
	fgets(cadena, LARGO_CADENA, stdin);


	largo = 0;
	while (cadena[largo] != VACIO) {
		largo++;
	}

	printf("Largo %d\n", largo);

	return 0;
}
