#include "extremista.h"

Extremista::Extremista(int id_objetivo,int cantidad, bool cumplido) :  Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = EXTREMISTA;
    this -> cantidad = 500;
    this -> bombas_compradas;
    this ->cumplido = false;
}


void Extremista::mostrar_progreso()
{
    cout << "Progreso: " << bombas_compradas << "/" << cantidad << endl;

}


void Extremista::mostrar_descripcion()
{
    cout << "\nExtremista: haber comprado "<< cantidad << " bombas en una partida"<<endl;
    mostrar_progreso();
}


void Extremista::progreso(Lista <Material> * inventario, int &energia)
 {
     cout << endl;
 }