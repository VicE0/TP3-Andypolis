#include "energetico.h"

Energetico::Energetico(int id_objetivo, int posicion, int cantidad) : Objetivo(id_objetivo, posicion,cantidad, andycoins_totales)
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
    cout << "\nEnergetico: haber terminado un turno con "<< cantidad << " puntos de energia"<<endl;
    mostrar_progreso();
}
int Energetico::obtener_id()
{
    return id_objetivo;
}
//ENERGIA