#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "Objetivos.h"

#include <iostream>

using namespace std;

class Constructor : public Objetivo
{
    public:
        Constructor(int id_objetivo, int cantidad);

        bool objetivo_cumplido();

        void mostrar_descripcion();

        void mostrar_progreso();

};

#endif //CONSTRUCTOR_H