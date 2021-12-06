#include "armado.h"

Armado::Armado(int id_objetivo, int cantidad) : Objetivo(id_objetivo, cantidad, andycoins_totales)
{
    this -> id_objetivo = ARMADO;
    this -> cantidad = 10;
}

bool Armado::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Armado::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Armado::mostrar_descripcion()
{
    cout << "\nArmado: tener "<< cantidad << " bombas en el inventario"<<endl;
    mostrar_progreso();
}

//SACAR COINS, puntero a la lista de inventario