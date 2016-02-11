#include <stdio.h>

#define MAXIMO 100

int main(){
	int i;
	int suma=0;
	for (i=2; i < MAXIMO; i+=3) {
		suma+=i;
	}
	printf("%i\n", suma);
	return 0;
}