#ifndef EXTREMISTA_H
#define EXTREMISTA_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Extremista : public Objetivo
{
    public:
        Extremista(int id_objetivo, int posicion ,int cantidad);

        bool objetivo_cumplido();

        void mostrar_descripcion();

        void mostrar_progreso();

        int obtener_id();

};

#endif //EXTREMISTA_H