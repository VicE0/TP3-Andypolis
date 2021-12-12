#include "letrado.h"

Letrado::Letrado(int id_objetivo,int cantidad,  bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = LETRADO;
    this -> cantidad = 100; //CANTIDAD_MAXIMA ESCUELAS
    this -> escuelas_construidas = 0;
    this -> cumplido = false;
}

void Letrado::mostrar_progreso()
{
    cout << "Progreso: " << escuelas_construidas << "/" << cantidad << endl;

}


void Letrado::mostrar_descripcion()
{
    cout << "\nLetrado: haber construido "<< cantidad << " escuelas"<<endl;
    mostrar_progreso();
}



void Letrado::progreso(Lista <Material> * inventario, int &energia)
 {
     cout << endl;
 }