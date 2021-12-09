#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Comprar_andypolis : public Objetivo
{
    public:
        Comprar_andypolis(int id_objetivo, int posicion,int cantidad);

        bool objetivo_cumplido();

        void mostrar_descripcion();

        void mostrar_progreso();

        int obtener_id();

};

#endif //COMPRAR_ANDYPOLIS