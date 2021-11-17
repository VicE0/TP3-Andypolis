#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using std::string;

class Jugador
{

    private:
        string nombre;
        int numero_jugador;
        int energia;
        int objetivos_cumplidos;
        //AGREGAR PARTE DE MATERIALES HECHA POR GIAN

    public:

        Jugador(string nombre, int numero_jugador ,int energia, int objetivos_cumplidos); //constructor

        //PRE: ~
        //POST: Devuelve el nombre del jugador
        string obtener_nombre();

        //PRE: ~
        //POST: Devuelve el numero del jugador (1 o 2)
        int dar_numero();

        // //PRE: ~
        // //POST: Devuelve TRUE si la energía del jugador es suficiente para realizar la opción
        // bool tiene_energia();


        // //Destructor, seguro lo necesitamos para liberar el inventario
        // ~Jugador();


};




#endif //JUGADOR_H