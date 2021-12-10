#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis(int id_objetivo,int cantidad) :Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = COMPRAR_ANDYPOLIS;
    this -> cantidad = 100000;
}


void Comprar_andypolis::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Comprar_andypolis::mostrar_descripcion()
{
    cout << "\nComprar Andypolis: juntar" << cantidad << " Andycoins a lo largo de la partida"<<endl;
    mostrar_progreso();
}
