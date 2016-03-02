#include <iostream>

#define TAM_MATRIZ 3 
#define MATRICES 3
#define CANT_CELDAS TAM_MATRIZ*TAM_MATRIZ

/*
 *Autor UnoCuatro
 */
 
using namespace std;

void inicializa(const int&);
void mostrarMatrices();
void multiplicarMatrices();

int matrices[MATRICES][TAM_MATRIZ][TAM_MATRIZ];

int main(){
	int inicio;
	cout << "\tMultiplicación matricial" << endl
			<< "Valor inicial: ";
	cin >> inicio;
	cin.ignore();
	cout << endl << endl;

	inicializa(inicio);
	multiplicarMatrices();
	mostrarMatrices();
	
	return 0;
}

void inicializa(const int& inicio){
	int valor = inicio;
	int i, j;

	for (i = 0; i < TAM_MATRIZ; i++){
		for (j = 0; j < TAM_MATRIZ; j++){
			matrices[0][i][j]=valor;
			matrices[1][i][j]=valor+CANT_CELDAS;
			valor++;
		}
	}
}

void mostrarMatrices() {
    int i, j, mat;
    for (mat = 0; mat < MATRICES; mat++){
        cout << "\tMatriz " << mat+1 << ":" << endl;
        for (i=0; i < TAM_MATRIZ; i++){
            cout << "\t";
            for(j=0; j < TAM_MATRIZ; j++){
                cout << matrices[mat][i][j] << " ";
            }
            cout << endl;
        }
        if(mat==0)        {
            cout << "\n\t    *" << endl;
        }
        else
        {
            if(mat==1)
            {
                cout << "\n\t    =" << endl;
            }
        }
        cout << endl;
    }
}

void multiplicarMatrices() {
    int i, j, k,mat=0;
    int suma;
    for (i=0; i < TAM_MATRIZ; i++)
    {
        for(j=0; j < TAM_MATRIZ; j++)
        {
            for(k=0; k < TAM_MATRIZ; k++)
            {
                suma+=matrices[0][j][k]*matrices[1][k][i];
            }
            matrices[2][j][i]=suma;
            suma=0;
        }
    }
    mat++;

}