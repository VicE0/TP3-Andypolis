#include "armado.h"

Armado::Armado(int id_objetivo, int posicion,int cantidad) : Objetivo(id_objetivo,posicion ,cantidad, andycoins_totales)
{
    this -> id_objetivo = ARMADO;
    this -> cantidad = 10;
    this -> bombas_inventario = 0;
}

bool Armado::objetivo_cumplido()
{ 

    if (bombas_inventario == cantidad)
    {
        return true;
    }
    return false;
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

int Armado::obtener_id()
{
    return id_objetivo;
}
