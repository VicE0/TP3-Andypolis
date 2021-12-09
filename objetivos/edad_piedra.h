#ifndef EDAD_PIEDRA_H
#define EDAD_PIEDRA_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Edad_piedra : public Objetivo
{
    public:
        Edad_piedra(int id_objetivo, int posicion,int cantidad);

        bool objetivo_cumplido();

        void mostrar_descripcion();

        void mostrar_progreso();

        int obtener_id();

};

#endif //EDAD_PIEDRA_H