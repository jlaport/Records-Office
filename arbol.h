#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "expediente.h"

typedef struct nodoA{
    expediente info; // de xpediente
    nodoA *hizq;
    nodoA *hder;
}nodo;
typedef nodo *arbol;


void crear (arbol &a);

boolean esVacio (arbol a);

int darRaiz (arbol a);  //da el codigo de la raiz

arbol hijoIzquierdo (arbol a);

arbol hijoDerecho (arbol a);

void cons (arbol i, arbol d, int valor, arbol &a);

arbol cons (arbol i, arbol d, int valor);

void orden(arbol a); // en orden
int contarNodos(arbol a);// cantidad de expedientes

boolean pertenece (arbol a, expediente exp);  // compara un codigo del expediente si esta o no en el arbol

void Insert (arbol &a, expediente exp); // inserta el codigo del expediente en el arbol, como long int

boolean perteneceXcodigo (arbol a, long int x);

long int minValue (arbol a); // muestra el exoediente mas de codigo mas chico

void listElem (arbol a); // muestra los codigos que no son mod 2

long int maxValue (arbol a); // muestra el codigo mas grande de expediente

int cantExpe(arbol a, strings ape);

long int Minimo(arbol a);

void Borrar_Minimo(arbol &a); //Tambien tine que borrar las revisiones de ese codigo

void Borrar(long int x, arbol &a);

int ContarXApellido(arbol a,strings ape); //Listar todo en linea. Lista los expedientes por codigo y los cuneta

void ListarEscribanoXApellidoNombre(arbol a, strings nombre, strings apellido);

void mostrarExpeMax(arbol a);

void mostrarExpeMin(arbol a);

void BajarArbolAux(arbol a, FILE *f);

void BajarArbol(arbol a, strings NombreArchivo);

void LevantarArbol(arbol &a, strings NombreArchivo);
#endif // ARBOL_H_INCLUDED
