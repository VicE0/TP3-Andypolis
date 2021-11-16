#include "jugador.h"

Jugador::Jugador(){

    this->inventario = new Lista<Material>;
}

Lista<Material> * Jugador::obtener_inventario(){
    return inventario;
}

void Jugador::agregar_material(Material * material){

    inventario->alta(material, inventario->obtener_cantidad());

}

