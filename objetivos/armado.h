#ifndef ARMADO_H
#define ARMADO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Armado : public Objetivo
{
    public:
        Armado(int id_objetivo,int cantidad , bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> * inventario, int &energia);

};

#endif //ARMADO_H