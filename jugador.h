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

    Material * obtener_material(string nombre);

    void mostrar_cantidad_material( string nombre );

    Lista<Material> * obtener_inventario();

};


#endif