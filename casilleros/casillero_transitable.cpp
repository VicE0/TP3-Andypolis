#include "casillero_transitable.h"

Casillero_transitable::Casillero_transitable(int fila, int columna): Casillero(fila, columna){
    this->nombre = "C";
    this->material = 0;
}

string Casillero_transitable::obtener_nombre(){
    return nombre;
}

void Casillero_transitable::mostrar_casillero(){
    if (!material){
        cout << " Soy un casillero transitable y me encuentro vacio" << endl;
    }
    else{
        cout << " Soy un casillero transitable y no me encuentro vacio" << endl;
        material -> saludar();
    }
}

void Casillero_transitable::agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo){
    cout << "\nEste es un casillero transitable no se podran construir edificios en el. \n" << endl;
}

void Casillero_transitable:: agregar_material(string nombre, int cantidad){
    if (!material){
        this->material = new Material(nombre, cantidad);
    }
}

void Casillero_transitable::mostrar_coordenadas_edificio(string nombre){
    cout << "\nNo existe edificio construido\n" << endl;
}

void Casillero_transitable::eliminar_edificio(){
    cout << "\nNo existe edificio en este casillero\n" << endl;
}

string Casillero_transitable::obtener_nombre_edificio(){
    return "";
}

string Casillero_transitable::obtener_nombre_material(){
    return material -> obtener_nombre();
}

string Casillero_transitable::obtener_diminutivo_edificio(){
    return "";
}

string Casillero_transitable::obtener_diminutivo_material(){
    string diminutivo = "";
    if ( material ){
        diminutivo = material->obtener_diminutivo() ;
    }
    return diminutivo;

}

bool Casillero_transitable::existe_edificio(){
    return false;
}

bool Casillero_transitable::existe_material(){
    bool existe = false;
    if ( material ){
        existe = true;
    }
    return existe;
}

Casillero_transitable::~Casillero_transitable(){
    if ( material ){
        delete material;
    }
    material = 0;
}

int Casillero_transitable::obtener_fila(){
    return fila;
}

int Casillero_transitable::obtener_columna(){
    return columna;
}