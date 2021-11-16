#ifndef JUGADOR_H 
#define JUGADOR_H

#include "lista.h"
#include "inventario.h"

class Jugador {
private:

    Lista<Material> * inventario;

public:

    Jugador();

    void agregar_material(Material * material);

    Lista<Material> * obtener_inventario();

};


#endif