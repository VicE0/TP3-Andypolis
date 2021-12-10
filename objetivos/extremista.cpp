#include "extremista.h"

Extremista::Extremista(int id_objetivo, int cantidad)
{
    this -> id_objetivo = EXTREMISTA;
    this -> cantidad = 500;
}

bool Extremista::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Extremista::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Extremista::mostrar_descripcion()
{
    cout << "\nExtremista: haber comprado "<< cantidad << " bombas en una partida"<<endl;
    mostrar_progreso();
}

//SACAR COINS, puntero a inventario. Las bombas se resetean?