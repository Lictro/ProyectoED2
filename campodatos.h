#ifndef CAMPODATOS_H
#define CAMPODATOS_H
#include "campo.h"

class CampoDatos
{
    public:
        CampoDatos(char val[],campo * dCampos);
        CampoDatos();
        char valor[20];
        campo * defCampos;
        CampoDatos * sig;
        int getIntValue();
        char * getCharValue();
        void printValor();
        void toString();
        char * toChar();
        void initFromChar(char * data);

    private:
};

#endif // CAMPODATOS_H
