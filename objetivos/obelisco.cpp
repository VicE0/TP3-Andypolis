#include "obelisco.h"

Objetivo_obelisco::Objetivo_obelisco(int id_objetivo,int cantidad, bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = CONSTRUIR_OBELISCO;
    this -> cantidad = 1;
    this ->cumplido = false;
}

void Objetivo_obelisco::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Objetivo_obelisco::mostrar_descripcion()
{
    cout << "PRINCIPAL:" << endl;
    cout << "\nMas alto que las nubes: construir el obelisco"<<endl;
    mostrar_progreso();
}



void Objetivo_obelisco::progreso(Lista <Material> * inventario, int &energia)
 {
     cout << endl;
 }
//link edificvios