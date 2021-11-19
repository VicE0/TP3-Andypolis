#ifndef ESCUELA_H
#define ESCUELA_H

#include "../edificio.h"

class Escuela: public Edificio {

private:

public:

    Escuela(int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    void mostrar_mensaje();

};


#endif 