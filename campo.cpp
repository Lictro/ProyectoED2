#include "campo.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

campo::campo(char name[20],int t)
{
    strncpy(nombre,name,20);
    tipo=t;
    if(t==0)
        longitud=20;
    else
        longitud=4;
    sig=0;

}


