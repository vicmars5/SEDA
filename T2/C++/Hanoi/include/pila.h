#ifndef PILA_H
#define PILA_H

#define MAXIMO 1024

class Pila
{
    public:
        Pila();

        void apila(int);
        int desapila();
        void imprimirPila();
    protected:
        int tope;
        int datos[MAXIMO];
    private:
};

#endif // PILA_H
