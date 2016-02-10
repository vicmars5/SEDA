#include <iostream>
#include <cctype>
using namespace std;

int main() {
	int i;
	int cantAlumnos, edad;
	int cantMayor15=0, cant15=0, cant14=0, cant13=0, cant12=0;
	int cantMuj=0, cantHom=0;
	char sexo;
	bool formValido;

	cout << "Puede indicarme la cantidad de alumnos que ingresara? " << endl;
	cin >> cantAlumnos;
	cin.ignore();

	i=0;
	while(i<cantAlumnos){
		cout << "\tAlumno " << (i+1) << endl;
		do{
			cout << "Edad: ";
			cin >> edad;
			if(edad > 0) {
				formValido=true;
			}
			else {
				formValido=false;
			}
		} while(!formValido);
		do{
			cout << "Sexo (H/M): ";
			cin >> sexo;
			sexo=toupper(sexo);
			if(sexo == 'H' or sexo == 'M') {
				formValido=true;
			}
			else {
				formValido=false;
			}
		} while(!formValido);
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
		cout << endl;
		i++;
	}
	cout << endl;
	cout << "\tESTADISTICAS: " << endl  << endl;
	cout << "\tSexo" << endl;
	cout << "Hombres: \t" << cantHom << endl
			<< "Mujeres: \t" << cantMuj << endl << endl;
	cout << "\tEdad" << endl;
	cout << "Doce \t\t" << cant12 << endl
			<< "Trece \t\t" << cant13 << endl
			<< "Catorce \t" << cant14 << endl
			<< "Quince \t\t" << cant15 << endl
			<< "Mayor quince \t" << cantMayor15 << endl; 
}