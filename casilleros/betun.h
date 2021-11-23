#ifndef BETUN_H
#define BETUN_H

#include "casillero_transitable.h"


class Betun : public Casillero_transitable {
public:

    //Constructor de Betun
    //PRE: Recibe un entero con la fila y otro con la columna
    //POST: Construye un Betun con nombre = "B".
    Betun(int fila, int columna);

    //PRE: -
    //POS: muestra por pantalla un mensaje diciendo que que el casillero es un Betun.
    void mostrar_casillero();

    //PRE:
    //POST: Devuelve un string con el nombre del casillero, en este caso "C" pues es un Betun
    string obtener_nombre();

    //PRE:
    //POST: Devuelve un int con el costo de energia para transitar por estee casillero.
    int obtener_costo_energia();

    //Destructor de Betun
    ~Betun();
};


#endif