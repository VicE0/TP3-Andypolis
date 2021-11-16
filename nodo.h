#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo {
private:
    T dato;
    Nodo * siguiente;

public:
    Nodo<T>(T d);

    T obtener_dato();

    Nodo<T> * obtener_siguiente();

    void cambiar_siguiente(Nodo<T> * pn);

    void cambiar_dato(T d);

};  

template <class T>
Nodo<T>::Nodo(T d){

    this->dato = d;
    this->siguiente = nullptr;

}

template <class T>
T Nodo<T>::obtener_dato(){
    return dato;
}

template <class T>
Nodo<T> * Nodo<T>::obtener_siguiente(){
    return siguiente;
}

template <class T>
void Nodo<T>::cambiar_siguiente(Nodo * pn){
    siguiente = pn;
}

template <class T>
void Nodo<T>::cambiar_dato(T d){
    dato = d;
}

#endif