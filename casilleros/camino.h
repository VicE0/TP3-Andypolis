#ifndef CAMINO_H
#define CAMINO_H

#include "casillero_transitable.h"


class Camino : public Casillero_transitable {
public:

    //Constructor de camino
    //PRE: Recibe un entero con la fila y otro con la columna
    //POST: Construye un camino con nombre = "c".
    Camino(int fila, int columna);

    //PRE: -
    //POS: muestra por pantalla un mensaje diciendo que que el casillero es un camino.
    void mostrar_casillero();

    //PRE:
    //POST: Devuelve un string con el nombre del casillero, en este caso "C" pues es un camino
    string obtener_nombre();

    //PRE:
    //POST: Devuelve un int con el costo de energia para transitar por este casillero.
    int obtener_costo_energia();

    //Destructor de camino
    ~Camino();
};


#endif