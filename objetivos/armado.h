#ifndef ARMADO_H
#define ARMADO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Armado : public Objetivo
{
    public:
        Armado(int id_objetivo,int posicion,int cantidad);

        bool objetivo_cumplido();

        int obtener_id();

        void mostrar_descripcion();

        void mostrar_progreso();

};

#endif //ARMADO_H