#ifndef OBJETIVO_OBELISCO_H
#define OBJETIVO_OBELISCO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Objetivo_obelisco: public Objetivo
{
    public:
        //CONSTRUCTOR
        Objetivo_obelisco(int id_objetivo,int cantidad, bool cumplido);

        //PRE: -
        //POS: Muestra la descripcion del objetivo
        void mostrar_descripcion();

        //PRE:
        //POS: Muestra como va el progreso del objetivo
        void mostrar_progreso();

        //PRE: Recibe la lista, la energia y un puntero de edificio del jugador
        //POS: Evalua como va el progresp y si se cumplió el objetivo o no
        void progreso(Lista <Material> *inventario, int &energia, Edificio * edificio_objetivo);

};

#endif //OBJETIVO_OBELISCO_H