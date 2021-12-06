#include "edad_piedra.h"

Edad_piedra::Edad_piedra(int id_objetivo, int cantidad) : Objetivo(id_objetivo, cantidad, andycoins_totales)
{
    this -> id_objetivo = EDAD_PIEDRA;
    this -> cantidad = 50000;
}

bool Edad_piedra::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Edad_piedra::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}

void Edad_piedra::mostrar_descripcion()
{
    cout << "\nEdad de piedra: tener en el inventario " << cantidad << " piedras" <<endl;
    mostrar_progreso();
}

//LINKEAR CON INVENTARIO, SACAR LAS COINS