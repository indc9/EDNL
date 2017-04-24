#include <iostream>
#include "agen.h"
#include "agen_E-S.h"

using namespace std;

template <typename T>
int profundidadNodo(const Agen<T>& A, typename Agen<T>::nodo n)
{
    if(n == A.NODO_NULO)
        return 0;
    else
    {
        if(A.padre(n) != A.NODO_NULO)
            return 1 + profundidadNodo(A, A.padre(n));
        else
            return 0;
    }
}
