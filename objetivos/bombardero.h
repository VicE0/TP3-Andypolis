#ifndef BOMBARDERO_H
#define BOMBARDERO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Bombardero : public Objetivo
{
    public:
        Bombardero(int id_objetivo,int cantidad, bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo);

   

};

#endif //BOMBARDERO_H