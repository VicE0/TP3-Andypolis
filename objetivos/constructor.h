#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Constructor : public Objetivo
{
    public:
        Constructor(int id_objetivo, int cantidad,  bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material>  *inventario, int &energia);



};

#endif //CONSTRUCTOR_H