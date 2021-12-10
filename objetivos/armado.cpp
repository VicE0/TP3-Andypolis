#include "armado.h"

Armado::Armado(int id_objetivo,int cantidad) : Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = ARMADO;
    this -> cantidad = 10;
    this -> bombas_inventario = 0;
}


void Armado::mostrar_progreso()
{
    cout << "Progreso: " << bombas_inventario << "/" << cantidad << endl;

}


void Armado::mostrar_descripcion()
{
    cout << "\nArmado: tener "<< cantidad << " bombas en el inventario"<<endl;
    mostrar_progreso();
}


