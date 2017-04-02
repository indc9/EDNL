#include <iostream>
#include <fstream>
#include <algorithm>
#include "abin.h"
#include "abin_E-S.h"

//5. Implemente un subprograma que determine el nivel de desequilibrio de un
// árbol binario. Desequilibrio de un nodo = Diferencia de alturas de los subárboles
// del mismo

template <typename T>
int desequilibrio_arbol(const Abin<T>& A)
{
    assert(A.arbolVacioB());

    return desequilibrio_arbol_rec(A, A.raizB());
}

template <typename T>
int desequilibrio_arbol_rec(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == A.NODO_NULO)
        return 0;
    else
        return std::max( std::max(diferenciaAltura(A, n), desequilibrio_arbol_rec(A, A.hijoIzqdoB(n))),
                         desequilibrio_arbol_rec(A, A.hijoDrchoB(n)) );
}

template <typename T>
int diferenciaAltura(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n != A.NODO_NULO)
        return abs( A.altura_nodo(A.hijoIzqdoB(n)) - A.altura_nodo(A.hijoDrchoB(n)) );
    else
        return 0;
}
