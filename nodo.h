#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
private:
    T * dato;
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

#endif