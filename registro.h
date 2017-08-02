#ifndef REGISTRO_H
#define REGISTRO_H
#include "listcampodatos.h"

class Registro
{
    public:
        Registro();
        ListCampoDatos * campoDatos;
        Registro * sig;

    private:
};

#endif // REGISTRO_H
