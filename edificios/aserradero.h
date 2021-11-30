#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "../edificio.h"

class Aserradero: public Edificio {

private:

public:

    Aserradero(int id_jugador, int vida, int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    void mostrar_mensaje();

};


#endif 