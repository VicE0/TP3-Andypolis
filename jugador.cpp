#include "jugador.h"

Jugador::Jugador(){
    this -> numero_jugador = 0;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
    this->inventario = new Lista<Material>;
}

Jugador::Jugador(string nombre, int numero_jugador ,int energia, int objetivos_cumplidos)
{
    this -> numero_jugador = 0;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
    this->inventario = new Lista<Material>;
}

string Jugador::obtener_nombre()
{
    return this -> nombre;
}

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

void Jugador::sumar_cantidad_material(string nombre, int cantidad){

    Material * aux = obtener_material(nombre);
    aux->sumar_material(cantidad);

}

void Jugador::restar_cantidad_material(string nombre, int cantidad){

    Material * aux = obtener_material(nombre);
    aux->restar_material(cantidad);

}

void Jugador::mostrar_inventario(){
    int cantidad = inventario->obtener_cantidad();
    for ( int i = 0; i < cantidad; i++){
        Material * aux = inventario->obtener_nodo(i)->obtener_dato();
        cout << "Nombre : " << aux->obtener_nombre();
        cout << " - Cantidad : " << aux->obtener_cantidad_disponible() << endl;
    }
}


