#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"

//1. Implementa un subprograma que calcule el numero de nodos de un arbol binario

template <typename T>
int numNodosRec(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == A.NODO_NULO)
        return 0;
    else
        return 1 + numNodosRec(A, A.hijoIzqdoB(n)) + numNodosRec(A, A.hijoDrchoB(n));
}

template <typename T>
int numNodos(const Abin<T>& A)
{
    if(A.arbolVacioB())
        return 0;
    else
        return numNodosRec(A, A.raizB());
}
