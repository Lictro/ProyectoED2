#ifndef MANEJADROTABLAS_H
#define MANEJADROTABLAS_H
#include "listbloquetablas.h"
#include "tabla.h"
#include "datafile.h"
#include "manejadordebloques.h"
#include "masterblock.h"
class ManejadroTablas
{
    public:
        ManejadroTablas(DataFile *a,MasterBlock *masterBlock);
        void listarTablas();
        tabla * buscarTabla(char * name);
        ListBloqueTablas * listaBT;
        void cargarBT();
        void crearTabla(char name[20],int id,ManejadordeBloques * manejador);
        DataFile * archivo;
};

#endif // MANEJADROTABLAS_H
