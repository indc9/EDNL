#include <iostream>
#include <fstream>
#include <algorithm>
#include "abin.h"
#include "abin_E-S.h"

//7. Implemente un subprograma que determine si un árbol binario
// es o no pseudocompleto.
// Pseudocompleto = Penultimo nivel del árbol cada nodo tiene dos hijos o ninguno

template <typename T>
bool pseudocompletoB(const Abin<T>& A)
{
    if(A.arbolVacioB())
        return true;
    else
        if(A.hijoIzqdoB(A.raizB()) == A.NODO_NULO && A.hijoDrchoB(A.raizB()) == A.NODO_NULO)
            return true;
        else
            return pseudocompletoB_rec(A, A.raizB());
}

template <typename T>
bool pseudocompletoB_rec(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(A.altura_nodo(A.raizB()) - 1 == A.profundidad_nodo(n))
        return comprobar_Pseudocompleto(A, n);

    if(A.altura_nodo(A.hijoIzqdoB(n)) > A.altura_nodo(A.hijoDrchoB(n)))
        return pseudocompletoB_rec(A, A.hijoIzqdoB(n));
    else
        if(A.altura_nodo(A.hijoDrchoB(n)) > A.altura_nodo(A.hijoIzqdoB(n)))
            return pseudocompletoB_rec(A, A.hijoDrchoB(n));
        else
            return pseudocompletoB_rec(A, A.hijoIzqdoB(n)) && pseudocompletoB_rec(A, A.hijoDrchoB(n));
}

template <typename T>
bool comprobar_Pseudocompleto(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(A.hijoIzqdoB(n) != A.NODO_NULO && A.hijoDrchoB(n) != A.NODO_NULO)
        return true;
    else
        if(A.hijoIzqdoB(n) == A.NODO_NULO && A.hijoDrchoB(n) == A.NODO_NULO)
            return true;
        else
            return false;
}



