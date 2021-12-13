#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include "nodo.h"

using namespace std;

const int NO_ENCONTRADO = -1;
template <typename T>
class Lista {

private:

    int cantidad;
    Nodo<T> * primero;
    T** datos;
    int capacidad;


public:
    Lista();

    Nodo<T> * obtener_nodo(int pos); 

    int obtener_pos(string nombre);

    int obtener_cantidad();

    void cambiar_cantidad(int nueva_cantidad);

    T * consulta(int pos); 
    
    void insertar(T *d); //lo inserta en la ultima posicion

    void alta(T * d, int pos);

    void baja(int pos); 

    bool vacia();

    void mostrar();

    string obtener_nombre(int posicion);

    ~Lista();


};

template <typename T>
Lista<T>::Lista(){

    // Primero seria el primer nodo de la lista
    primero = 0;
    cantidad = 0;

}

template <typename T>
Nodo<T> * Lista<T>::obtener_nodo(int pos){
    Nodo<T> * aux = primero;
    for ( int i = 0 ; i < pos ; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
}

template <typename T>
int Lista<T>::obtener_pos(string nombre){
    bool elemento_encontrado = false;
    int i = 0;
    Nodo<T>* auxiliar = primero;

    while(!elemento_encontrado && i < cantidad){
        if((*auxiliar -> obtener_dato())-> obtener_id_casillero() == nombre){
            elemento_encontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elemento_encontrado){
        return NO_ENCONTRADO;
    }
    return i - 1;
}

template <typename T>
int Lista<T>::obtener_cantidad(){
    return cantidad;
}

template <typename T>
void Lista<T>::cambiar_cantidad(int nueva_cantidad){
    cantidad = nueva_cantidad;
}

template <typename T>
void Lista<T>::alta(T * d, int pos){   

    Nodo<T> * nuevo = new Nodo<T>(d);
    Nodo<T> * siguiente = primero;

    // Depende donde quiera insertar el nuevo nodo :

    // si lo quiero insertar en la pos = 1 :
    if ( pos == 0){
        primero = nuevo;
    } 

    // si lo quiero insertar en cualquier otra posicion : 
    else {
        Nodo<T> * anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);

    }

    // En todos los casos posibles el nuevo nodo va a apuntar al siguiente
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
}

template <typename T>
T * Lista<T>::consulta(int pos){
    Nodo<T> * aux = obtener_nodo(pos);
    T * d = aux->obtener_dato();
    return d;
}

template <typename T>
void Lista<T>::insertar(T *d)
{
    datos[cantidad] = d;
    cantidad++;
}

template <typename T>
void Lista<T>::baja(int pos){
    Nodo<T> * baja = primero;

    // En caso de dar de baja el primer nodo , paso al siguiente
    if ( pos == 0){
        primero = baja->obtener_siguiente();
    }

    else {

        Nodo<T>* anterior = obtener_nodo(pos - 1);
        baja = anterior->obtener_siguiente();

        anterior->cambiar_siguiente(baja->obtener_siguiente());

    }

    cantidad--;
    delete baja;
}

template <typename T>
bool Lista<T>::vacia(){
    return (cantidad == 0);
}

template <typename T>
void Lista<T>::mostrar(){
    Nodo<T> * aux = primero;
    for ( int i = 0; i < cantidad; i++){
        cout << aux->obtener_dato() << endl;
        aux = aux->obtener_siguiente();
    }
}

template<typename Tipo>
string Lista<Tipo>::obtener_nombre(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidad){
        return "";
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return (*auxiliar -> obtener_dato()) -> obtener_id_casillero();
}

template <typename T>
Lista<T>::~Lista(){
    Nodo<T> * siguiente;
    while ( primero != nullptr ){
        siguiente = primero->obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}


#endif