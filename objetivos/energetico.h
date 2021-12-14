#ifndef ENERGETICO_H
#define ENERGETICO_H

#include "../Objetivos.h"

#include <iostream>

using namespace std;

class Energetico : public Objetivo
{
    public:
        Energetico(int id_objetivo,int cantidad, bool cumplido);

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

#endif //ENERGETICO_H