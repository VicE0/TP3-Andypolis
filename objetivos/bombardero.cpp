#include "bombardero.h"

Bombardero::Bombardero(int id_objetivo, int cantidad) : Objetivo(id_objetivo, cantidad, andycoins_totales)
{
    this -> id_objetivo = BOMBARDERO;
    this -> cantidad = 5;
}

bool Bombardero::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Bombardero::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Bombardero::mostrar_descripcion()
{
    cout << "\nBombardero: haber usado "<< cantidad << " bombas"<<endl;
    mostrar_progreso();
}

//SACAR COINS, TAL VEX AGREGAR CONTADOR A LA CLASE OBJETIVO?