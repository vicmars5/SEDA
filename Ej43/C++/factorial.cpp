#include <iostream>

using namespace std;

int factorial (const int& entero){
	int factorial;
	if(entero < 0){
		factorial=-1;
	}
	else {
		if(entero == 0) {
			factorial=1;
		} else {
			factorial=entero;
			for(int i=entero-1; i > 0; i--){
				factorial*=i;
			}
		}
	}

	return factorial;
}
int main (){
	int entero;
	cout << "Calculo de factorial" << endl
			<< "Numero entero: ";
	cin >> entero;

	cout << endl << "Factorial: " << factorial(entero) << endl;
	return 0;
}