#include <iostream>
#include "agen.h"
#include "agen_E-S.h"

// Ejercicio 4. Dado un árbol general de enteros A y un entero x, implementa
// un subprograma que realice la poda de A a partir de x.
// Se asume que no hay elementos repetidos en A.

using namespace std;

template <typename T>
void podaArbol(Agen<T>& A, int num)
{
    if(A.raiz() != A.NODO_NULO)
        podaArbolRec(A, A.raiz(), num);
}

template <typename T>
void podaArbolRec(Agen<T>& A, typename Agen<T>::nodo n, int num)
{
    bool encontrado = false;

    typename Agen<T>::nodo hijo = n;

    while(hijo != A.NODO_NULO && !encontrado)
    {
        if(A.elemento(hijo) == num)
        {
            encontrado = true;
            eliminarHijos(A, hijo);
        }
        else
            podaArbolRec(A, A.hijoIzqdo(hijo), num);
            hijo = A.hermDrcho(hijo);
    }
}

template <typename T>
void eliminarHijos(Agen<T>& A, typename Agen<T>::nodo n)
{
    if(n != A.NODO_NULO)
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != A.NODO_NULO) {
            eliminarHijos(A, hijo);
            hijo = A.hermDrcho(hijo);
            A.eliminarHijoIzqdo(n);
        }
    }
}

