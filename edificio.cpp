#include "edificio.h"

Edificio::Edificio(){
    this->id_jugador = 1;
    this-> nombre = "nada";
    this-> diminutivo = "";
    this-> cantidad_piedra = 0;
    this-> cantidad_madera = 0;
    this-> cantidad_metal = 0;
    this-> brinda = 0;
    this-> maximo_construir = 0;
    this-> vida = 1;
    this-> vida_max = 1;
    this-> construidos_j1 = 0;
    this-> construidos_j2 = 0;
}

Edificio::Edificio(int id_jugador, int vida, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir){
    this-> id_jugador = id_jugador;
    this-> nombre = "";
    this-> diminutivo = "Ed";
    this-> cantidad_piedra = cantidad_piedra;
    this-> cantidad_madera = cantidad_madera;
    this-> cantidad_metal = cantidad_metal;
    this-> brinda = 0;
    this-> maximo_construir = maximo_construir;
    this-> vida = vida;
    this-> vida_max = vida;
    this-> construidos_j1 = 0;
    this-> construidos_j2 = 0;


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

int Edificio::obtener_cantidad_construidos(){
    return construidos_j2 + construidos_j1;
}

int Edificio::obtener_cantidad_construidos(int id_jugador){
    int cantidad = 0;
    if ( id_jugador == 1){
        cantidad = construidos_j1;
    } else {
        cantidad = construidos_j2;
    }
    return cantidad;
}

int Edificio::obtener_restantes_j1(){
    int restantes = maximo_construir - construidos_j1;
    return restantes;
}

int Edificio::obtener_restantes_j2(){
    int restantes = maximo_construir - construidos_j2;
    return restantes;
}

int Edificio::obtener_cuantos_puedo_construir(int id_jugador){
    int restantes = 0;
    if ( id_jugador == 1){
        restantes = maximo_construir - construidos_j1;
    } else {
        restantes = maximo_construir - construidos_j2;   
    }
    return restantes;
}

void Edificio::sumar_cantidad(int id_jugador){
    if ( id_jugador == 1 ){
        construidos_j1 += 1;
    } else {
        construidos_j2 += 1;
    }
}

void Edificio::restar_cantidad(int id_jugador){
    if ( id_jugador == 1 ){
        construidos_j1 += 1;
    } else {
        construidos_j2 += 1;
    }
}

int Edificio::devolver_id_jugador(){
    return id_jugador;
}

Edificio::~Edificio(){}

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

void Edificio::atacar(){
    vida -= 1;
}