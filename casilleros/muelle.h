#ifndef MUELLE_H
#define MUELLE_H

#include "casillero_transitable.h"


class Muelle : public Casillero_transitable {
public:

    //Constructor de Muelle
    //PRE: Recibe un entero con la fila y otro con la columna
    //POST: Construye un Muelle con nombre = "M".
    Muelle(int fila, int columna);

    //PRE: -
    //POS: muestra por pantalla un mensaje diciendo que que el casillero es un Muelle.
    void mostrar_casillero();

    //PRE:
    //POST: Devuelve un string con el nombre del casillero, en este caso "M" pues es un Muelle
    string obtener_nombre();

    //PRE: Le pido el codigo paras aber que jugador es.
    //POST: Devuelve un int con el costo de energia para transitar por este casillero.
    int obtener_costo_energia(int codigo_jugador);

    //Destructor de Muelle
    ~Muelle();
};


#endif