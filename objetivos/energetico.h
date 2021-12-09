#ifndef ENERGETICO_H
#define ENERGETICO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Energetico : public Objetivo
{
    public:
        Energetico(int id_objetivo, int posicion,int cantidad);

        bool objetivo_cumplido();

        void mostrar_descripcion();

        void mostrar_progreso();

        int obtener_id();

};

#endif //ENERGETICO_H