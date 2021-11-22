#ifndef MINA_ORO_H
#define MINA_ORO_H

#include "../edificio.h"

class Mina_oro: public Edificio {

private:

public:

    Mina_oro(int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    void mostrar_mensaje();

};

#endif