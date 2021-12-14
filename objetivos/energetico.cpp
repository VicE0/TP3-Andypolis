#include "energetico.h"

Energetico::Energetico(int id_objetivo, int cantidad, bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = ENERGETICO;
    this -> cantidad = cantidad;
    this ->cumplido = false;
    this -> energia_jugador = 0;
}

void Energetico::mostrar_progreso()
{
    cout << "Progreso: " << energia_jugador << "/" << cantidad << endl;

}


void Energetico::mostrar_descripcion()
{
    cout << "\nEnergetico: haber terminado un turno con "<< cantidad << " puntos de energia"<<endl;

    if (cumplido)
    {
        cout << "OBJETIVO CUMPLIDO!" << endl;
    }
    else{
        mostrar_progreso();
    }
}


void Energetico::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
{
    this ->energia_jugador = energia;

    if (energia_jugador == cantidad)
    {
        cumplido = true;
    }
}