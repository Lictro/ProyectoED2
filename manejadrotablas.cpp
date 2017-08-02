#include "manejadrotablas.h"
#include "listbloquetablas.h"
#include "listtabla.h"
#include "bloquetabla.h"
#include "tabla.h"
#include "manejadordebloques.h"
#include "bloque.h"
#include <iostream>
#include "masterblock.h"
using namespace std;


ManejadroTablas::ManejadroTablas(DataFile *a,MasterBlock * masterBlock)
{
    archivo=a;
    listaBT= new ListBloqueTablas();
    if(masterBlock->primerBloqueTabla!=-1)
        cargarBT();
}

void ManejadroTablas::crearTabla(char name[20],int id,ManejadordeBloques * manejador)
{
    tabla * t = new tabla(name,id,0,0,0,0,0);
    if(manejador->masterBlock->primerBloqueTabla==-1)
    {
        BloqueTabla * bt= new BloqueTabla(archivo,0);
        bt->tablas->addTabla(t);
        bt->actualizarCantidad();
        bt->escribir();
        listaBT->addBT(bt);
        manejador->masterBlock->actualBloqueTabla=0;
        manejador->masterBlock->primerBloqueTabla=0;
        manejador->masterBlock->guardar();
        return;
    }
    //Meto la tabla en la lista de algun bloque tabla
    int op=0;
    for(int x=0;x<listaBT->cantidad;x++)
    {
        BloqueTabla * bt=listaBT->get(x);
        int maximo = 11;
        if(bt->cantidad<maximo)
        {
            t->nBloque=bt->nBloque;
            bt->tablas->addTabla(t);
            bt->actualizarCantidad();
            bt->escribir();
            return;
        }
        op=x;
    }

    Bloque * b =manejador->asignarNueboBloque();
    BloqueTabla * bt=listaBT->get(op);
    bt->siguiente=b->nBloque;
    bt->escribir();
    BloqueTabla * tmp= new BloqueTabla(b->archivo,b->nBloque);
    t->nBloque=tmp->nBloque;
    tmp->tablas->addTabla(t);
    tmp->actualizarCantidad();
    tmp->escribir();
    manejador->masterBlock->actualBloqueTabla=tmp->nBloque;
    manejador->masterBlock->guardar();
    listaBT->addBT(tmp);

}

void ManejadroTablas::listarTablas()
{
    for(int x=0;x<listaBT->cantidad;x++)
    {
        BloqueTabla * bt=listaBT->get(x);
        for(int c=0;c<bt->cantidad;c++)
        {
            tabla * t=bt->tablas->get(c);
            //printf(t->nombre);
            //printf("\n");
            //cout<<t->nombre<<endl;
            t->toString();
        }
    }
}

tabla * ManejadroTablas::buscarTabla(char *name)
{
    for(int x=0;x<listaBT->cantidad;x++)
    {
        BloqueTabla * bt=listaBT->get(x);
        for(int c=0;c<bt->tablas->cantidad;c++)
        {
            tabla * t=bt->tablas->get(c);
            if(t->nombre==name)
                return t;
        }
    }
    return 0;
}

void ManejadroTablas::cargarBT()
{
    int actual=0;
    BloqueTabla * bloque= new BloqueTabla(archivo,actual);
    bloque->cargar();
    listaBT->addBT(bloque);
    while(bloque->siguiente !=-1)
    {
        actual=bloque->siguiente;
        bloque= new BloqueTabla(archivo,actual);
        bloque->cargar();
        listaBT->addBT(bloque);
    }
}
