#include "mina_oro.h"

Mina_oro::Mina_oro(int id_jugador,int piedra, int madera, int metal, int maximo) : Edificio( id_jugador,piedra, madera, metal, maximo){
    this->nombre = "mina oro";
    this->diminutivo = "G";
    this->brinda = 50;
}

int Mina_oro::obtener_cantidad_brindada(){
    return brinda;
}

void Mina_oro::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo 50 andycoins y me encuentro en el casillero consultado . " << endl;
}