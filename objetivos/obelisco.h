#ifndef OBELISCO
#define OBELISCO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Obelisco: public Objetivo
{
    public:
        Obelisco(int id_objetivo, int cantidad);

        bool objetivo_cumplido();

        void mostrar_descripcion();

        void mostrar_progreso();

};

#endif //OBELISCO_H