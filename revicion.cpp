#include "revicion.h"
void cargarRevision (revicion &rev){
    strings s;
    Fecha Aux;

    Aux.anio=0;
    Aux.mes=0;
    Aux.dia=0;

    CargarFecha(rev.fecRealizado);
    if(fechaIgualMenor(Aux,rev.fecRealizado)){
        Aux.anio=DarDia(rev.fecRealizado);
        Aux.mes=DarMes(rev.fecRealizado);
        Aux.dia=DarAnio(rev.fecRealizado);
        if(EsValida(rev.fecRealizado)){
            printf("Ingrese el motivo de la revision: ");
            fflush(stdin);
            strcrear(s);
            scan(s);
            strcrear(rev.motivoRev);
            strcop(rev.motivoRev, s);
            strdestruir(s);
            printf("Ingrese el codigo del expediente: ");
            scanf("%ld",&rev.codigo);
            cargarEstado(rev.est);
        }
    }
}

void mostrarRevision(revicion rev){
    MostrarFecha(rev.fecRealizado);
        printf(" Motivo: ");

    print(rev.motivoRev);
        printf(". Codigo: ");

    printf("%ld",rev.codigo);
        printf(". Estado: ");

    mostrarEstado(rev.est);
    printf("\n");
}

void darMotivo(revicion rev, strings &s){
    strcop(s, rev.motivoRev);
}
long int darCodigoRev(revicion rev){
    return rev.codigo;
}
estado darEstado(revicion rev){
    return rev.est;
}

void bajarRevision(revicion rev, FILE * f){
    fwrite(&rev.fecRealizado, sizeof(int), 3, f);
    bajarString(rev.motivoRev, f);
    fwrite(&rev.codigo, sizeof(long int), 1, f);
    fwrite(&rev.est, sizeof(estado), 1, f);
}

void levantarRevision(revicion &rev, FILE * f){
    fread(&rev.fecRealizado,sizeof(int), 3, f);
    strcrear(rev.motivoRev);
    levantarString(rev.motivoRev, f);
    fread(&rev.codigo, sizeof(long int), 1, f);
    fread(&rev.est, sizeof(estado), 1, f);
}
