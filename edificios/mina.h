#ifndef MINA_H
#define MINA_H

#include "../edificio.h"

class Mina: public Edificio {

private:


public:

    Mina(int id_jugador, int vida, int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    void mostrar_mensaje();


};

#endif