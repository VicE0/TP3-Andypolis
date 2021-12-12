#ifndef MINERO_H
#define MINERO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Minero: public Objetivo
{
    public:
        Minero(int id_objetivo,int cantidad,  bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> * inventario, int &energia);


};

#endif //MINERO_H