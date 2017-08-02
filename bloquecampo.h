#ifndef BLOQUECAMPO_H
#define BLOQUECAMPO_H
#include "datafile.h"

class BloqueCampo
{
    public:
        BloqueCampo(DataFile * a,int numBloque,int tamanoBloque,int s);
        int nBloque;
        int tamBloque;
        void escribir();
        void cargar();
        char * toChar();
        void charToBloque(char * data);
        DataFile * archivo;
        int siguiente;

};

#endif // BLOQUECAMPO_H
