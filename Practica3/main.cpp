#include <iostream>
#include <fstream>
#include "agen.h"
#include "agen_E-S.h"
#include "grado.hpp"
#include "profundidad.hpp"
//#include "desequilibrio.hpp"
#include "poda.hpp"

using namespace std;

typedef int tElto;
const tElto fin = -1; // fin de lectura

int main ()
{
    Agen<tElto> A, B;

    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin

    ofstream fs("agen.dat"); // Abrir fichero de salida.
    imprimirAgen(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";

    //Ejercicio 1
    int grado = gradoArbol(A);
    cout << "El arbol A tiene grado : " << grado << endl;
    //Ejercicio 2
    Agen<tElto>::nodo n = A.hijoIzqdo(A.hermDrcho(A.hijoIzqdo(A.raiz())));
    int prof = profundidadNodo(A, n);
    cout << "El arbol A tiene profundidad : " << prof << endl;
    /*//Ejercicio 3
    int desequilibrio = desequilibrioArbol(A);
    cout << "El arbol A tiene un grado de desequilibrio de : " << desequilibrio << endl;*/
    //Ejercicio 4
    podaArbol(A, 4);            //Se le pasa el entero a partir el cuál podar.
    imprimirAgen(A);

}
