#ifndef MINERO_H
#define MINERO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Minero: public Objetivo
{
    public:
        Minero(int id_objetivo,int cantidad);

        void mostrar_descripcion();

        void mostrar_progreso();


};

#endif //MINERO_H