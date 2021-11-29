#ifndef JUGADA_H
#define JUGADA_H

#include "Objetivos.h"
#include "comprar_andypolis.h"
#include "edad_piedra.h"
#include "bombardero.h"
#include "energetico.h"
#include "letrado.h"
#include "minero.h"
#include "cansado.h"
#include "constructor.h"
#include "armado.h"
#include "extremista.h"

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