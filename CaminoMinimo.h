#ifndef CAMINO_MINIMO_H
#define CAMINO_MINIMO_H

#include "lista.h"
#include "casilleros/casillero.h"
#include <iostream>

const int INFINITO = 99999999;

class CaminoMinimo {
protected:
    int ** matriz_adyacente;
    Lista<Casillero*> * vertices;
    int canitdad_vertices;
public:
    CaminoMinimo(Lista<Casillero*> * vertices, int ** matriz_adyacente);

    virtual void camino_minimo(int origen, int destino) = 0;

    virtual ~CaminoMinimo() = default;
};


#endif