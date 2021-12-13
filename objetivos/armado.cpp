#include "armado.h"

Armado::Armado(int id_objetivo,int cantidad,  bool cumplido) : Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = ARMADO;
    this -> cantidad = 10;
    this -> bombas_inventario = 0;
    this ->cumplido = false;
}


void Armado::mostrar_progreso()
{
    cout << "Progreso: " << bombas_inventario << "/" << cantidad << endl;

}

void Armado::mostrar_descripcion()
{
    cout << "\nArmado: tener "<< cantidad << " bombas en el inventario"<<endl;

    if (cumplido)
    {
        cout << "OBJETIVO CUMPLIDO!" << endl;
    }
    else{
        mostrar_progreso();
    }
    
}

void Armado::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
{
    for (int i = 0; i < inventario ->obtener_cantidad(); i++)
    {
        if (inventario -> obtener_nodo(i) ->obtener_dato() ->obtener_nombre() == BOMBA)
        {
            this -> bombas_inventario += inventario ->obtener_nodo(i) ->obtener_dato() ->obtener_cantidad_disponible();
        }
    }

    if (bombas_inventario == cantidad)
    {
        cumplido = true;
    }
} 
