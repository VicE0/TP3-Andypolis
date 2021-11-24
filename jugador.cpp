#include "jugador.h"


Jugador::Jugador(int id_jugador ,int energia, int objetivos_cumplidos, int andycoins_totales)
{
    this -> id_jugador = 0;
    this -> energia = ENERGIA_INICIAL; //dudoso, es solo al inicio
    this -> objetivos_cumplidos = 0;
    this -> andycoins_totales = 0;
    this->inventario = new Lista<Material>;
}

int Jugador::obtener_ID()
{
    return id_jugador;
}


Lista<Material> * Jugador::obtener_inventario(){
    return inventario;
}


void Jugador::agregar_material(Material * material)
{
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

bool Jugador::tiene_energia()
{
    return energia > 0;
}

