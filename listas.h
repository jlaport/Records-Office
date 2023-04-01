#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include"revicion.h"
#include"arbol.h"
#include"archivos.h"

typedef struct nodoL {
    revicion info;
    nodoL * sig;
 } nodos;
typedef nodos * lista;

void crearLista (lista &L);

void insFront(lista &L, revicion e);

void CargarLista(lista &L, arbol a,revicion rev); //cargo la revision a la lista y chequeo que codigo existe y que fecha es valida

void cargLista2(lista L, lista &L2); //iguala las listas

void imprimirRevisiones(lista L);

void ImprimirRevisionesXcodigo(lista L, long int x); //imprimo revisones por codigo

int RevisionesXFechas(lista L, Fecha f1, Fecha f2);

boolean vacia (lista L);

revicion primero (lista L);

void resto (lista &L);

void insBack (lista &L, revicion e);

int largoIter (lista L);

revicion ultimoIter (lista L);

int contarIter ( lista L, revicion a);

boolean perteneceIter (lista L, int a);

int maximoIter(lista L);

void paresImparesIter(lista L,lista &L1,lista &L2);

void insBack(lista &L, revicion rev);

void cantRevicionesEst (lista L, int &x,int &y,int &z);

void BorrarOcurrencias (lista &L, long int e);

long int ExpedienteConMasRevisiones(lista L, lista L2);

void bajarLista(lista L , strings nomArch);

void levantarLista(lista &L, strings nomArch);
#endif // LISTAS_H_INCLUDED
