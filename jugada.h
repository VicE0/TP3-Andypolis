#ifndef JUGADA_H
#define JUGADA_H

#include "Objetivos.h"
#include "objetivos/comprar_andypolis.h"
#include "objetivos/edad_piedra.h"
#include "objetivos/bombardero.h"
#include "objetivos/energetico.h"
#include "objetivos/letrado.h"
#include "objetivos/minero.h"
#include "objetivos/cansado.h"
#include "objetivos/constructor.h"
#include "objetivos/armado.h"
#include "objetivos/extremista.h"

const int MAX_OBJETIVOS = 100;

class Jugada
{
    private:
        Objetivo* objetivos[MAX_OBJETIVOS];
        int cantidad_objetivos;


    public:

        Jugada();

        void mostrar_objetivos_jugador();

        int randomizar_objetivo();

        void cargar_objetivos();


};


#endif //JUGADA_H