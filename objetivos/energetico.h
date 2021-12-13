#ifndef ENERGETICO_H
#define ENERGETICO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Energetico : public Objetivo
{
    public:
        Energetico(int id_objetivo,int cantidad, bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo);


};

#endif //ENERGETICO_H