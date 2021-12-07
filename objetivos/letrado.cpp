#include "letrado.h"

Letrado::Letrado(int id_objetivo, int cantidad) : Objetivo(id_objetivo, cantidad, andycoins_totales)
{
    this -> id_objetivo = LETRADO;
    this -> cantidad = 100; //CANTIDAD_MAXIMA ESCUELAS
    this -> escuelas_construidas = 0;
}

bool Letrado::objetivo_cumplido()
{ 

    if (escuelas_construidas == cantidad)
    {
        return true;
    }
    return false;
}

void Letrado::mostrar_progreso()
{
    cout << "Progreso: " << escuelas_construidas << "/" << cantidad << endl;

}


void Letrado::mostrar_descripcion()
{
    cout << "\nLetrado: haber construido "<< cantidad << " escuelas"<<endl;
    mostrar_progreso();
}