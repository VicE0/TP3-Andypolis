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
    srand (time(NULL)); //inicializo el random seed
    for (int i = 0; i < 3; i++)
    {
        
        int id_objetivo = randomizar_objetivo();
        int cantidad;

        switch(id_objetivo)
        {
            case COMPRAR_ANDYPOLIS:
                this ->objetivos[cantidad_objetivos] = new Comprar_andypolis(id_objetivo, cantidad);
                break;

            case EDAD_PIEDRA:
                this -> objetivos[cantidad_objetivos] = new Edad_piedra(id_objetivo, cantidad);
                break;

            case BOMBARDERO:
                this -> objetivos[cantidad_objetivos] = new Bombardero(id_objetivo, cantidad);
                break;

            case ENERGETICO:
                this -> objetivos[cantidad_objetivos] = new Energetico(id_objetivo, cantidad);
                break;

            case LETRADO:
                this -> objetivos[cantidad_objetivos] = new Letrado(id_objetivo, cantidad);
                break;

            case MINERO:
                this -> objetivos[cantidad_objetivos] = new Minero(id_objetivo, cantidad);
                break;

            case CANSADO:
                this -> objetivos[cantidad_objetivos] = new Cansado(id_objetivo, cantidad);
                break;

            case CONSTRUCTOR:
                this -> objetivos[cantidad_objetivos] = new Constructor(id_objetivo, cantidad);
                break;

            case ARMADO:
                this -> objetivos[cantidad_objetivos] = new Armado(id_objetivo, cantidad);
                break;

            case EXTREMISTA:
                this -> objetivos[cantidad_objetivos] = new Extremista(id_objetivo, cantidad);
                break;


        }

    // this -> objetivos[cantidad_objetivos] = new Construir_obelisco(id_objetivo, cantidad);

    cantidad_objetivos++;
    }
}



int Jugada::randomizar_objetivo()
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
