#include "jugada.h"

#include <iostream>
#include <fstream>
#include <string>

Jugada::Jugada()
{
    this -> cantidad_objetivos = 0;
    this -> cargar_objetivos();
}


void Jugada::cargar_objetivos()
{
    int id_objetivo = asignar_objetivo();
    int cantidad;

    switch(id_objetivo)
    {
        case COMPRAR_ANDYPOLIS:
            this ->objetivos[cantidad_objetivos] = new Comprar_andypolis(id_objetivo, cantidad);
            break;

        case EDAD_PIEDRA:
            break;

        case BOMBARDERO:
            break;

        case ENERGETICO:
            break;

        case LETRADO:
            break;

        case MINERO:
            break;

        case CANSADO:
            break;

        case CONSTRUCTOR:
            break;

        case ARMADO:
            break;

        case EXTREMISTA:
            break;


    }

    // this -> objetivos[cantidad_objetivos] = new Construir_obelisco(id_objetivo, cantidad);

    cantidad_objetivos++;
}


int Jugada::asignar_objetivo()
{
    int objetivo_dado = 2 + rand() % (12 -2); //El 1 nunca se randomiza porque siempre se asgina (obelisco)

    return objetivo_dado;
}


void Jugada::mostrar_objetivos_jugador()
{
    
    for(int i = 0; i < cantidad_objetivos; i++)
    {
        this -> objetivos[i] -> mostrar_descripcion();
    }
}
