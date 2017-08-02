#include "campo.h"

campo::campo(char name[20],char tipo[10],int columna,char nombTabla[20])
{
    for(int c=0;c<20;c++)
    {
        nombre[c]=name[c];
    }

    for(int c=0;c<20;c++)
    {
        tipo[c]=tipo[c];
    }

    for(int c=0;c<20;c++)
    {
        nombreTabla[c]=nombTabla[c];
    }
    columna=columna;
}


