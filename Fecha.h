#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include "Boolean.h"

typedef struct{
    int dia;
    int mes;
    int anio;
} Fecha;

void CargarFecha(Fecha &f);

int DarDia(Fecha f);

int DarMes(Fecha f);

int DarAnio(Fecha f);

void MostrarFecha(Fecha f);

boolean EsValida(Fecha f);

long int DeFechaaSumaTotal(Fecha f);

boolean fechaIgualMenor (Fecha f, Fecha f2);
#endif // FECHA_H_INCLUDED
