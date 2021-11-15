#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "../edificio.h"

class Aserradero: public Edificio {

private:

public:

    Aserradero(int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    void mostrar_mensaje();

};


#endif 