#include "cansado.h"

Cansado::Cansado(int id_objetivo,int cantidad, bool cumplido) : Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = CANSADO;
    this -> cantidad = 0;
    this ->cumplido = false;
    this ->energia_jugador = 0;
}


void Cansado::mostrar_progreso()
{
    cout << "Progreso: " << energia_jugador << "/" << cantidad << endl;

}


void Cansado::mostrar_descripcion()
{
    cout << "\nCansado: haber terminado un turno con "<< cantidad << " puntos de energia"<<endl;

    if (cumplido)
    {
        cout << "OBJETIVO CUMPLIDO!" << endl;
    }
    else{
        mostrar_progreso();
    }
}

void Cansado::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
{
    this -> energia_jugador = energia;

    if (energia_jugador == cantidad)
    {
        cumplido = true;
    }
}