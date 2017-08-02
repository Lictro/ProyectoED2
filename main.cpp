#include <iostream>
#include "datafile.h"
#include "bloque.h"
#include "manejadrotablas.h"
#include "manejadordebloques.h"
#include "bloquecampo.h"
#include "bloquetabla.h"
#include <stdio.h>
#include "masterblock.h"
#include "tabla.h"
using namespace std;

int main()
{
    //Creo la base de Datos
    DataFile * archivo = new DataFile("C:\\Users\\David\\Desktop\\BaseDatos.data");
    archivo->abrir();
    ManejadordeBloques * mbloques= new ManejadordeBloques(archivo);
    ManejadroTablas * mtablas=new ManejadroTablas(archivo,mbloques->masterBlock);

    /*for(int c=0;c<1000;c++)
    {
        char * nombre= new char[20];
        nombre[0]='t';
        nombre[1]='a';
        nombre[2]='b';
        nombre[3]='l';
        nombre[4]='a';
        nombre[5]='_';
        char cadena[1000];
        sprintf(cadena, "%d", c);
        for(int x=0;cadena[x]!='\0';x++)
        {
            nombre[x+6]=cadena[x];
        }

        mtablas->crearTabla(nombre,c,mbloques);
    }//*/
    mtablas->listarTablas();
    archivo->cerrar();

    /*
    tmp->primerBloqueCampos=bc->nBloque;
    tmp->actualBloqueCampos=bc->nBloque;*/
    /*
    int op=1;
    while(op!=0)
    {
        cout<<"Ingrese una opcion"<<endl;
        cout<<"1. Crear Base de Datos"<<endl;
        cout<<"2. Crear Tabla"<<endl;
        cout<<"3. Crear Campo"<<endl;

        cin>> op;
        cout<<endl;
        if(op==1)
        {
             cout<<"Ingrese el path"<<endl;
             char * path;
             cin>> path;
             DataFile * archivo = new DataFile(path);
        }
        else if(op==2)
        {
             cout<<"Ingrese el path"<<endl;
             char * path;
             cin>> path;
             DataFile * archivo = new DataFile(path);
             cout<<"Ingrese el nombre de la tabla"<<endl;
             char name[20];
             cin>> name;
             cout<<"Ingrese el ID de la tabla"<<endl;
             int id;
             cin>> id;
             ManejadroTablas * mtablas= new ManejadroTablas(archivo);
             mtablas->crearTabla(name,id,0,0,0,0);
        }
        else if(op==3)
        {
             cout<<"Ingrese el path"<<endl;
             char * path;
             cin>> path;
             DataFile * archivo = new DataFile(path);
             cout<<"Ingrese el nombre de la tabla a la que le asignara el campo"<<endl;
             char name[20];
             cin>> name;
             ManejadroTablas * mtablas= new ManejadroTablas(archivo);
             tabla * t =mtablas->buscarTabla(name);
        }




    }*/
    return 0;
}
