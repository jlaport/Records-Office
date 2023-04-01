#include"escribano.h"

void cargarEscri(escrib &esc){
    printf("ingrese el apellido del escribano: ");
    fflush(stdin);
    strcrear(esc.apellido);
    scan(esc.apellido);
    printf("Ingrese el nombre del escribano: ");
    fflush(stdin);
    strcrear(esc.nombre);
    scan(esc.nombre);
}
void mostrarEscri(escrib esc){
    printf(" Apellido del escribano: ");
    print(esc.apellido);
    printf(". Nombre del escribano: ");
    print(esc.nombre);

}

void darApellido(escrib esc, strings &s){
    strcop(s,esc.apellido);

}

void darNombre (escrib esc, strings &s){
    strcop(s, esc.nombre);
}
