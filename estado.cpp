#include"estado.h"

void cargarEstado(estado &est){
    int n=0;
    printf("Ingrese el estado de la revision: \n1-Satisfactoria. \n2- Incompleto. \n3- Pendiente.\n");
    scanf("%d",&n);
    if(n==1)
        est=SATISFACTORIA;
    else if (n==2)
        est=INCOMPLETO;
    else est=PENDIENTE;
}

void mostrarEstado(estado est){
    if(est==SATISFACTORIA)
        printf("Satisfactoria.");
        else if (est==INCOMPLETO)
            printf("Incompleto.");
            else
                printf("Pendiente.");
}

