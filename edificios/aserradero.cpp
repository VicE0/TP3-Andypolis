#include "aserradero.h"

Aserradero::Aserradero(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "aserradero";
    this->diminutivo = "A";
    this->brinda = 25;
}

int Aserradero::obtener_cantidad_brindada(){
    return brinda;
}

void Aserradero::mostrar_mensaje(){
    cout << " Soy un " << nombre << " brindo : " << brinda << " de madera y me encuentro en el casillero consultado . " << endl;
}