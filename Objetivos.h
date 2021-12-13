#ifndef OBJETIVOS_H
#define OBJETIVOS_H

#include <string>
using std::string;

#include "material.h"
#include "edificio.h"
#include "lista.h"


const int CONSTRUIR_OBELISCO = 1;
const int COMPRAR_ANDYPOLIS = 2;
const int EDAD_PIEDRA= 3;
const int BOMBARDERO = 4;
const int ENERGETICO = 5;
const int LETRADO = 6;
const int MINERO = 7;
const int CANSADO = 8;
const int CONSTRUCTOR = 9;
const int ARMADO = 10;
const int EXTREMISTA = 11;


class Objetivo
{
    protected:
        int id_objetivo;
        int cantidad;
        
        bool cumplido;
      
        bool mina_construida;
        bool mina_oro_construida;
        bool obelisco_construido;
        bool aserradero_construido;
        bool escuela_construida;
        bool fabrica_construida;
        bool planta_electrica_construida;

        int minas_construidas;
        int edificios_construidos;
        int energia_jugador;
        int bombas_inventario;
        int piedras_inventario;
        int escuelas_construidas;

        int andycoins_totales; 
        int bombas_usadas;
        int bombas_compradas;
        
        
        
        
        

    public:
        //  ----- Constructores ------
        // PRE: ~
        // POST : Inicializa los valores en 0 
        Objetivo();

        // PRE: ~
        // POST: Carga los valores 
        Objetivo(int id_objetivo, int cantidad, bool cumplido);

        //------ Getters ---------

        //PRE: ~
        //POS: Devuelve el numero que le representa el objetivo
        int obtener_objetivo();


        //PRE: ~
        //POS: Devuelve el atributo cumplido
        bool objetivo_cumplido();


        // ------ Metodos virtuales -----

        virtual void mostrar_descripcion() = 0;

        virtual void mostrar_progreso() = 0;

        virtual void progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo) = 0;


        ~Objetivo();

};



#endif //OBJETIVOS_H