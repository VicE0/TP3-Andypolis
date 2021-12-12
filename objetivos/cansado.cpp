#include "cansado.h"

Cansado::Cansado(int id_objetivo,int cantidad, bool cumplido) : Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = CANSADO;
    this -> cantidad = 0;
    this ->cumplido = false;
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

 void Cansado::progreso(Lista <Material> * inventario, int &energia)
 {
     cout << endl;
 }