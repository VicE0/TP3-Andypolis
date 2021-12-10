#ifndef CANSADO_H
#define CANSADO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Cansado : public Objetivo
{
    public:
        Cansado(int id_objetivo, int cantidad);

        void mostrar_descripcion();

        void mostrar_progreso();


};

#endif //CANSADO_H