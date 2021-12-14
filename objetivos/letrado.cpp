#include "letrado.h"

Letrado::Letrado(int id_objetivo,int cantidad,  bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = LETRADO;
    this -> cantidad = cantidad;
    this -> escuelas_construidas = 0;
    this -> cumplido = false;
}

void Letrado::mostrar_progreso()
{
    cout << "Progreso: " << escuelas_construidas << "/" << cantidad << endl;

}


void Letrado::mostrar_descripcion()
{
    cout << "\nLetrado: haber construido "<< cantidad << " escuelas"<<endl;
    if(cumplido)
    {
        cout << "¡OBJETIVO CUMPLIDO!" << endl;
    }
    else{
        mostrar_progreso();
    }
    
}



void Letrado::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
{
    this -> cantidad = edificio_objetivo ->obtener_maximo_construir();

    if (edificio_objetivo -> obtener_nombre() == ESCUELA)
    {
        escuelas_construidas++;
    }

    if (escuelas_construidas == cantidad)
    {
        cumplido = true;
    }

}
