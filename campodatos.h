#ifndef CAMPODATOS_H
#define CAMPODATOS_H
#include "campo.h"

class CampoDatos
{
    public:
        CampoDatos(char * val,campo * dCampos);
        CampoDatos();
        char * valor;
        campo * defCampos;
        CampoDatos * sig;
        int getIntValue();
        char * getCharValue();

    private:
};

#endif // CAMPODATOS_H
