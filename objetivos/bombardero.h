#ifndef BOMBARDERO_H
#define BOMBARDERO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Bombardero : public Objetivo
{
    public:
        Bombardero(int id_objetivo, int cantidad);

        bool objetivo_cumplido();

        void mostrar_descripcion();

        void mostrar_progreso();

};

#endif //BOMBARDERO_H