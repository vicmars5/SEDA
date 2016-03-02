#ifndef PILA_H
#define PILA_H


template <class T, int arraySize=1024>
class Pila
{
    public:
        Pila();
        bool estaVacia();
        bool estaLlena();

        void apilar(const T&);
        T tope(); //Top



    protected:
        T datos[arraySize];
        int ultimo;
    private:
};

#endif // PILA_H
