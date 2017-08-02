#ifndef BLOQUEREGISTRO_H
#define BLOQUEREGISTRO_H
#include "datafile.h"

class BloqueRegistro
{
    public:
        BloqueRegistro(DataFile * archivo,int nBloque);
        int nBloque;
        DataFile * archivo;
        int cantidad;
        int tamBloque;
        int siguiente;
        void escribir();
        void cargar();
        char * toChar();
        void charToBloque(char * data);
};

#endif // BLOQUEREGISTRO_H
