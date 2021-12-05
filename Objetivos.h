#ifndef OBJETIVOS_H
#define OBJETIVOS_H

#include <string>
using std::string;

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
        int andycoins_totales; 
        // bool obelisco_construido;
        

    public:
        //  ----- Constructores ------
        // PRE: ~
        // POST : Inicializa los valores en 0 
        Objetivo();

        // PRE: ~
        // POST: Carga los valores 
        Objetivo(int id_objetivo, int cantidad, int andycoins_totales);

        //------ Getters ---------

        int obtener_objetivo();


        // ------ Metodos virtuales -----

        virtual bool objetivo_cumplido() = 0;

        virtual void mostrar_descripcion() = 0;

        virtual void mostrar_progreso() = 0;

        ~Objetivo();

};



#endif //OBJETIVOS_H