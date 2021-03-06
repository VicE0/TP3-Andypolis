#include "casillero.h"

Casillero::Casillero(){
    this->fila = 0;
    this->columna = 0;
    this->nombre = "A";
    this->jugador = 0;
    this->peso = 0;
}

Casillero::Casillero(int fila, int columna, string id_casillero){
    this->fila = fila;
    this->columna = columna;
    this->nombre = "";
    this->peso = 0;
    this->id_casillero = id_casillero;
    this->jugador = 0;
}

string Casillero::obtener_nombre(){
    return nombre;
}

int Casillero::obtener_fila(){
    return fila;
}

int Casillero::obtener_columna(){
    return columna;
}

void Casillero::agregar_jugador(Jugador * jugador){
    this->jugador = jugador;
    peso = INFINITO;
}

string Casillero::obtener_diminutivo_jugador(){
    string dim = "";
    if ( jugador != 0 ){
        dim = jugador->obtener_diminutivo();
    }
    return dim;
}

int Casillero::obtener_peso(){
    return peso;
}

string Casillero::obtener_id_casillero(){
    return id_casillero;
}

bool Casillero::existe_jugador(){
    bool existe = false;
    if ( jugador ){
        existe = true;
    }
    return existe;
}

int Casillero::devolver_id_jugador(){
    int id = 0;
    if ( jugador ){
        id = jugador->obtener_id();
    }
    return id;
}

Jugador * Casillero::obtener_jugador(){
    return jugador;
}