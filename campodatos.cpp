#include "campodatos.h"
#include "campo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
CampoDatos::CampoDatos(char * val,campo *dCampos)
{
    valor=val;
    defCampos=dCampos,
    sig=0;
}

CampoDatos::CampoDatos()
{
    valor=0;
    defCampos=0;
    sig=0;
}

int CampoDatos::getIntValue()
{
    return (int)(valor-48);
}
char * CampoDatos::getCharValue()
{
    return valor;
}

void CampoDatos::printValor()
{
    if(defCampos->tipo==0)
        cout<<getCharValue();
    else
        cout<<getIntValue();
}

void CampoDatos::toString()
{
    cout<<"Campo: "<<defCampos->nombre<<" Valor: ";
    printValor();
    cout<<endl;
}

char * CampoDatos::toChar()
{
    int pos=0;
    char * data= new char[20];
    memcpy(&data[pos],valor,4);
    pos+=4;
    return data;
}

void CampoDatos::initFromChar(char * data)
{
    int pos=0;
    memcpy(valor,&data[pos],4);
    pos+=4;
}



