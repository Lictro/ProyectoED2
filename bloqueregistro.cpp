#include "bloqueregistro.h"
#include "datafile.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
BloqueRegistro::BloqueRegistro(DataFile * archivo,int nBloque)
{
    archivo=archivo;
    nBloque=nBloque;
    tamBloque=512;
    siguiente=-1;
    cantidad=0;
}

void BloqueRegistro::escribir()
{
    char * data= this->toChar();
    int pos= nBloque * tamBloque+20;
    archivo->escribir(data,pos,tamBloque);
}

void BloqueRegistro::cargar()
{
    int pos= nBloque * tamBloque+20;
    char * data=archivo->leer(pos,tamBloque);
    charToBloque(data);
}

void BloqueRegistro::charToBloque(char * data)
{
    int pos=0;
    memcpy(&nBloque,&data[pos],4);
    pos+=4;
    memcpy(&tamBloque,&data[pos],4);
    pos+=4;
    memcpy(&siguiente,&data[pos],4);
    pos+=4;
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
    return data;
}


