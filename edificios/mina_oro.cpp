#include "mina_oro.h"

Mina_oro::Mina_oro(int piedra, int madera, int metal, int maximo) : Edificio( piedra, madera, metal, maximo){
    this->nombre = "planta electrica";
    this->diminutivo = "P";
    this->brinda = 0;
}

int Mina_oro::obtener_cantidad_brindada(){
    return brinda;
}

void Mina_oro::mostrar_mensaje(){
    cout << " Soy una " << nombre << " no brindo materiales, me encuentro en el casillero consultado . " << endl;
}