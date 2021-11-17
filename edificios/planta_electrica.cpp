#include "planta_electrica.h"

Planta_electrica::Planta_electrica(int piedra, int madera, int metal, int maximo) : Edificio( piedra, madera, metal, maximo){
    this->nombre = "planta electrica";
    this->diminutivo = "P";
    this->brinda = 0;
}

int Planta_electrica::obtener_cantidad_brindada(){
    return brinda;
}

void Planta_electrica::mostrar_mensaje(){
    cout << " Soy una " << nombre << " no brindo materiales, me encuentro en el casillero consultado . " << endl;
}