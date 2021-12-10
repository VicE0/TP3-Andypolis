#ifndef ENERGETICO_H
#define ENERGETICO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Energetico : public Objetivo
{
    public:
        Energetico(int id_objetivo,int cantidad);

        void mostrar_descripcion();

        void mostrar_progreso();


};

#endif //ENERGETICO_H