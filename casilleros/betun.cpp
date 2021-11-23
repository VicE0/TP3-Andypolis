#include "betun.h"

Betun::Betun(int fila, int columna): Casillero_transitable(fila, columna){
    this->nombre = "B";
}

void Betun::mostrar_casillero(){
    if (!material){
        cout << " Soy un betun y me encuentro vacio" << endl;
    }
    else{
        cout << " Soy un betun y no me encuentro vacio" << endl;
        material -> saludar();
    }
}

string Betun::obtener_nombre(){
    return nombre;
}

int Betun::obtener_costo_energia(){
    return 0;
}

Betun::~Betun(){}