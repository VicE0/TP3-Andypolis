#include "jugador.h"

Jugador::Jugador(){
    this -> numero_jugador = 0;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
    this -> inventario = new Lista<Material>;
    this -> turno = 0;
    this -> diminutivo = "";
}

Jugador::Jugador(int numero_jugador, string diminutivo)
{
    this -> numero_jugador = numero_jugador;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
    this -> inventario = new Lista<Material>;
    this -> turno = 0;
    this -> diminutivo = diminutivo;
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

string Jugador::obtener_diminutivo(){
    return diminutivo;
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

bool Jugador::alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int 
cantidad_metal_nec){

    bool alcanza = true;
    int i = 0;
    int cantidad_de_materiales = inventario->obtener_cantidad();
    while (alcanza && i < cantidad_de_materiales){
        
        string material_a_chequear = inventario->obtener_nodo(i)->obtener_dato()->obtener_nombre();

        int cantidad_disponible = inventario->obtener_nodo(i)->obtener_dato()->obtener_cantidad_disponible();
        
        if (material_a_chequear == PIEDRA){
            chequear_material(cantidad_disponible, cantidad_piedra_nec, alcanza);
        } 
        if (material_a_chequear == MADERA){
            chequear_material(cantidad_disponible, cantidad_madera_nec, alcanza);
        } 
        if (material_a_chequear == METAL){
            chequear_material(cantidad_disponible, cantidad_metal_nec, alcanza);
        } 
        i++;
    }
    return alcanza;
}

void Jugador::chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza){
    if (cantidad_disponible < cantidad_material_nec){
                alcanza = false;
    }
}


void Jugador::utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int 
cantidad_metal_nec){
    
    int i = 0;
    int cantidad_de_materiales = inventario->obtener_cantidad();
    while (i < cantidad_de_materiales){
    
        string material_a_chequear = inventario->obtener_nodo(i)->obtener_dato()->obtener_nombre();

        if (material_a_chequear == PIEDRA){
            restar_cantidad_material(material_a_chequear, cantidad_piedra_nec);
        }
        if (material_a_chequear == MADERA){
            restar_cantidad_material(material_a_chequear,cantidad_madera_nec);
        } 
        if (material_a_chequear == METAL){
            restar_cantidad_material(material_a_chequear,cantidad_metal_nec);
        }
        i++;
    }
}

void Jugador::devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int 
cantidad_metal_nec){
    
    int i = 0;
    int cantidad_de_materiales = inventario->obtener_cantidad();

    while (i < cantidad_de_materiales){
    
        string material_a_chequear = inventario->obtener_nodo(i)->obtener_dato()->obtener_nombre();
        
        if (material_a_chequear == PIEDRA){
            sumar_cantidad_material(material_a_chequear,cantidad_piedra_nec);
        }
        if (material_a_chequear == MADERA){
            sumar_cantidad_material(material_a_chequear,cantidad_madera_nec);        
        } 
        if (material_a_chequear == METAL){
            sumar_cantidad_material(material_a_chequear,cantidad_metal_nec);
        }
        i++;
    }

};

