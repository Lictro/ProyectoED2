#include "tabla.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "listcampos.h"
#include "bloquecampo.h"
#include "datafile.h"
#include "bloqueregistro.h"
#include "registro.h"
#include "campodatos.h"
#include "listregistros.h"

using namespace std;

tabla::tabla(char name[20],int i,int pBCampos,int actualBCampos,int pBDatos,int actualBDatos,int nB)
{
    strncpy(nombre,name,20);
    id=i;
    primerBloqueCampos=pBCampos;
    actualBloqueCampos=actualBCampos;
    primerBloqueDatos=pBDatos;
    actualBloqueDatos=actualBDatos;
    nBloque=nB;
    sig=0;
    campos= new ListCampos();
    registros= new ListRegistros();
}


char * tabla::toChar()
{
    char * data= new char[44];
    int pos=0;
    memcpy(&data[pos],nombre,20);
    pos+=20;
    memcpy(&data[pos],&id,4);
    pos+=4;
    memcpy(&data[pos],&primerBloqueCampos,4);
    pos+=4;
    memcpy(&data[pos],&actualBloqueCampos,4);
    pos+=4;
    memcpy(&data[pos],&primerBloqueDatos,4);
    pos+=4;
    memcpy(&data[pos],&actualBloqueDatos,4);
    pos+=4;
    memcpy(&data[pos],&nBloque,4);
    pos+=4;
    return data;
}

void tabla::charToTabla(char * data)
{
    int pos=0;
    memcpy(nombre,&data[pos],20);
    pos+=20;
    memcpy(&id,&data[pos],4);
    pos+=4;
    memcpy(&primerBloqueCampos,&data[pos],4);
    pos+=4;
    memcpy(&actualBloqueCampos,&data[pos],4);
    pos+=4;
    memcpy(&primerBloqueDatos,&data[pos],4);
    pos+=4;
    memcpy(&actualBloqueDatos,&data[pos],4);
    pos+=4;
    memcpy(&nBloque,&data[pos],4);
    pos+=4;
}

void tabla::cargarCampos(DataFile * archivo)
{
    int actual=primerBloqueCampos;
    while(actual!=-1)
    {
        BloqueCampo *bc= new BloqueCampo(archivo,actual);
        bc->cargar();
        for(int c=0;c<bc->cantidad;c++)
        {
            campos->add(bc->campos->get(c));
        }
        actual=bc->siguiente;
    }
}

void tabla::cargarRegistros(DataFile * archivo)
{
    int actual=primerBloqueCampos;
    while(actual!=-1)
    {
        BloqueRegistro *br= new BloqueRegistro(archivo,actual);
        br->cargar();
        int longitudReg=this->getLongitudRegistros();
        for(int c=0;c< br->cantidad;c++)
        {
            registros->add(interpretarRegistro("",longitudReg));
        }
        actual=br->siguiente;
    }
}

Registro * tabla::interpretarRegistro(char * data,int longitud)
{
    int pos=0;
    Registro * reg= new Registro();
    for(int c=0;c<campos->cantidad;c++)
    {
        CampoDatos * campDatos= new CampoDatos();
        campo * defCampo= campos->get(c);
        campDatos->defCampos=defCampo;
        campDatos->valor=&data[pos];
        pos+=defCampo->longitud;
        reg->campoDatos->add(campDatos);
    }
    return reg;
}

int tabla::getLongitudRegistros()
{
    int sum=0;
    for(int c=0;c<campos->cantidad;c++)
    {
        sum+=campos->get(c)->longitud;
    }
    return sum;

}

void tabla::toString()
{
    cout<<"Nombre: "<<nombre<<"  ID: "<<id<<"  PrimerBloqueCampo: "<<primerBloqueCampos<<"  ActualBloqueCampo: "<<actualBloqueCampos<<"  PrimerBloqueDatos: "<<primerBloqueDatos<<"  ActualBloqueDatos: "<<actualBloqueDatos<<"  Numero de Bloque: "<<nBloque<<endl<<endl;
}

