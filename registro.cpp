#include "registro.h"
#include "listcampodatos.h"
#include <stdio.h>
#include <string.h>
#include "campodatos.h"
Registro::Registro(int longitud)
{
    campoDatos= new ListCampoDatos();
    sig=0;
    longitudRegistro=longitud;
}

char * Registro::toChar()
{
    int pos=0;
    char * data= new char[longitudRegistro];
    for(int c=0;c<campoDatos->cantidad;c++)
    {
        char * data_entry=campoDatos->get(c)->toChar();
        memcpy(&data[pos],data_entry,20);
        pos+=20;
    }
    return data;
}

void Registro::initFromChar(char * data)
{
    int pos=0;
    for(int c=0;c<longitudRegistro;c+=20)
    {
        CampoDatos * cam= new CampoDatos();
        cam->initFromChar(&data[pos]);
        campoDatos->add(cam);
        pos+=20;
    }
}


