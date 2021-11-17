#ifndef FABRICA_H
#define FABRICA_H

#include "../edificio.h"

class Fabrica: public Edificio {

private:

public:

    Fabrica(int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    void mostrar_mensaje();

};

#endif