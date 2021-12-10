#include "cansado.h"

Cansado::Cansado(int id_objetivo,int cantidad) : Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = CANSADO;
    this -> cantidad = 0;
    //energiaa del jugador
}


void Cansado::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Cansado::mostrar_descripcion()
{
    cout << "\nCansado: haber terminado un turno con "<< cantidad << " puntos de energia"<<endl;
    mostrar_progreso();
}

