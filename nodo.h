#ifndef NODO_H
#define NODO_H

#include <string>

using namespace std;

template <typename T>
class Nodo {
private:
    T * dato;
    Nodo<T> * siguiente;

public:
    Nodo<T>(T * d);

    T * obtener_dato();

    Nodo<T> * obtener_siguiente();

    void cambiar_siguiente(Nodo<T> * pn);

    void cambiar_dato(T d);

    ~Nodo();

};  

template <typename T>
Nodo<T>::Nodo(T * d){

    this->dato = d;
    this->siguiente = nullptr;

}

template <typename T>
T * Nodo<T>::obtener_dato(){
    return dato;
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
void Nodo<T>::cambiar_dato(T d){
    dato = d;
}

template <typename T>
Nodo<T>::~Nodo(){
    delete dato;
}

#endif