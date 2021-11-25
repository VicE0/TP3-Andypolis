#include "energetico.h"

Energetico::Energetico(int id_objetivo, int cantidad)
{
    this -> id_objetivo = ENERGETICO;
    this -> cantidad = 100;
}

bool Energetico::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Energetico::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Energetico::mostrar_descripcion()
{
    cout << "Energetico: haber terminado un turno con "<< cantidad << " puntos de energia"<<endl;
    mostrar_progreso();
}

//SACAR COINS, TAL VEX AGREGAR CONTADOR A LA CLASE OBJETIVO?