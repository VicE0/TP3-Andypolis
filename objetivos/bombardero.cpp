#include "bombardero.h"

Bombardero::Bombardero(int id_objetivo, int posicion,int cantidad) : Objetivo(id_objetivo, posicion ,cantidad, andycoins_totales)
{
    this -> id_objetivo = BOMBARDERO;
    this -> cantidad = 5;
    this -> bombas_usadas = 0;
}

bool Bombardero::objetivo_cumplido()
{ 

    if (bombas_usadas == cantidad)
    {
        return true;
    }
    return false;
}

void Bombardero::mostrar_progreso()
{
    cout << "Progreso: " << bombas_usadas << "/" << cantidad << endl;

}


void Bombardero::mostrar_descripcion()
{
    cout << "\nBombardero: haber usado "<< cantidad << " bombas"<<endl;
    mostrar_progreso();
}

int Bombardero::obtener_id()
{
    return id_objetivo;
}
