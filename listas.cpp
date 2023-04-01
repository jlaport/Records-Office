#include "listas.h"

void crearLista (lista &L){
    L = NULL;
}

void insFront (lista & L, revicion e){
    lista aux = new nodos;
    aux -> info = e;
    aux -> sig = L;
    L = aux;
}

void CargarLista(lista &L,arbol a,revicion rev){
    if(a!= NULL){
        if((a->info.codigo==rev.codigo) && (fechaIgualMenor(a->info.fech,rev.fecRealizado))){
                insFront(L,rev);
        }
        else
            if(rev.codigo > a->info.codigo){
                CargarLista(L,a->hder,rev);
            }
            else
                CargarLista(L,a->hizq,rev);
    }
}

void cargLista2(lista L, lista &L2){
    while(L!=NULL){
        L2=L;
        L=L->sig;
        L2=L2->sig;
    }
}

void imprimirRevisiones(lista L){

    while(L!=NULL){
        mostrarRevision(L->info);
        L=L->sig;
    }
}

void ImprimirRevisionesXcodigo(lista L,long int x){
    while(L!= NULL){
        if(L->info.codigo == x){
            mostrarRevision(L->info);
            printf("\n");
            L=L->sig;
        }
        else
            L=L->sig;
    }
}

int RevisionesXFechas(lista L, Fecha f1, Fecha f2){
    int contador=0;

    if(EsValida(f1)&& EsValida(f2)){
        if(fechaIgualMenor(f1,f2)){
            while(L!=NULL){
                if((DeFechaaSumaTotal(L->info.fecRealizado) >= DeFechaaSumaTotal(f1)) && ((DeFechaaSumaTotal(L->info.fecRealizado) <= DeFechaaSumaTotal(f2)))) {
                    contador++;
                    L=L->sig;
                }
                else
                    L=L->sig;
            }
        }
    }
    return contador;
}

boolean vacia (lista L){
    boolean es = FALSE;

    if (L == NULL)
        es = TRUE;
    return es;
}

void insBack(lista &L, revicion rev){
    if (L == NULL) {
        L = new nodos;
        L -> info = rev;
        L -> sig = NULL;
    } else insBack(L->sig, rev);
 }

void cantRevicionesEst (lista L, int &x,int &y,int &z){
    while(L!=NULL){
        if(L->info.est==SATISFACTORIA){
            x++;
        }
        if(L->info.est==INCOMPLETO){
            y++;
        }
        if(L->info.est==PENDIENTE){
            z++;
        }
        L=L->sig;
    }

}

void BorrarOcurrencias (lista &L, long int e)
{
    if (L != NULL)
    {
        if (e == L->info.codigo)
        {
            lista aux = L;
            L = L -> sig;
            delete aux;
            BorrarOcurrencias (L, e);
        }
        else
            BorrarOcurrencias (L -> sig, e);
    }
}

long int ExpedienteConMasRevisiones(lista L, lista L2){
    int contador=0, contadorfin=0;
    long int codigoin=0,codigofin=0;
    while(L!= NULL){
        codigoin = (darCodigoRev(L->info));
        L=L->sig;
        while(L2!=NULL){
            if(codigoin == darCodigoRev(L2->info))
                contador++;
            L2=L2->sig;
        }
        if(contadorfin < contador){
            contadorfin = contador;
            codigofin = codigoin;
        }
    }
    contador=0;
    return codigofin;
}

void bajarLista(lista L , strings nomArch){
    FILE * f=fopen(nomArch, "wb");
    while (L != NULL) {
        bajarRevision(L->info, f);
        L =L -> sig;
    }
    fclose (f);
}

void levantarLista(lista &L, strings nomArch){
    FILE * f=fopen(nomArch,"rb");
    revicion buffer;
    crearLista(L);
    levantarRevision(buffer, f);
    while (!feof(f)) {
        insBack(L,buffer);
        levantarRevision(buffer, f);
    }
    fclose(f);
}
