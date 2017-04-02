#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"
#include "numNodos.hpp"
#include "altura.hpp"
#include "profundidad.hpp"
#include "desequilibrio.hpp"
#include "pseudocompleto.hpp"

using namespace std;

typedef char tElto;
const tElto fin = '#'; //fin de lectura

int main()
{
    Abin<tElto> A;

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin);   //desde std::cin

    ofstream fs("abin.dat");    //Abrir fichero de salida
    imprimirAbin(fs, A, fin);   //en fichero
    fs.close();
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";

    //Ejercicio 1
    int nodos = numNodos(A);
    cout << "El arbol A tiene " << nodos << " nodos" << endl;
    //Ejercicio 2
    int altura = calcularAltura(A);
    cout << "El arbol A tiene altura " << altura << endl;
    //Ejercicio 3
    int profundidad = profundidadB(A, A.hijoIzqdoB(A.hijoIzqdoB(A.raizB())));
    cout << "El arbol A tiene profundidad " << profundidad << endl;
    //Ejercicio 6
    int desequilibrio = desequilibrio_arbol(A);
    cout << "El arbol A tiene desequilibrio " << desequilibrio << endl;
    //Ejercicio 7
    bool pseudocompleto = pseudocompletoB(A);
    if(pseudocompleto)
        cout << "El arbol A es pseudocompleto" << endl;
    else
        cout << "El arbol A no es pseudocompleto" << endl;

}



