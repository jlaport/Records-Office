#include "expediente.h"

void cargarExpe( expediente &exp){
    strings s;
    printf("Ingrese el codigo del expediente:");
    scanf("%ld",&exp.codigo);
    printf("Ingrese la caratula:");
    fflush(stdin);
    strcrear(s);
    strcrear(exp.caratula);
    scan(s);
    strcop(exp.caratula,s);
    CargarFecha(exp.fech);
    while(!EsValida(exp.fech)){
        printf("Ingrese una fecha valida.");
        CargarFecha(exp.fech);
    }
    fflush(stdin);
    cargarEscri(exp.esc);
    printf("Ingrese la cantidad de paginas: ");
    scanf("%d",&exp.cantpag);
    strdestruir(s);


}


void mostrarExpe( expediente exp){
    printf("Codigo: ");
    printf("%ld",exp.codigo);
    printf(" Caratula: ");
    print(exp.caratula);
    printf(". ");
    MostrarFecha(exp.fech);

    mostrarEscri(exp.esc);
    printf(". Cantidad de paginas: ");

    printf("%d",exp.cantpag);
    printf("\n");

}

long int darCodigo(expediente exp){
    return exp.codigo;
}
void darCaratula(expediente exp, strings &s){
    strcop(s,exp.caratula);
}


int darCantpaginas(expediente exp){
    return exp.cantpag;
}

void bajarExpediente(expediente exp, FILE *f){
    fwrite(&exp.codigo, sizeof(long int),1,f);
    bajarString(exp.caratula,f);
    fwrite(&exp.fech,sizeof(int),3,f);
    bajarString(exp.esc.nombre,f);
    bajarString(exp.esc.apellido,f);
    fwrite(&exp.cantpag,sizeof(int),1,f);
}

void levantarExpediente(expediente &exp,FILE *f){
    fread(&exp.codigo,sizeof(long int),1,f);
    strcrear(exp.caratula);
    levantarString(exp.caratula,f);
    fread(&exp.fech,sizeof(int),3,f);
    strcrear(exp.esc.nombre);
    levantarString(exp.esc.nombre,f);
    strcrear(exp.esc.apellido);
    levantarString(exp.esc.apellido,f);
    fread(&exp.cantpag,sizeof(int),1,f);
}
