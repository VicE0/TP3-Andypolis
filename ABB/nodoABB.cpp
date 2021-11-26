#include "nodoABB.h"

Nodo_ABB::Nodo_ABB(Edificio * d){
    this -> edificio = d;
    this -> clave = d -> obtener_nombre();
    this -> derecho = NULL;
    this -> izquierdo = NULL; 
}   

Edificio* Nodo_ABB::obtener_edificio(){
    return this -> edificio;
}

string Nodo_ABB::obtener_clave(){
    return this -> clave;
}

Nodo_ABB * Nodo_ABB::obtener_der(){
    return this -> derecho;
}

Nodo_ABB * Nodo_ABB::obtener_izq(){
    return this -> izquierdo;
}

void Nodo_ABB::cambiar_dato(Edificio * d){
    edificio = d;
}

void Nodo_ABB::cambiar_izq(Nodo_ABB * pi){
    izquierdo = pi;
}

void Nodo_ABB::cambiar_der(Nodo_ABB * pd){
    derecho = pd;
}
