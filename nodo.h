#ifndef NODO_H
#define NODO_H

#include <string>

using namespace std;

template <typename T>
class Nodo {
private:
    T * pdato;
    Nodo<T> * siguiente;

public:
    // CONSTRUCTOR
    Nodo<T>(T * d);

    // PRE: -
    // POST: devuelve el dato que contiene el nodo
    T * obtener_dato();

    // PRE: -
    // POST: devuelve el nodo siguiente
    Nodo<T> * obtener_siguiente();

    // PRE: Necesito darle un nodo 
    // POST: Cambio el nodo siguiente con el nuevo nodo pasado
    void cambiar_siguiente(Nodo<T> * pn);

    // PRE: Necesito apsarle un nodo 
    // POST: Cambia el dato en el nodo ingresado
    void cambiar_dato(T d);

    ~Nodo();

};  

template <typename T>
Nodo<T>::Nodo(T * pd){
    this->pdato = pd;
    this->siguiente = nullptr;
}

template <typename T>
T * Nodo<T>::obtener_dato(){
    return pdato;
}

template <typename T>
Nodo<T> * Nodo<T>::obtener_siguiente(){
    return siguiente;
}

template <typename T>
void Nodo<T>::cambiar_siguiente(Nodo * pn){
    siguiente = pn;
}

template <typename T>
void Nodo<T>::pcambiar_dato(T d){
    pdato = d;
}

template <typename T>
Nodo<T>::~Nodo(){
    delete pdato;
}

#endif