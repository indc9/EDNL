#include <iostream>
#include <fstream>
#include <algorithm>
#include "abin.h"
#include "abin_E-S.h"

//3. Implementa un subprograma que, dados un arbol binario y un nodo del mismo,
//determine la profundidad de este nodo en dicho arbol

using namespace std;

template <typename T>
int profundidadRecB(const Abin<T>& A, typename Abin<T>::nodo n)
{

        if(n == A.raizB())
            return 0;
        else
            return 1 + profundidadRecB(A, A.padreB(n));
}

template <typename T>
int profundidadB(const Abin<T>& A, typename Abin<T>::nodo n)
{
    return profundidadRecB(A, n);
}


