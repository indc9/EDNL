#include <iostream>
#include <fstream>
#include <algorithm>
#include "abin.h"
#include "abin_E-S.h"

// 2. Construir el arbol reflejado (Ar) de un arbol dado (A)
// cambiando los subarboles izquierdo y derecho en cada nodo.

using namespace std;

template <typename T>
void reflejadoB_rec(const Abin<T>& A, typename Abin<T>::nodo n1,
                       Abin<T>& B, typename Abin<T>::nodo n2)
{
    if(A.hijoIzqdoB(n1) != A.NODO_NULO)
    {
        B.insertarHijoDrchoB(n2, A.elemento(A.hijoIzqdoB(n1)));
        return reflejadoB_rec(A, A.hijoIzqdoB(n1), B, B.hijoDrchoB(n2));
    }

    if(A.hijoDrchoB(n1) != A.NODO_NULO)
    {
        B.insertarHijoIzqdoB(n2, A.elemento(A.hijoDrchoB(n1)));
        return reflejadoB_rec(A, A.hijoDrchoB(n1), B, B.hijoIzqdoB(n2));
    }
}

template <typename T>
Abin<T> reflejadoB(const Abin<T>& A)
{
    Abin<T> B;

    if(!A.arbolVacioB())
    {
        B.insertarRaizB(A.elemento(A.raizB()));
        reflejadoB_rec(A, A.raizB(), B, B.raizB());
    }

    return B;
}




