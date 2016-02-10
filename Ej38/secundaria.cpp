#include <iostream>

using namespace std;

int main() {
	int cantAlumnos, edad;
	int cantMayor15=0, cant15=0, cant14=0, cant13=0, cant12=0;
	int cantMuj=0, cantHom=0;
	char sexo;
	bool formValido;

	cout << "Puede indicarme la cantidad de alumnos que ingresara? " << endl;
	cin >> cantAlumnos;

	for (int i=0; i < cantAlumnos; i++) {
		cout << "\tAlumno " << i << endl;
		do{
			cout << "Edad: ";
			cin >> edad;
			if(edad > 0) {
				formValido==true;
			}
			else {
				formValido==false;
			}
		} while(!formValido);
		
		cout << "Sexo: ";
		cin >> sexo;

		if(sexo == 'H'){
			cantHom++;
		} else {
			if(sexo == 'M'){
				cantMuj++;
			}
		}

		if(edad > 15) {
			cantMayor15++;
		}
		else {
			if(edad == 15) {
				cant15++;
			}
			else {
				if(edad == 14) {
					cant14++;
				}
				else {
					if(edad == 13) {
						cant13++;
					}
					else {
						if (edad == 12) {
							cant12++;
						}
					}
				}
			}
		}
	}
}