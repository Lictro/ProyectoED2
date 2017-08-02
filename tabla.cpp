#include "tabla.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
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

void tabla::toString()
{
    cout<<"Nombre: "<<nombre<<"  ID: "<<id<<"  PrimerBloqueCampo: "<<primerBloqueCampos<<"  ActualBloqueCampo: "<<actualBloqueCampos<<"  PrimerBloqueDatos: "<<primerBloqueDatos<<"  ActualBloqueDatos: "<<actualBloqueDatos<<"  Numero de Bloque: "<<nBloque<<endl<<endl;
}

