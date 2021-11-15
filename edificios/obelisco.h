#ifndef OBELISCO_H
#define OBELISCO_H

#include "../edificio.h"

class Obelisco: public Edificio {

private:

public:

    Obelisco(int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    void mostrar_mensaje();

};

#endif