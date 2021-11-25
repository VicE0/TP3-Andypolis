#include "minero.h"

Minero::Minero(int id_objetivo, int cantidad)
{
    this -> id_objetivo = MINERO;
    this -> cantidad = 2;
}

bool Minero::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Minero::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Minero::mostrar_descripcion()
{
    cout << "Minero: haber construido una mina de cada tipo"<<endl;
    mostrar_progreso();
}

//LINKEAR CON MAPA / EDIFICIOS