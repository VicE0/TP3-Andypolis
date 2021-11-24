#include "jugador.h"

Jugador::Jugador(){
    this -> numero_jugador = 0;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
    this -> inventario = new Lista<Material>;
    this -> turno = 0;
}

Jugador::Jugador(int numero_jugador)
{
    this -> numero_jugador = numero_jugador;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
    this -> inventario = new Lista<Material>;
    this -> turno = 0;
}

/*
string Jugador::obtener_nombre()
{
    return this -> nombre;
}
*/

int Jugador::dar_numero()
{
    return this ->numero_jugador;
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

void Jugador::establecer_turno(int turno){
    this -> turno = turno;
}

int Jugador::obtener_turno(){
    return turno;
}