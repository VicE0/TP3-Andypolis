#include "muelle.h"

Muelle::Muelle(int fila, int columna, string id_casillero): Casillero(fila, columna, id_casillero){
    this->nombre = "M";
    this->material = 0;
}

void Muelle::mostrar_casillero(){
    if (!material && !jugador){
        cout << "\n Soy un muelle y me encuentro vacio" << endl;
    }
    
    else{
        cout << "\n Soy un muelle y no me encuentro vacio" << endl;
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

string Muelle::obtener_nombre(){
    return nombre;
}

int Muelle::obtener_costo_energia(int id_jugador){
    if(id_jugador == 1 && peso != INFINITO){
        return 5;
    } else if (id_jugador == 2 && peso != INFINITO){
        return 2;
    } else {return peso;}
}


void Muelle::agregar_edificio(string nombre, int id_jugador, int vida,int piedra, int madera, int metal, int maximo){
    cout << "\nEste es un muelle no se podran construir edificios en el. \n" << endl;
}

void Muelle::agregar_material(string nombre, int cantidad){
    if (!material){
        this->material = new Material(nombre, cantidad);
    }
}

void Muelle::mostrar_coordenadas_edificio(string nombre){
    cout << "\nNo existe edificio construido\n" << endl;
}

void Muelle::eliminar_edificio(){
    cout << "\nNo existe edificio en este casillero\n" << endl;
}

string Muelle::obtener_nombre_edificio(){
    return "";
}

string Muelle::obtener_nombre_material(){
    return material -> obtener_nombre();
}

string Muelle::obtener_diminutivo_edificio(){
    return "";
}

string Muelle::obtener_diminutivo_material(){
    string diminutivo = "";
    if ( material ){
        diminutivo = material->obtener_diminutivo() ;
    }
    return diminutivo;

}

bool Muelle::existe_edificio(){
    return false;
}

bool Muelle::existe_material(){
    bool existe = false;
    if ( material ){
        existe = true;
    }
    return existe;
}


int Muelle::obtener_fila(){
    return fila;
}

int Muelle::obtener_columna(){
    return columna;
}

Edificio * Muelle::obtener_edificio_construido(){
    Edificio * aux = 0;
    return aux;
}

void Muelle::comprobar_destruccion_edificio(){}

Material * Muelle::devolver_material(){
    return material;
}

void Muelle::sacar_material(){
    if (existe_material()){
        delete material;
        material = 0;
    }
}

void Muelle::eliminar_jugador(){
    if (jugador){
    jugador = nullptr;
    peso = 0;
    }
}


Muelle::~Muelle(){
    cout << " destructor de muelle " << endl;
    if ( material ){
        delete material;
    }
    material = 0;
    if ( jugador ){
        delete jugador;
    }
    jugador = nullptr;
}
