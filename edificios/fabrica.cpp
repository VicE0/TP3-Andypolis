#include "fabrica.h"

Fabrica::Fabrica(int id_jugador,int vida,int piedra, int madera, int metal, int maximo) : Edificio(id_jugador, vida, piedra, madera, metal, maximo){
    this->nombre = "fabrica";
    this->diminutivo = "F";
    this->brinda = 40;
}

int Fabrica::obtener_cantidad_brindada(){
    return brinda;
}

void Fabrica::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo : " << brinda << " de metal y me encuentro en el casillero consultado . " << endl;
}
