#include "bloqueregistro.h"
#include "datafile.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "listregistros.h"
using namespace std;
BloqueRegistro::BloqueRegistro(DataFile * archivo,int nBloque)
{
    this->archivo=archivo;
    nBloque=nBloque;
    tamBloque=512;
    siguiente=-1;
    cantidad=0;
    registros= new ListRegistros();
}

void BloqueRegistro::escribir()
{
    char * data= this->toChar();
    int pos= nBloque * tamBloque+20;
    archivo->escribir(data,pos,tamBloque);
}

void BloqueRegistro::cargar(int longitud)
{
    int pos= nBloque * tamBloque+20;
    char * data=archivo->leer(pos,tamBloque);
    charToBloque(data,longitud);
}

void BloqueRegistro::charToBloque(char * data,int longitud)
{
    int pos=0;
    memcpy(&nBloque,&data[pos],4);
    pos+=4;
    memcpy(&tamBloque,&data[pos],4);
    pos+=4;
    memcpy(&siguiente,&data[pos],4);
    pos+=4;
    memcpy(&cantidad,&data[pos],4);
    pos+=4;
    for(int c=0;c<cantidad;c++)
    {
        Registro * r= new Registro(longitud);
        r->initFromChar(&data[pos]);
        registros->add(r);
        pos+=longitud;
    }
}

char * BloqueRegistro::toChar()
{
    char * data= new char[tamBloque];
    int pos=0;
    memcpy(&data[pos],&nBloque,4);
    pos+=4;
    memcpy(&data[pos],&tamBloque,4);
    pos+=4;
    memcpy(&data[pos],&siguiente,4);
    pos+=4;
    memcpy(&data[pos],&cantidad,4);
    pos+=4;
    for(int c=0;c<cantidad;c++)
    {
        Registro * r=registros->get(c);
        int x=r->longitudRegistro;
        char * entry_data= r->toChar();
        memcpy(&data[pos],entry_data,x);
        pos+=x;
    }
    return data;
}


