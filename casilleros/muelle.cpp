#include "muelle.h"

Muelle::Muelle(int fila, int columna): Casillero_transitable(fila, columna){
    this->nombre = "M";
}

void Muelle::mostrar_casillero(){
    if (!material){
        cout << " Soy un muelle y me encuentro vacio" << endl;
    }
    else{
        cout << " Soy un muelle y no me encuentro vacio" << endl;
        material -> saludar();
    }
}

string Muelle::obtener_nombre(){
    return nombre;
}

int Muelle::obtener_costo_energia(int codigo_jugador){
    if(codigo_jugador == 1){
        return 5;
    } else {return 2;}
}
