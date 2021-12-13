#ifndef CANSADO_H
#define CANSADO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Cansado : public Objetivo
{
    public:
        Cansado(int id_objetivo, int cantidad,  bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo);


};

#endif //CANSADO_H