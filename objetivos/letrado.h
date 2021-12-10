#ifndef LETRADO_H
#define LETRADO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Letrado : public Objetivo
{
    public:
        Letrado(int id_objetivo,int cantidad);

        void mostrar_descripcion();

        void mostrar_progreso();


};

#endif //LETRADO_H