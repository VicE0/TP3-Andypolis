#include "betun.h"

Betun::Betun(int fila, int columna, string id_casillero): Casillero(fila, columna, id_casillero){
    this->nombre = "B";
    this->material = 0;
}

void Betun::mostrar_casillero(){
    if (!material && !jugador){
        cout << "\n Soy un Betun y me encuentro vacio" << endl;
    }
    
    else{
        cout << "\n Soy un Betun y no me encuentro vacio" << endl;
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

string Betun::obtener_nombre(){
    return nombre;
}

int Betun::obtener_costo_energia(int id_jugador){
    return peso;
}

void Betun::agregar_edificio(string nombre, int id_jugador, int vida,int piedra, int madera, int metal, int maximo){
    cout << "\nEste es un betun no se podran construir edificios en el. \n" << endl;
}

void Betun::agregar_material(string nombre, int cantidad){
    if (!material){
        this->material = new Material(nombre, cantidad);
    }
}

void Betun::mostrar_coordenadas_edificio(string nombre){
    cout << "\nNo existe edificio construido\n" << endl;
}

void Betun::eliminar_edificio(){
    cout << "\nNo existe edificio en este casillero\n" << endl;
}

string Betun::obtener_nombre_edificio(){
    return "";
}

string Betun::obtener_nombre_material(){
    return material -> obtener_nombre();
}

string Betun::obtener_diminutivo_edificio(){
    return "";
}

string Betun::obtener_diminutivo_material(){
    string diminutivo = "";
    if ( material ){
        diminutivo = material->obtener_diminutivo() ;
    }
    return diminutivo;

}

bool Betun::existe_edificio(){
    return false;
}

bool Betun::existe_material(){
    bool existe = false;
    if ( material ){
        existe = true;
    }
    return existe;
}

int Betun::obtener_fila(){
    return fila;
}

int Betun::obtener_columna(){
    return columna;
}

Edificio * Betun::obtener_edificio_construido(){
    Edificio * aux = 0;
    return aux;
}

void Betun::comprobar_destruccion_edificio(){}

Material * Betun::devolver_material(){
    return material;
}

void Betun::sacar_material(){
    if (existe_material()){
        delete material;
        material = 0;
    }
}

void Betun::eliminar_jugador(){
    if (jugador){
    jugador = nullptr;
    peso = 0;
    }
}

Betun::~Betun(){
    cout << " destructor de betun " << endl;
    if ( material ){
        delete material;
    }
    material = 0;

    if ( jugador ){
        delete jugador;
    }
    jugador = nullptr;
}

