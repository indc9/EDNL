#include <iostream>
#include <fstream>
#include <stdio.h>
#include "abin.h"
#include "abin_E-S.h"
#include "similares.hpp"

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
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";

    cout << "*** Lectura del árbol binario B ***\n";
    rellenarAbin(B, fin);   //desde std::cin

    ofstream fe("abin2.dat");    //Abrir fichero de salida
    imprimirAbin(fe, B, fin);   //en fichero
    fe.close();
    cout << "\n*** Árbol B guardado en fichero abin2 .dat ***\n";

    //Ejercicio 1
    bool similares = similaresB(A, B);
    if(similares)
        cout << "Los dos arboles son similares" << endl;
    else
        cout << "Los dos arboles no son similares" << endl;

}
