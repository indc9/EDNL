#include <iostream>
#include <fstream>
#include <algorithm>
#include "abin.h"
#include "abin_E-S.h"

//1. Dos �rboles son similares cuando tienen id�ntica estructura
// de ramificaci�n, es decir, ambos son vac�os, o bien tienen
//subarboles similares. Determina si dos �rboles son similares.

using namespace std;

template <typename T>
int similaresB_rec(const Abin<T>& A, typename Abin<T>::nodo a,
                   const Abin<T>& B, typename Abin<T>::nodo b)
{
    if(a == A.NODO_NULO && b == B.NODO_NULO)
        return true;
    else{
        if(a != A.NODO_NULO && b != B.NODO_NULO)
            return similaresB_rec(A, A.hijoIzqdoB(a), B, B.hijoIzqdoB(b)) && similaresB_rec(A, A.hijoDrchoB(a), B, B.hijoDrchoB(b));
        else
            return false;
    }
}

template <typename T>
int similaresB(const Abin<T>& A, const Abin<T>& B)
{
    return similaresB_rec(A, A.raizB(), B, B.raizB());
}



