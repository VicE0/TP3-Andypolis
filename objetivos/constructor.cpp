#include "constructor.h"

Constructor::Constructor(int id_objetivo,int cantidad, bool cumplido) : Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = CONSTRUCTOR;
    this -> cantidad = cantidad; //cantidad de edificios diferentes (sin contar obelisco)
    this -> cumplido = false;
    this -> mina_construida = false;
    this -> mina_oro_construida = false;
    this -> aserradero_construido = false;
    this -> escuela_construida = false;
    this -> fabrica_construida = false;
    this -> planta_electrica_construida = false;
    this -> edificios_construidos = 0;
}

void Constructor::mostrar_progreso()
{
    cout << "Progreso: " << edificios_construidos << "/" << cantidad << endl;

}

void Constructor::mostrar_descripcion()
{
    cout << "\nConstructor: haber construido un edificio de cada tipo "<<endl;

    if (cumplido)
    {
        cout << "OBJETIVO CUMPLIDO!" << endl;
    }
    else{
        mostrar_progreso();
    }
    
}

void Constructor::progreso(Lista <Material> *inventario, int &energia, Edificio * edificio_objetivo)
{
    if (edificio_objetivo -> obtener_nombre() == MINA)
    {
        mina_construida = true;
        edificios_construidos++;
    }

    if (edificio_objetivo -> obtener_nombre() == MINA_ORO)
    {
        mina_oro_construida = true;
        edificios_construidos++;
    }

    if (edificio_objetivo -> obtener_nombre() == ASERRADERO)
    {
        aserradero_construido = true;
        edificios_construidos++;
    }

    if (edificio_objetivo -> obtener_nombre() == ESCUELA)
    {
        escuela_construida = true;
        edificios_construidos++;
    }

    if (edificio_objetivo -> obtener_nombre() == FABRICA)
    {
        fabrica_construida = true;
        edificios_construidos++;
    }

    if (edificio_objetivo -> obtener_nombre() == PLANTA_ELECTRICA)
    {
        planta_electrica_construida = true;
        edificios_construidos++;
    }



    if (planta_electrica_construida && escuela_construida && fabrica_construida && aserradero_construido
        && mina_oro_construida && mina_construida )
    {
        cumplido = true;
    }

}