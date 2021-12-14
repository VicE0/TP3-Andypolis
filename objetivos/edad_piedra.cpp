#include "edad_piedra.h"

Edad_piedra::Edad_piedra(int id_objetivo,int cantidad, bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = EDAD_PIEDRA;
    this -> cantidad = cantidad;
    this -> piedras_inventario = 0;
    this -> cumplido = false;
}


void Edad_piedra::mostrar_progreso()
{
    cout << "Progreso: " << piedras_inventario << "/" << cantidad << endl;

}

void Edad_piedra::mostrar_descripcion()
{
    cout << "\nEdad de piedra: tener en el inventario " << cantidad << " piedras" <<endl;
    
    if (cumplido)
    {
        cout << "OBJETIVO_CUMPLIDO!" << endl;
    }
    else{
        mostrar_progreso();
    }
}


void Edad_piedra::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
{
    for (int i = 0; i < inventario ->obtener_cantidad(); i++)
    {
        if (inventario -> obtener_nodo(i) ->obtener_dato() ->obtener_nombre() == PIEDRA)
        {
            this -> piedras_inventario = inventario ->obtener_nodo(i) ->obtener_dato() ->obtener_cantidad_disponible();
        }
    } 

    if (piedras_inventario >= cantidad)
    {
        cumplido = true;
    }
} 

