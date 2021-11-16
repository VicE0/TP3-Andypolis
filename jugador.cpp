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

Material * Jugador::obtener_material(string nombre){
    Material * aux;

    for ( int i = 0 ; i < inventario->obtener_cantidad(); i++){
        if ( inventario->obtener_nodo(i)->obtener_dato()->obtener_nombre() == nombre ) {
            aux = inventario->obtener_nodo(i)->obtener_dato();
        }
    }

    return aux;
}

void Jugador::mostrar_cantidad_material(string nombre){

    Material * aux = obtener_material(nombre);

    aux->mostrar_nombre();

}

