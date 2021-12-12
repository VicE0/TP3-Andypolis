#ifndef EXTREMISTA_H
#define EXTREMISTA_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Extremista : public Objetivo
{
    public:
        Extremista(int id_objetivo,int cantidad, bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> * inventario, int &energia);


};

#endif //EXTREMISTA_H