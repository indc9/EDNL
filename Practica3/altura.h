#include <iostream>
#include "agen.h"

using namespace std;

template <typename T>
int altura(const Agen<T>& A)
{
    if(A.arbolVacio())
        return 0;
    else
        return altura_rec(A.raiz(), A);
}

template <typename T>
int altura_rec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    int altura = -1;

    if(n ==  A.NODO_NULO)
        return -1;
    else
    {

        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != A.NODO_NULO)
        {
            altura = max(altura, altura_rec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + altura;
    }
}

