#ifndef EDAD_PIEDRA_H
#define EDAD_PIEDRA_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Edad_piedra : public Objetivo
{
    public:
        Edad_piedra(int id_objetivo,int cantidad,  bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo);


};

#endif //EDAD_PIEDRA_H