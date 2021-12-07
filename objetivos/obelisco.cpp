#include "obelisco.h"

Obelisco::Obelisco(int id_objetivo, int cantidad) : Objetivo(id_objetivo, cantidad, andycoins_totales)
{
    this -> id_objetivo = OBJETIVO_OBELISCO;
    this -> cantidad = 1;
}

bool Obelisco::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Obelisco::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Obelisco::mostrar_descripcion()
{
    cout << "PRINCIPAL:" << endl;
    cout << "\nMas alto que las nubes: construir el obelisco"<<endl;
    mostrar_progreso();
}
//link edificvios