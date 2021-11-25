#include "terreno.h"

Terreno::Terreno(int fila, int columna): Casillero(fila, columna){
    this->nombre = "T";
    this->edificio_construido = 0;
}

string Terreno::obtener_nombre(){
    return nombre;
}

int Terreno::obtener_costo_energia(int JUGADOR_1){
    return 25;
}

void Terreno::mostrar_casillero(){
    if ( ! edificio_construido ){
        cout << " Soy un terreno y me encuentro vacio" << endl;
    }
    else{
        cout << " Soy un terreno y no me encuentro vacio" << endl;
        edificio_construido->mostrar_mensaje();
    }
}

void Terreno::agregar_edificio(string nombre,int id_jugador, int piedra, int madera, int metal, int maximo){
    if ( ! edificio_construido ){
        if (nombre == "aserradero"){

            this->edificio_construido = new Aserradero(id_jugador,piedra, madera, metal, maximo);

        }
        else if ( nombre == ESCUELA){ 

            this->edificio_construido = new Escuela( id_jugador,piedra, madera, metal, maximo);

        }
        else if ( nombre == FABRICA){

            this->edificio_construido = new Fabrica( id_jugador,piedra, madera, metal, maximo);

        }
        else if ( nombre == MINA){

            this->edificio_construido = new Mina( id_jugador,piedra, madera, metal, maximo);

        }
        else if ( nombre == MINA){

            this->edificio_construido = new Obelisco( id_jugador,piedra, madera, metal, maximo);

        }
        else if ( nombre == PLANTA_ELECTRICA){

            this->edificio_construido = new Planta_electrica( id_jugador,piedra, madera, metal, maximo);

        }
        else if ( nombre == MINA_ORO){

            this->edificio_construido = new Mina_oro( id_jugador,piedra, madera, metal, maximo);

        }
    } else {
        cout << "\n El casillero ya esta ocupado.\n" << endl;
    }

}


void Terreno::agregar_material(string nombre, int cantidad){
}

string Terreno::obtener_nombre_edificio(){

    string nombre_edificio = "";
    if ( edificio_construido ){
        nombre_edificio = edificio_construido->obtener_nombre();
    }
    return nombre_edificio;

}


string Terreno::obtener_nombre_material(){
    return "";
}

string Terreno::obtener_diminutivo_edificio(){

    string diminutivo = "";
    if ( edificio_construido ){
        diminutivo = edificio_construido->obtener_diminutivo() ;
    }
    return diminutivo;
}

string Terreno::obtener_diminutivo_material(){
    return "";
}

void Terreno::eliminar_edificio(){
    delete edificio_construido;
    edificio_construido = 0;

}

bool Terreno::existe_edificio(){
    bool existe = false;
    if ( edificio_construido ){
        existe = true;
    }
    return existe;
}

bool Terreno::existe_material(){
    return false;
}

void Terreno::mostrar_coordenadas_edificio(string nombre){

    if ( edificio_construido ){

        if ( nombre == edificio_construido->obtener_nombre()){

            cout << " - (" << fila << "," << columna << ") " << endl;
        }
    }
}

Terreno::~Terreno(){
    if ( edificio_construido ){
        delete edificio_construido;
    }
    edificio_construido = 0;
}

int Terreno::obtener_fila(){
    return fila;
}

int Terreno::obtener_columna(){
    return columna;
}

Edificio * Terreno::obtener_edificio_construido(){
    Edificio * aux = 0;
    if ( edificio_construido != 0 ){
        aux = edificio_construido;
    }
    return aux;
}
