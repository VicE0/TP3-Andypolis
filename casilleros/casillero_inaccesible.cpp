#include "casillero_inaccesible.h"


Casillero_inaccesible::Casillero_inaccesible(int fila, int columna): Casillero(fila, columna){
    this->nombre = "L";
}

string Casillero_inaccesible::obtener_nombre(){
    return nombre;
}

void Casillero_inaccesible::mostrar_casillero(){
    cout << " Este es un lago y es un casillero inaccesible. " << endl;
}

void Casillero_inaccesible::agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo){
    cout << "\nEste es un casillero inaccesible , no se podran construir edificios en el. \n" << endl;
}

void Casillero_inaccesible::agregar_material(string nombre, int cantidad){
}

void Casillero_inaccesible::mostrar_coordenadas_edificio(string nombre){
    cout << "\nNo existe edificio construido\n" << endl;
}

void Casillero_inaccesible::eliminar_edificio(){
    cout << "\nNo existe edificio en este casillero\n" << endl;
}

string Casillero_inaccesible::obtener_nombre_edificio(){
    return "";
}

string Casillero_inaccesible::obtener_nombre_material(){
    return "";
}

string Casillero_inaccesible::obtener_diminutivo_edificio(){
    return "";
}


string Casillero_inaccesible::obtener_diminutivo_material(){
    return "";
}

bool Casillero_inaccesible::existe_edificio(){
    return false;
}

bool Casillero_inaccesible::existe_material(){
    return false;
}

int Casillero_inaccesible::obtener_fila(){
    return fila;
}

int Casillero_inaccesible::obtener_columna(){
    return columna;
}