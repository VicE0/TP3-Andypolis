#include "bombardero.h"

Bombardero::Bombardero(int id_objetivo, int cantidad) : Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = BOMBARDERO;
    this -> cantidad = 5;
    this -> bombas_usadas = 0;
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

