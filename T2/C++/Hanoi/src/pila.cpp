#include "pila.h"
#include <iostream>

using namespace std;

Pila::Pila()
{
    tope = -1;
}

void Pila::apila(int elemento){
    datos[++tope]=elemento;
}

int Pila::desapila(){
    return datos[tope--];
}

void Pila::imprimirPila(){
    for (int i=0; i <= tope; i++) {
        cout << " " << datos[i];
    }
}
