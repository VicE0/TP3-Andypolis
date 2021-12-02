#include "escuela.h"

Escuela::Escuela(int id_jugador,int vida,int piedra, int madera, int metal, int maximo) : Edificio(id_jugador, vida, piedra, madera, metal, maximo){
    this->nombre = "escuela";
    this->diminutivo = "E";
    this->brinda = 25;
}

int Escuela::obtener_cantidad_brindada(){
    return brinda;
}

void Escuela::mostrar_mensaje(){
    cout << " Soy una " << nombre << " no brindo materiales y me encuentro en el casillero consultado . " << endl;
}