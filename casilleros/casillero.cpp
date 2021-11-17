#include "casillero.h"

Casillero::Casillero(){
    this->fila = 0;
    this->columna = 0;
    this->nombre = "A";
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

Casillero::~Casillero(){}