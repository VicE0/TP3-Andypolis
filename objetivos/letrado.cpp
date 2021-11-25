#include "letrado.h"

Letrado::Letrado(int id_objetivo, int cantidad)
{
    this -> id_objetivo = LETRADO;
    this -> cantidad = 100; //CANTIDAD_MAXIMA ESCUELAS
}

bool Letrado::objetivo_cumplido()
{ 

    if (andycoins_totales == cantidad)
    {
        return true;
    }
    return false;
}

void Letrado::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}


void Letrado::mostrar_descripcion()
{
    cout << "Letrado: haber construido "<< cantidad << " escuelas"<<endl;
    mostrar_progreso();
}

//SACAR COINS, linkear con max edificios escuela