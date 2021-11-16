#include "jugador.h"

Jugador::Jugador(){
    this->usuario_inventario = 0;
}

Inventario * Jugador::obtener_inventario(){
    return usuario_inventario;
}
