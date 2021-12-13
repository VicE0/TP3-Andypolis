#include "camino.h"

Camino::Camino(int fila, int columna, string id_casillero): Casillero(fila, columna, id_casillero){
    this->nombre = "C";
    this->material = 0;
    this->peso = 4;
}

void Camino::mostrar_casillero(){
    if (!material && !jugador){
        cout << "\n Soy un camino y me encuentro vacio" << endl;
    }

    else{
        cout << "\n Soy un camino y no me encuentro vacio" << endl;
        if (material && !jugador)
            material -> saludar();
        else if (!material && jugador)
            jugador -> saludar();
        else{
            jugador -> saludar();
            material -> saludar();
        }
    }
}

string Camino::obtener_nombre(){
    return nombre;
}

int Camino::obtener_costo_energia(int id_jugador){
    return 4;
}

void Camino::agregar_edificio(string nombre,int id_jugador, int vida,int piedra, int madera, int metal, int maximo){
    cout << "\nEste es un camino no se podran construir edificios en el. \n" << endl;
}

void Camino::agregar_material(string nombre, int cantidad){
    if (!material){
        this->material = new Material(nombre, cantidad);
    }
}

void Camino::mostrar_coordenadas_edificio(string nombre){
    cout << "\nNo existe edificio construido\n" << endl;
}

void Camino::eliminar_edificio(){
    cout << "\nNo existe edificio en este casillero\n" << endl;
}

string Camino::obtener_nombre_edificio(){
    return "";
}

string Camino::obtener_nombre_material(){
    return material -> obtener_nombre();
}

string Camino::obtener_diminutivo_edificio(){
    return "";
}

string Camino::obtener_diminutivo_material(){
    string diminutivo = "";
    if ( material ){
        diminutivo = material->obtener_diminutivo() ;
    }
    return diminutivo;

}

bool Camino::existe_edificio(){
    return false;
}

bool Camino::existe_material(){
    bool existe = false;
    if ( material ){
        existe = true;
    }
    return existe;
}

int Camino::obtener_fila(){
    return fila;
}

int Camino::obtener_columna(){
    return columna;
}

Edificio * Camino::obtener_edificio_construido(){
    Edificio * aux = 0;
    return aux;
}

void Camino::comprobar_destruccion_edificio(){}

Camino::~Camino(){
    if ( material ){
        delete material;
    }
    material = 0;

    if ( jugador ){
        delete jugador;
    }
    jugador = nullptr;
}
