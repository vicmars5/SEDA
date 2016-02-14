#include <stdio.h>

#define MAXIMO 100

int main(){
	int i;
	int suma=0;
	for (i=2; i < MAXIMO; i+=3) {
		suma+=i;
	}
	printf("\tSuma de cada tercer entero desde el dos\n");
	printf("Suma: %i\n", suma);
	return 0;
}