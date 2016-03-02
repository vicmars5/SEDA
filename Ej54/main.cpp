#include <stdio.h>

#define LARGO_CADENA 40
#define VACIO '\0'

/*
 * Ejercicio 54
 * Autor UnoCuatro
 * Tiempo 00:35
 */

void miStrcat(char * cadena, const char aConcadenar[]);

int main () {

	char cadena1[LARGO_CADENA] = "hola ",
		cadena2[LARGO_CADENA] = "amigo";
	int largo;

	miStrcat(cadena1, cadena2);
	printf("%s\n", cadena1);

	return 0;
}

void miStrcat(char * cadena, const char aConcadenar[]) {
	int i = 0, j;
	while (cadena[i] != VACIO) {
		i++;
	}
	while (aConcadenar[j] != VACIO) {
		cadena[i++] = aConcadenar[j++];
	}
}