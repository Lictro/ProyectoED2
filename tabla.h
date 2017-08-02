#ifndef TABLA_H
#define TABLA_H
#include "listcampos.h"
#include "datafile.h"
#include  "registro.h"
#include "listregistros.h"
class tabla
{
    public:
        tabla(char name[20],int i,int pBCampos,int actualBCampos,int pBDatos,int actualBDatos,int nB);
        char nombre[20];
        int id;
        int primerBloqueCampos;
        int actualBloqueCampos;
        int primerBloqueDatos;
        int actualBloqueDatos;
        int nBloque;
        ListCampos * campos;
        ListRegistros * registros;
        char * toChar();
        void charToTabla(char * data);
        tabla * sig;
        void toString();
        void cargarCampos(DataFile * archivo);
        void cargarRegistros(DataFile *archivo);
        Registro * interpretarRegistro(char * data,int longitud);
        int getLongitudRegistros();


    protected:

    private:
};

#endif // TABLA_H
