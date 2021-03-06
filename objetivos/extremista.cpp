#include "extremista.h"

Extremista::Extremista(int id_objetivo,int cantidad, bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = EXTREMISTA;
    this -> cantidad = cantidad;
    this -> bombas_compradas = 0;
    this ->cumplido = false;
}


void Extremista::mostrar_progreso()
{
    cout << "Progreso: " << bombas_compradas << "/" << cantidad << endl;
    
}


void Extremista::mostrar_descripcion()
{
    cout << "\nExtremista: haber comprado "<< cantidad << " bombas en una partida"<<endl;
    if (cumplido)
    {
        cout << "OBJETIVO CUMPLIDO!" << endl;
    }
    else{
        mostrar_progreso();
    }
}


void Extremista::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
{
    for (int i = 0; i < inventario ->obtener_cantidad(); i++)
    {

        this -> bombas_compradas = inventario ->obtener_nodo(i) ->obtener_dato() ->obtener_bombas_compradas();

    }

    if (bombas_compradas >= cantidad)
    {
        cumplido = true;
    }
}