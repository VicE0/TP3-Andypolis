#include "camino.h"

Camino::Camino(int fila, int columna): Casillero_transitable(fila, columna){
    this->nombre = "C";
}

void Camino::mostrar_casillero(){
    if (!material){
        cout << " Soy un camino y me encuentro vacio" << endl;
    }
    else{
        cout << " Soy un camino y no me encuentro vacio" << endl;
        material -> saludar();
    }
}

string Camino::obtener_nombre(){
    return nombre;
}

int Camino::obtener_costo_energia(){
    return 4;
}

Camino::~Camino(){}
