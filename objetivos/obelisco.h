#ifndef OBELISCO
#define OBELISCO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Objetivo_obelisco: public Objetivo
{
    public:
        Objetivo_obelisco(int id_objetivo,int cantidad, bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> *inventario, int &energia);

};

#endif //OBELISCO_H