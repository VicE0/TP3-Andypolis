#include "casillero.h"

Casillero::Casillero(){
    this->fila = 0;
    this->columna = 0;
    this->nombre = "A";
    this->jugador = 0;
}

Casillero::Casillero(int fila, int columna){
    this->fila = fila;
    this->columna = columna;
    this->nombre = "";
}

string Casillero::obtener_nombre(){
    return nombre;
}

int Casillero::obtener_fila(){
    return fila;
}

int Casillero::obtener_columna(){
    return fila;
}

void Casillero::agregar_jugador(Jugador * jugador){
    this->jugador = jugador;
}

string Casillero::obtener_diminutivo_jugador(){
    string dim = "";
    if ( jugador != 0 ){
        dim = jugador->obtener_diminutivo();
    }
    return dim;
}