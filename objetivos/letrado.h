#ifndef LETRADO_H
#define LETRADO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Letrado : public Objetivo
{
    public:
        Letrado(int id_objetivo, int posicion,int cantidad);

        bool objetivo_cumplido();

        void mostrar_descripcion();

        void mostrar_progreso();

        int obtener_id();

};

#endif //LETRADO_H