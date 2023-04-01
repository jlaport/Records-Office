#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED
#include "Fecha.h"
#include "escribano.h"
typedef struct{
    long int codigo;
    strings caratula;
    Fecha fech;
    escrib esc;
    int cantpag;
}expediente;

void cargarExpe( expediente &exp); //carga el esxpediente

void mostrarExpe( expediente exp);// muestra el expediente

boolean estaExpe (expediente exp);//True si existe el expediente

//selectoras
long int darCodigo(expediente exp);

void darCaratula(expediente exp, strings &s);

int darCantpaginas(expediente exp);

void bajarExpediente(expediente exp, FILE *f);

void levantarExpediente(expediente &exp,FILE *f);
#endif // EXPEDIENTE_H_INCLUDED
