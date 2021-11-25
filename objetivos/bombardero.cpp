#include "bombardero.h"

Bombardero::Bombardero(int id_objetivo, int cantidad)
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
    cout << "Bombardero: haber usado "<< cantidad << " bombas"<<endl;
    mostrar_progreso();
}

//SACAR COINS, TAL VEX AGREGAR CONTADOR A LA CLASE OBJETIVO?