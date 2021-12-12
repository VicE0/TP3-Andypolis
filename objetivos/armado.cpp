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
    // mostrar_progreso();
}

void Armado::progreso(Lista <Material> * inventario, int &energia)
{
    for (int i = 0; i < inventario ->obtener_cantidad(); i++)
    {
        if (inventario -> obtener_nodo(i) ->obtener_dato() ->obtener_nombre() == "bombas")
        {
            this -> bombas_inventario += inventario ->obtener_nodo(i) ->obtener_dato() ->obtener_cantidad_disponible();
        }
    }
    cout << "Progreso: " << bombas_inventario << "/" << cantidad << endl;
} //TERMINAL NO COMṔILA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!
