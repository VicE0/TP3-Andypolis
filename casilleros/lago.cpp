#include "lago.h"


Lago::Lago(int fila, int columna, string id_casillero): Casillero(fila, columna, id_casillero){
    this->nombre = "L";
    this->peso = 0;
}

string Lago::obtener_nombre(){
    return nombre;
}

void Lago::mostrar_casillero(){
    if (!jugador){
        cout << "\n Este es un lago y me encuentro vacio." << endl;
    }
    
    else{
        cout << "\n Este es un lago y no me encuentro vacio" << endl;
        jugador -> saludar();
    }
}

int Lago::obtener_costo_energia(int id_jugador){
    if(id_jugador == 1){
        return 2;
    } else {return 5;}
}

void Lago::agregar_edificio(string nombre,int id_jugador, int vida, int piedra, int madera, int metal, int maximo){
    cout << "\nEste es un lago , no se podran construir edificios en el. \n" << endl;
}

void Lago::agregar_material(string nombre, int cantidad){
}

void Lago::mostrar_coordenadas_edificio(string nombre){
    cout << "\nNo existe edificio construido\n" << endl;
}

void Lago::eliminar_edificio(){
    cout << "\nNo existe edificio en este casillero\n" << endl;
}

string Lago::obtener_nombre_edificio(){
    return "";
}

string Lago::obtener_nombre_material(){
    return "";
}

string Lago::obtener_diminutivo_edificio(){
    return "";
}


string Lago::obtener_diminutivo_material(){
    return "";
}

bool Lago::existe_edificio(){
    return false;
}

bool Lago::existe_material(){
    return false;
}

int Lago::obtener_fila(){
    return fila;
}

int Lago::obtener_columna(){
    return columna;
}

Edificio * Lago::obtener_edificio_construido(){
    Edificio * aux = 0;
    return aux;
}
void Lago::comprobar_destruccion_edificio(){}

Lago::~Lago(){
    if ( jugador ){
        delete jugador;
    }
    jugador = nullptr;
}