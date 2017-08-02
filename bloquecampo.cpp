#include "bloquecampo.h"
#include "datafile.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

BloqueCampo::BloqueCampo(DataFile * file,int numBloque,int tamanoBloque,int s)
{
    nBloque=numBloque;
    tamBloque=tamanoBloque;
    siguiente=s;
    archivo=file;
}

void BloqueCampo::escribir()
{
    char * data= this->toChar();
    int pos= nBloque * tamBloque+20;
    archivo->escribir(data,pos,tamBloque);
}

void BloqueCampo::cargar()
{
    int pos= nBloque * tamBloque+20;
    char * data=archivo->leer(pos,tamBloque);
    charToBloque(data);
}

void BloqueCampo::charToBloque(char * data)
{
    int pos=0;
    memcpy(&nBloque,&data[pos],4);
    pos+=4;
    memcpy(&tamBloque,&data[pos],4);
    pos+=4;
    memcpy(&siguiente,&data[pos],4);
    pos+=4;
}

char * BloqueCampo::toChar()
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




