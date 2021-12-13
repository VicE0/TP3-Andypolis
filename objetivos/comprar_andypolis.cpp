#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis(int id_objetivo,int cantidad, bool cumplido) : Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = COMPRAR_ANDYPOLIS;
    this -> cantidad = 100000;
    this ->cumplido = false;
}


void Comprar_andypolis::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Comprar_andypolis::mostrar_descripcion()
{
    cout << "\nComprar Andypolis: juntar" << cantidad << " Andycoins a lo largo de la partida"<<endl;
    if (cumplido)
    {
        cout << "OBJETIVO CUMPLIDO!" << endl;
    }
    else{
        mostrar_progreso();
    }
}

void Comprar_andypolis::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
 {
     cout << endl;
 }