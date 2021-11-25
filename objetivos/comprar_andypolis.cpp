#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis(int id_objetivo, int cantidad)
{
    this -> id_objetivo = COMPRAR_ANDYPOLIS;
    this -> cantidad = 100000;
}

bool Comprar_andypolis::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Comprar_andypolis::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Comprar_andypolis::mostrar_descripcion()
{
    cout << "Comprar Andypolis: juntar 100.000 Andycoins a lo largo de la partida"<<endl;
    mostrar_progreso();
}