
#ifndef JUGADOR_H
#define JUGADOR_H

const int ENERGIA_INICIAL = 50;

#include "lista.h"
#include "inventario.h"

#include <string>
using std::string;

class Jugador
{

    private:
        int id_jugador; // El mismo que va para identificar los edificios de c/u (1 - 2)
        int energia;
        int objetivos_cumplidos;
        int andycoins_totales; // debe ser un contador, el objetivo tiene en cuenta TODAS las coins usadas/recolectadas
        Lista<Material> * inventario;

    public:

        // -------------------------------- Constructores --------------------------------

        Jugador(int id_jugador,int energia, int objetivos_cumplidos, int andycoins_totales);

        // -------------------------------- Getters --------------------------------

        //PRE: ~
        //POST: Devuelve el ID del jugador (1 / 2)
        int obtener_ID();

        //PRE: ~
        //POST: Obtiene la cantidad de energia del jugador 
        int obtener_energia();

        //PRE: ~
        //POST: Devuelve TRUE si la energía del jugador es suficiente para realizar la opción
        bool tiene_energia();

        //Obtener bombas / andycoins ?

        Material * obtener_material(string nombre);

        Lista<Material> * obtener_inventario();


        // -------------------------------- Funciones jugador --------------------------------

        void agregar_material(Material * material);


        void mostrar_cantidad_material( string nombre );

        // Destructor, seguro lo necesitamos para liberar el inventario
        // ~Jugador();

        
};


#endif //JUGADOR_H

