#include "minero.h"

Minero::Minero(int id_objetivo,int cantidad, bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = MINERO;
    this -> cantidad = 2;
    this -> minas_construidas = 0;
    this -> cumplido = false;
    this -> mina_construida = false;
    this -> mina_oro_construida = false;
}


void Minero::mostrar_progreso()
{
    cout << "Progreso: " << minas_construidas << "/" << cantidad << endl;

}


void Minero::mostrar_descripcion()
{
    cout << "\nMinero: haber construido una mina de cada tipo"<<endl;
    
    if(cumplido)
    {
        cout << "OBJETIVO CUMPLIDO!" << endl;
    }

    else
    {
        mostrar_progreso();
    }
}



void Minero::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
{
    if (edificio_objetivo -> obtener_nombre() == MINA)
    {
        mina_construida = true;
        minas_construidas++;
    }

    if (edificio_objetivo -> obtener_nombre() == MINA_ORO)
    {
        mina_oro_construida = true;
        minas_construidas++;
    }

    if (mina_oro_construida && mina_construida)
    {
        cumplido = true;
    }
}

