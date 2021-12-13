#include "objetivo_obelisco.h"

Objetivo_obelisco::Objetivo_obelisco(int id_objetivo,int cantidad, bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = CONSTRUIR_OBELISCO;
    this -> cantidad = 1;
    // this -> obelisco_construido = false;
    this ->cumplido = false;
}

void Objetivo_obelisco::mostrar_progreso()
{
    cout << "Progreso: " << "0" << "/" << cantidad << endl;

}


void Objetivo_obelisco::mostrar_descripcion()
{
    cout << "PRINCIPAL:" << endl;
    cout << "\nMas alto que las nubes: construir el obelisco"<<endl;

    if (cumplido)
    {
        cout << "¡¡OBJETIVO PRINCIPAL CUMPLIDO!!" << endl;
    }
    mostrar_progreso();
    cout << "-------------------------------------" << endl;
}



void Objetivo_obelisco::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
{
    if (edificio_objetivo -> obtener_nombre() == OBELISCO)
    {
        cumplido = true;
    }

}
