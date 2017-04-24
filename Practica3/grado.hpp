#include <iostream>
#include "agen.h"
#include "agen_E-S.h"

using namespace std;

template <typename T>
int gradoArbol(const Agen<T>& A)
{
    return gradoArbolRec(A, A.raiz());
}

template <typename T>
int gradoArbolRec(const Agen<T>& A, typename Agen<T>:: nodo n)
{
    int maximo = 0;

    if(n == A.NODO_NULO)
        maximo = 0;
    else
    {
        if(gradoNodo(A, A.hijoIzqdo(n)) < gradoArbolRec(A, A.hijoIzqdo(n)))
            maximo = gradoArbolRec(A, A.hijoIzqdo(n));
        else
            maximo = gradoNodo(A, A.hijoIzqdo(n));
    }

    return maximo;
}

template <typename T>
int gradoNodo(const Agen<T>& A, typename Agen<T>::nodo n)
{
    int cont = 0;

    typename Agen<T>::nodo her = n;

    while(her != A.NODO_NULO)
    {
        cont++;
        her = A.hermDrcho(her);
    }

    return cont;
}
