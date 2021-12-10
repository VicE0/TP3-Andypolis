#include "extremista.h"

Extremista::Extremista(int id_objetivo,int cantidad) : Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = EXTREMISTA;
    this -> cantidad = 500;
    this -> bombas_compradas;
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

