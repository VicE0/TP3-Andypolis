#include <string>
#include <iostream>

#include "Objetivos.h"

using namespace std;

Objetivo::Objetivo()
{
    this -> id_objetivo = 0;
    this -> cantidad = 0;
    this -> cumplido = false;
}

Objetivo::Objetivo(int id_objetivo, int cantidad, bool cumplido)
{
    this -> id_objetivo = id_objetivo;
    this -> cantidad = cantidad;
    this -> cumplido = cumplido;
}


int Objetivo::obtener_objetivo()
{
    return id_objetivo;
}

bool Objetivo::objetivo_cumplido()
{
    return cumplido;
}