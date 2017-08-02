#ifndef TABLA_H
#define TABLA_H


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
        char * toChar();
        void charToTabla(char * data);
        tabla * sig;
        void toString();

    protected:

    private:
};

#endif // TABLA_H
