#include <iostream>
#include <fstream>
#include <algorithm>
#include "abin.h"
#include "abin_E-S.h"

//2. Implementa un subprograma que calcule la altura de un arbol binario

using namespace std;

template <typename T>
int calcularAlturaRec(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == A.NODO_NULO)
        return -1;
    else
        return 1 + max(calcularAlturaRec(A, A.hijoIzqdoB(n)), calcularAlturaRec(A, A.hijoDrchoB(n)));
}

template <typename T>
int calcularAltura(const Abin<T>& A)
{
    if(A.arbolVacioB())
        return -1;
    else
        return calcularAlturaRec(A, A.raizB());
}

