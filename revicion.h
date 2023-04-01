#ifndef REVICION_H_INCLUDED
#define REVICION_H_INCLUDED
#include"stringdinamico.h"
#include"estado.h"
#include"Fecha.h"

typedef struct{
    Fecha fecRealizado;
    strings motivoRev;
    long int codigo;
    estado est;
}revicion;

void cargarRevision (revicion &rev);

void mostrarRevision(revicion rev);

void darMotivo(revicion rev, strings &s);

long int darCodigoRev(revicion rev);

estado darEstado(revicion rev);

void bajarRevision(revicion rev, FILE * f);

void levantarRevision(revicion &rev, FILE * f);
#endif // REVICION_H_INCLUDED
