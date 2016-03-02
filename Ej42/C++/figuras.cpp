#include <iostream>
#include <cmath>

using namespace std;

/*
 * Autor: UnoCuatro
 */
float areaCirculo() {
	float r;
	cout << "\tCirculo" << endl
			<< "Radio: ";
	cin >> r;
	
	return M_PI * pow(r, 2);
}

float areaCuadrado() {
	float l;
	cout << "\tCuadrado" << endl
			<< "Lado: ";
	cin >> l;
	
	return pow(l, 2);
}

float areaRectangulo() {
	float b,h;
	cout << "\tRectangulo" << endl
			<< "Base: ";
	cin >> b;
	cout << "Altura: ";
	cin >> h;
	
	return b * h;
}

float areaTriangulo() {
	float b,h;
	cout << "\tTriangulo" << endl
			<< "Base: ";
	cin >> b;
	cout << "Altura: ";
	cin >> h;

	return (b * h) / 2;
}
void menu(){
	short op;
	float area;
	bool repetir=true;

	do{
		cout << "\tCALCULAR AREA DE: " << endl
				<< "1.-Circulo " << endl
				<< "2.-Cuadrado " << endl
				<< "3.-Rectangolo " << endl
				<< "4.-Triangulo" << endl
				<< "0.-Salir" << endl;
		cin >> op;
		cout << endl;

		switch(op){
			case 1:
				area = areaCirculo();
				break;
			case 2:
				area = areaCuadrado();
				break;
			case 3:
				area = areaRectangulo();
				break;
			case 4:
				area = areaTriangulo();
				break;
		}

		if(op!=0){
			cout << "Area: " << area << endl << endl;
		} else {
			cout << "Fin";
			repetir = false;
		};

	}while(repetir);
}

int main (){
	menu();
	return 0;
}