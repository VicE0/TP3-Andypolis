#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis(int id_objetivo,int cantidad, bool cumplido) : Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = COMPRAR_ANDYPOLIS;
    this -> cantidad = cantidad;
    this -> andycoins_totales = 0;
    this -> cumplido = false;
}


void Comprar_andypolis::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Comprar_andypolis::mostrar_descripcion()
{
    cout << "\nComprar Andypolis: juntar " << cantidad << " Andycoins a lo largo de la partida"<<endl;
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
    for (int i = 0; i < inventario ->obtener_cantidad(); i++)
    {

        this -> andycoins_totales = inventario ->obtener_nodo(i) ->obtener_dato() ->obtener_andycoins_totales();

    }

    if (andycoins_totales >= cantidad)
    {
        cumplido = true;
    }
}