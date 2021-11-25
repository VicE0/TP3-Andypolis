#ifndef JUGADA_H
#define JUGADA_H

#include "Objetivos.h"
#include "objetivos/comprar_andypolis.h"

const int MAX_OBJETIVOS = 100;

class Jugada
{
    private:
        Objetivo* objetivos[MAX_OBJETIVOS];
        int cantidad_objetivos;


    public:

        Jugada();

        void mostrar_objetivos_jugador();

        int asignar_objetivo();

        void cargar_objetivos(); //carga el array

};


#endif //JUGADA_H