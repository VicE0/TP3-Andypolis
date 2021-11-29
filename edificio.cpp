#include "edificio.h"

Edificio::Edificio(){
    this->id_jugador = 1;
    this-> nombre = "nada";
    this-> diminutivo = "";
    this-> cantidad_piedra = 0;
    this-> cantidad_madera = 0;
    this-> cantidad_metal = 0;
    this-> cantidad_edificios = 0;
    this-> brinda = 0;
    this-> maximo_construir = 0;
    this-> vida = 1;
    this-> vida_max = 1;
}

Edificio::Edificio(int id_jugador, int vida, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir){
    this-> id_jugador = id_jugador;
    this-> nombre = "";
    this-> diminutivo = "Ed";
    this-> cantidad_piedra = cantidad_piedra;
    this-> cantidad_madera = cantidad_madera;
    this-> cantidad_metal = cantidad_metal;
    this-> cantidad_edificios = 0;
    this-> brinda = 0;
    this-> maximo_construir = maximo_construir;
    this-> vida = vida;
    this-> vida_max = vida;

}

string Edificio::obtener_nombre(){
    return nombre;
}

string Edificio::obtener_diminutivo(){
    return diminutivo;
}

int Edificio::obtener_cantidad_piedra(){
    return cantidad_piedra;
}
int Edificio::obtener_cantidad_madera(){
    return cantidad_madera;
}
int Edificio::obtener_cantidad_metal(){
    return cantidad_metal;
}

int Edificio::obtener_cantidad_construidos(){
    return cantidad_edificios;
}

int Edificio::obtener_maximo_construir(){
    return maximo_construir;
}

int Edificio::obtener_mitad_madera(){
    return cantidad_madera/2;
}

int Edificio::obtener_mitad_piedra(){
    return cantidad_piedra/2;
}

int Edificio::obtener_mitad_metal(){
    return cantidad_metal/2;
}

int Edificio::obtener_cuantos_puedo_construir(){
    int restantes = maximo_construir - cantidad_edificios ;
    return restantes;
}

void Edificio::sumar_cantidad(){
    cantidad_edificios++ ;
}

void Edificio::restar_cantidad(){
    cantidad_edificios-- ;
}

Edificio::~Edificio(){}

int Edificio::obtener_id_jugador(){
    return id_jugador;
}

void Edificio::modificar_cantidad_material(string nombre_material, int nueva_cantidad){
    if (nombre_material == PIEDRA){
        modificar_cantidad_piedra(nueva_cantidad);
    }
    else if (nombre_material == MADERA){
        modificar_cantidad_madera(nueva_cantidad);
    }
    else{
        modificar_cantidad_metal(nueva_cantidad);
    }
}

void Edificio::modificar_cantidad_piedra(int nueva_cantidad){
    this -> cantidad_piedra = nueva_cantidad;
}

void Edificio::modificar_cantidad_madera(int nueva_cantidad){
    this -> cantidad_madera = nueva_cantidad;
}

void Edificio::modificar_cantidad_metal(int nueva_cantidad){
    this -> cantidad_metal = nueva_cantidad;
}

int Edificio::devolver_vida(){
   return vida;
}

int Edificio::devolver_vida_max(){
    return vida_max;
}

void Edificio::reparar(){
    vida += 1;
}