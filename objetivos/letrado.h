#ifndef LETRADO_H
#define LETRADO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Letrado : public Objetivo
{
    public:
        Letrado(int id_objetivo,int cantidad, bool cumplido);

        void mostrar_descripcion();

        void mostrar_progreso();

        void progreso(Lista <Material> * inventario, int &energia , Edificio * edificio_objetivo);


};

#endif //LETRADO_H