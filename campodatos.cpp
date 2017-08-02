#include "campodatos.h"
#include "campo.h"
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



