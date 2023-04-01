#include "arbol.h"

void crear (arbol &a)
{
    a=NULL;

}

boolean esVacio (arbol a)
{
    boolean es=TRUE;
    if (a!=NULL)
        es=FALSE;
    return es;
}

int darRaiz (arbol a)
{
    return (a->info.codigo);
}

arbol hijoIzquierdo (arbol a)
{
    return (a->hizq);
}

arbol hijoDerecho (arbol a)
{
    return (a->hder);
}

void orden(arbol a)
{
    if(a!=NULL)
    {
        orden(a->hizq);
        mostrarExpe(a->info);
        orden(a->hder);
    }
}


int contarNodos(arbol a)
{
    int b=0;
    if(a!=NULL)
    {
        return 1 + contarNodos(a->hder)+contarNodos(a->hizq);
    }
    else
        return 0;
}

boolean pertenece (arbol a, expediente exp)
{
    if (a == NULL)
        return FALSE;
    else if (a -> info.codigo == exp.codigo)
        return TRUE;
    else if (exp.codigo < a -> info.codigo)
        return pertenece (a -> hizq, exp);
    else
        return pertenece (a -> hder, exp);
}

boolean perteneceXcodigo (arbol a, long int x)
{
    if (a == NULL)
        return FALSE;
    else if (a -> info.codigo == x)
        return TRUE;
    else if (x < a -> info.codigo)
        return perteneceXcodigo (a -> hizq, x);
    else
        return perteneceXcodigo (a -> hder, x);
}

void Insert (arbol &a, expediente exp)
{
    if(!pertenece(a, exp))
    {
        if (a == NULL)
        {
            a = new nodo;
            a -> info = exp;
            a -> hizq = NULL;
            a -> hder = NULL;
        }
        else
        {
            if (exp.codigo < a->info.codigo)
                Insert (a -> hizq, exp);
            else
                Insert (a -> hder, exp);
        }
    }
    else
        printf("\n Ya pertenece.\n");
}

long int minValue (arbol a)
{
    if (a -> hizq == NULL)
        return a->info.codigo;
    else
        return minValue (a->hizq);
}

void listElem (arbol a)
{
    if(a!=NULL)
    {
        if(a->info.codigo %2!=0)
        {
            listElem(a->hder);
            listElem(a->hizq);
            mostrarExpe(a->info);
        }
        else
        {
            listElem(a->hder);
            listElem(a->hizq);
        }
    }
}

long int maxValue (arbol a)
{
    if(a->hder==NULL)
        return(a->info.codigo);
    else return maxValue(a->hder);
}

int cantExpe(arbol a, strings ape)
{
    strings s;

    if (a == NULL)
        return 0;
    else
    {
        darApellido(a->info.esc, s);

        if (streq(s,ape))
            return 1 + cantExpe(a->hder, ape)+cantExpe(a->hizq,ape);
        else
            return cantExpe(a->hder, ape)+cantExpe(a->hizq, ape);
    }
}

long int Minimo(arbol a)
{
    if(a->hizq == NULL)
        return (a->info.codigo);
    else
        return Minimo(a->hizq);
}

void Borrar_Minimo(arbol &a)
{
    arbol aux;
    if(a->hizq == NULL)
    {
        aux = a-> hder;
        delete a;
        a = aux;
    }
    else
        Borrar_Minimo(a->hizq);
}

void Borrar(long int x, arbol &a)
{
    arbol aux;
    printf("");
    if(perteneceXcodigo(a,x))
    {
        if(x == darCodigo(a->info))
        {
            if(a->hder == NULL)
            {
                aux = a -> hizq;
                delete a;
                a = aux;
            }
            else
            {
                if(a->hizq == NULL)
                {
                    aux = a->hder;
                    delete a;
                    a = aux;
                }
                else
                {
                    a->info.codigo = Minimo(a -> hder);
                    Borrar_Minimo(a->hder);
                }
            }
        }
        else
        {
            if(x < darCodigo(a->info))
                Borrar(x, a->hizq);
            else
                Borrar(x, a->hder);
        }
    }
    else
        printf("\nNo existe en el arbol");
}

int ContarXApellido(arbol a,strings ape){
    int contador=0;
    strings aux;

    strcrear(aux);

    if(a!=NULL)
    {
        darApellido(a->info.esc,aux);
        if(streq(aux,ape)){
            contador++;
            return contador + ContarXApellido(a->hder,ape) + ContarXApellido(a->hizq,ape);
        }
        else
            return contador + ContarXApellido(a->hder,ape) + ContarXApellido(a->hizq,ape);
    }
    else{
        return contador;
    }

    strdestruir(aux);
}

void ListarEscribanoXApellidoNombre(arbol a, strings nombre, strings apellido){
    int contador=0;
    if(a != NULL){
        if(streq(a->info.esc.apellido,apellido)){
            if(streq(a->info.esc.nombre,nombre)){
                mostrarExpe(a->info);
                ListarEscribanoXApellidoNombre(a->hizq,nombre,apellido);
                ListarEscribanoXApellidoNombre(a->hder,nombre,apellido);
            }
            else{
                ListarEscribanoXApellidoNombre(a->hizq,nombre,apellido);
                ListarEscribanoXApellidoNombre(a->hder,nombre,apellido);
            }
        }
        else{
            ListarEscribanoXApellidoNombre(a->hizq,nombre,apellido);
            ListarEscribanoXApellidoNombre(a->hder,nombre,apellido);
        }
    }
}

void mostrarExpeMax(arbol a){
    while(a->hder!=NULL){
        a=a->hder;
    }
    mostrarExpe(a->info);
}
void mostrarExpeMin(arbol a){
    while(a->hizq!=NULL){
        a=a->hizq;
    }
    mostrarExpe(a->info);
}

void BajarArbolAux(arbol a, FILE *f){
    if(a!= NULL){
        bajarExpediente(a->info,f);
        BajarArbolAux(a->hizq,f);
        BajarArbolAux(a->hder,f);
    }
}

void BajarArbol(arbol a, strings NombreArchivo){
    FILE *f=fopen(NombreArchivo,"wb");
    BajarArbolAux(a,f);
    fclose(f);
}

void LevantarArbol (arbol &a, strings NombreArchivo)
{
	FILE * f = fopen (NombreArchivo, "rb");
	expediente buffer;
	crear(a);
	levantarExpediente(buffer,f);
	while (!feof(f))
	{
		Insert(a, buffer);
		levantarExpediente(buffer,f);
	}
	fclose (f);
}
