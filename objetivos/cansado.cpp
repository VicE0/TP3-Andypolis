#include "cansado.h"

Cansado::Cansado(int id_objetivo, int cantidad)
{
    this -> id_objetivo = CANSADO;
    this -> cantidad = 0;
}

bool Cansado::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Cansado::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Cansado::mostrar_descripcion()
{
    cout << "Cansado: haber terminado un turno con "<< cantidad << " puntos de energia"<<endl;
    mostrar_progreso();
}

//SACAR COINS, TAL VEX AGREGAR CONTADOR A LA CLASE OBJETIVO?