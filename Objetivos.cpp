#include <string>
#include <iostream>

#include "Objetivos.h"

using namespace std;

Objetivo::Objetivo()
{
    this -> id_objetivo = 0;
    this -> cantidad = 0;
    // this -> obelisco_construido = false;
    this -> andycoins_totales = 0;
    this -> posicion = 0;
}

Objetivo::Objetivo(int id_objetivo,int posicion, int cantidad, int andycoins_totales)
{
    this -> id_objetivo = id_objetivo;
    this -> cantidad = cantidad;
    this -> posicion = posicion;
    // this -> obelisco_construido = false;
    this -> andycoins_totales = 0;
}


int Objetivo::obtener_objetivo()
{
    return id_objetivo;
}
