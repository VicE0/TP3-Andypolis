#include "energetico.h"

Energetico::Energetico(int id_objetivo, int cantidad) : Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = ENERGETICO;
    this -> cantidad = 100;
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
