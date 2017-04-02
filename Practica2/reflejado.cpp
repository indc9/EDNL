#include <iostream>
#include <fstream>
#include <stdio.h>
#include "abin.h"
#include "abin_E-S.h"
#include "reflejado.hpp"

using namespace std;

typedef char tElto;
const tElto fin = '#'; //fin de lectura

int main()
{
    Abin<tElto> A, B;

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin);   //desde std::cin

    ofstream fs("abin.dat");    //Abrir fichero de salida
    imprimirAbin(fs, A, fin);   //en fichero
    fs.close();
    cout << "\n*** Arbol A guardado en fichero abin.dat ***\n";

    B = reflejadoB(A);

    cout << "\n*** Arbol B ***\n";
    imprimirAbin(B);
}

