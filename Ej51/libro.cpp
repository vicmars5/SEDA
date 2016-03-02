/*
 * Autor UnoCuatro
 */
#include <iostream>

#define MAX_LIBROS 128 

using namespace std;

typedef struct {
	string nombre;
	string autor;
	float precio;
	int publicacion; //Año de publicacion
	string codigo;
} Libro;

int ultimo;
Libro libros[MAX_LIBROS];

void inicializa ();
void alta ();
Libro formulario ();
void modificar ();
void baja ();
void consulta ();
void listar();
int obtenPosicion(string);
int elegirOpcionMenu ();

int main (){
	int salir = 0;
	do{
		switch (elegirOpcionMenu()) {
			case 1:
				alta();
				break;
			case 2:
				baja();
				break;
			case 3:
				consulta();
				break;
			case 4:
				modificar();
				break;
			case 5:
				listar();
				break;
			case 0:
				salir = 1;
				break;
			default:
				cout << "Opcion no valida" << endl;
				break;

		}
	} while (salir == 0);
	return 0;
}

void inicializa (){
	ultimo = -1;
}
void alta() {
	if(ultimo < MAX_LIBROS - 1){
		Libro l;
		cout << "\tALTA " << endl;
		l = formulario();
		ultimo++;
		libros[ultimo]=l;
	} else {
		cout << "ERROR. Se ha alcanzado el maximo de libros." << endl;
	}
}

Libro formulario () {
	Libro l;
	bool valido;

	cout << "Nombre: ";
	getline(cin, l.nombre);

	cout << "Autor: ";
	getline(cin, l.autor);

	do{	
		cout << "Precio";
		cin >> l.precio;
		cin.ignore();

		if(l.precio > 0) {
			valido = true;
		} else {
			valido = false;
		}
		
	} while (!valido);

	cout << "Publicacion: ";
	cin >> l.publicacion;

	do{
		cout << "Codigo: ";
		getline(cin, l.codigo);
		
		if(obtenPosicion(l.codigo) >= 0){
			valido = true;
		} else {
			valido = false;
		}

	} while (!valido);
	return l;
}

void modificar () {

}

void baja () {

}

void consulta () {

}

void listar () {

}

int obtenPosicion (string & c){
	int posicion = -1;
	for (int i = 0; i <= ultimo; i++) {
		if(libros[i].codigo == c) {
			posicion = i;
			break;
		}
	}
	return posicion;
}

int elegirOpcionMenu () {
	int op;

	cout << "MENU " << endl
			<< "1.-Nuevo libro" << endl
			<< "2.-Eliminar libro" << endl
			<< "3.-Ver libro" << endl
			<< "4.-Modificar libro" << endl
			<< "5.-Listado de libros" << endl
			<< "0.-Salir" << endl
			<< "Opcion: ";
	cin >> op;
	return op;
}