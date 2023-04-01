#include "menu.h"

void Menu (){
int Opcion, op2,x=0,y=0,z=0;
arbol a;
lista l;
lista aux;
expediente exp;
revicion rev;
strings nombre,apellido;
strings ARCExpe = "Expedientes.dat";
strings ARCRevi = "Revisiones.dat";
FILE *f;

crear(a);
crearLista(l);
crearLista(aux);

if(!existe(ARCRevi)){
        bajarLista(l,ARCRevi);
}
levantarLista(l,ARCRevi);
levantarLista(aux,ARCRevi);

if(!existe(ARCExpe)){
    BajarArbol(a, ARCExpe);
}
LevantarArbol(a,ARCExpe);


do{
    printf("\n--MENU--\n");
    printf("\n1. Registrar ingreso de un expediente.");
    printf("\n2. Registrar partida de una revision.");
    printf("\n3. Borrar expediente.");
    printf("\n4. Menu de consultas y listados.");
    printf("\n5. Salir del programa. \n");
    printf("\nIngrese a continuacion la opcion deseada: ");
    scanf("%d",&Opcion);
    switch(Opcion){
        case 1:
            fflush(stdin);
            cargarExpe(exp);
            Insert(a, exp);
            break;
       case 2:
            fflush(stdin);
            cargarRevision(rev);
            CargarLista(l,a,rev);
            CargarLista(aux,a,rev);
            break;
        case 3:
            long int codborr;
            printf("Borrar expediente y sus revisiones");
            printf("Ingrese codigo a borrar:");
            scanf("%ld",&codborr);
            Borrar(codborr,a);
            BorrarOcurrencias(l,codborr);
            BorrarOcurrencias(aux,codborr);

        case 4:
            do{
                printf("\n--MENU LISTADOS Y CONSULTAS--\n");
                printf("\n1. Mostrar todos los expedientes en sistema.");
                printf("\n2. Mostrar expediente con mayor codigo.");
                printf("\n3. Mostrar expediente con menor codigo.");
                printf("\n4. Mostrar todas las revisiones realizadas.");
                printf("\n5. Mostrar revisiones por codigo de expediente");
                printf("\n6. Buscar expedientes por apellido.");
                printf("\n7. Mostrar codigo de expediente con mas revisiones.");
                printf("\n8. Mostrar cantidad de revisiones por rango de fechas.");
                printf("\n9. Cantidad de revisiones segun estado.");
                printf("\n10. Volver al Menu Principal.");
                printf("\nIngrese a continuacion la opcion deseada: ");
                scanf("%d",&op2);
                    switch(op2){
                            case 1:
                                orden(a);
                                break;
                            case 2:
                                if(a != NULL)
                                    mostrarExpeMax(a);
                                else
                                    printf("Error, el arbol esta vacio.");
                                break;
                            case 3:
                                if(a != NULL)
                                   mostrarExpeMin(a);
                                else
                                    printf("Error, el arbol esta vacio.");
                                break;
                            case 4:
                                imprimirRevisiones(l);
                                break;
                            case 5:
                                long int codRev;
                                printf("Ingrese un codigo para buscar:");
                                scanf("%ld",&codRev);
                                ImprimirRevisionesXcodigo(l,codRev);
                                break;
                            case 6:
                                printf("Ingrese el nombre y el apellido del escribano: ");
                                strcrear(nombre);
                                strcrear(apellido);
                                printf("\nNOMBRE: ");
                                fflush(stdin);
                                scan(nombre);
                                printf("\nAPELLIDO: ");
                                fflush(stdin);
                                scan(apellido);
                                ListarEscribanoXApellidoNombre(a,nombre,apellido);
                                strdestruir(nombre);
                                strdestruir(apellido);
                                break;
                            case 7:
                                printf("El codigo con mas revisiones es: %ld",ExpedienteConMasRevisiones(l,aux));
                                break;
                            case 8:
                                Fecha f, f1;
                                printf("\nIngrese la primer fecha: ");
                                CargarFecha(f);
                                while(!EsValida(f)){
                                    printf("Ingrese una fecha valida");
                                    CargarFecha(f);
                                }
                                printf("\nIngrese la segunda fecha: ");
                                CargarFecha(f1);
                                while(!EsValida(f1)){
                                    printf("Ingrese una fecha valida");
                                    CargarFecha(f1);
                                }
                                printf("La cantidad de revisiones por fecha es: %d",RevisionesXFechas(l,f,f1));
                                break;
                            case 9:
                                cantRevicionesEst(l,x,y,z);
                                printf("La cantidad de revisiones por estado son:\nSatisfactorias:%d\nIncompletas:%d\nPendientes:%d",x,y,z);

                                break;
                            case 10:
                                break;
                            default: printf("\n--ERROR FUERA DE RANGO--\n");
                                break;
                        }
                }while(op2 != 10);
            break;
        case 5:
            printf("\n--SALIENDO DEL MENU--\n");
            break;
        default: printf("\n--ERROR FUERA DE RANGO--\n");
                 Opcion = 5;
            break;
    }
}while(Opcion!=5);

BajarArbol(a,ARCExpe);
bajarLista(l,ARCRevi);
}

