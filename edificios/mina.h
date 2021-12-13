#ifndef MINA_H
#define MINA_H

#include "../edificio.h"

class Mina: public Edificio {

private:


public:

    // PRE: Le pido como parametro todos los enteros para poder inicializar el edificio.
    // POS: Creo el edificio con todas las caracteristicas del mismo.
    Mina(int id_jugador, int vida, int piedra, int madera, int metal, int maximo);

    // PRE: -
    // POS: Devuelve la cantidad del material que produce
    int obtener_cantidad_brindada();

    // PRE: -
    // POS: Muestra un mensaje por pantalla diciendo su nombre y la cantidad del material que brinda,
    void mostrar_mensaje();



};

#endif