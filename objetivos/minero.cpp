#include "minero.h"

Minero::Minero(int id_objetivo,int cantidad) : Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = MINERO;
    this -> cantidad = 2;
}


void Minero::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Minero::mostrar_descripcion()
{
    cout << "\nMinero: haber construido una mina de cada tipo"<<endl;
    mostrar_progreso();
}


//agregar bool 