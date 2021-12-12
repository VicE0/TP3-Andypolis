#include "minero.h"

Minero::Minero(int id_objetivo,int cantidad, bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = MINERO;
    this -> cantidad = 2;
    this -> cumplido = 0;
}


void Minero::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Minero::mostrar_descripcion()
{
    cout << "\nMinero: haber construido una mina de cada tipo"<<endl;
    mostrar_progreso();
}



void Minero::progreso(Lista <Material> * inventario, int &energia)
 {
     cout << endl;
 }

//agregar bool 