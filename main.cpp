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
#include "registro.h"
#include "campodatos.h"
using namespace std;

int main()
{
    //Creo la base de Datos
    DataFile * archivo = new DataFile("C:\\Users\\David\\Desktop\\BaseDatos.data");
    archivo->abrir();
    ManejadordeBloques * mbloques= new ManejadordeBloques(archivo);
    ManejadroTablas * mtablas=new ManejadroTablas(archivo,mbloques->masterBlock);
    char * buscar= new char[20];
    buscar[0]='t';
    buscar[1]='a';
    buscar[2]='b';
    buscar[3]='l';
    buscar[4]='a';
    char * nombre= new char[20];
    nombre[0]='t';
    nombre[1]='a';
    nombre[2]='b';
    nombre[3]='l';
    nombre[4]='a';
    cout<<nombre<<endl;
    mtablas->crearTabla(nombre,1020,mbloques);
    //mtablas->buscarTabla(nombre);
    //mtablas->listarTablas();

    char * nombreC= new char[20];
    nombreC[0]='N';
    nombreC[1]='o';
    nombreC[2]='m';
    nombreC[3]='b';
    nombreC[4]='r';
    nombreC[5]='e';
    mtablas->crearCampo(1020,nombreC,0,mbloques);
    char * nombreC1= new char[20];
    nombreC1[0]='E';
    nombreC1[1]='d';
    nombreC1[2]='a';
    nombreC1[3]='d';
    mtablas->crearCampo(1020,nombreC1,1,mbloques);
    char * datos= new char[20];
    datos[0]='D';
    datos[1]='a';
    datos[2]='v';
    datos[3]='i';
    datos[3]='d';
    CampoDatos * datosN=new CampoDatos(datos,mtablas->buscarTabla(1020)->campos->get(0));
    char * edad= new char[20];
    datos[0]='1';
    datos[1]='9';
    CampoDatos * datosE=new CampoDatos(edad,mtablas->buscarTabla(1020)->campos->get(1));
    Registro * r= new Registro(mtablas->buscarTabla(1020)->getLongitudRegistros());
    mtablas->addRegistro(1020,mbloques,r);
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
