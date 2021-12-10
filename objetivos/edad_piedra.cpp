#include "edad_piedra.h"

Edad_piedra::Edad_piedra(int id_objetivo,int cantidad) : Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = EDAD_PIEDRA;
    this -> cantidad = 50000;
    this -> piedras_inventario = 0;
}


void Edad_piedra::mostrar_progreso()
{
    cout << "Progreso: " << piedras_inventario << "/" << cantidad << endl;

}

void Edad_piedra::mostrar_descripcion()
{
    cout << "\nEdad de piedra: tener en el inventario " << cantidad << " piedras" <<endl;
    mostrar_progreso();
}


