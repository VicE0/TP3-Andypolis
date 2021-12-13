#ifndef LISTA_SP_H
#define LISTA_SP_H

#include "nodoSP.h"
#include <iostream>

template <typename Data>

class ListaSP //Lista sin puntero para ingresar dato
{

private:
    // ATRBUTOS

    NodoSP<Data>* primero;
    NodoSP<Data>* ultimo;
    NodoSP<Data>* actual;
    NodoSP<Data>* anterior;

    int cantidad_elementos;

    NodoSP<Data>* obtener_nodo(int posicion);

public:
    // CONSTRUCTOR
    // PRE: -
    // POST: crea una Lista vacia
    ListaSP();

    // PRE: -
    // POST: inserta un nuevo elemento en la Listaa
    void insertar_elemento(Data o);

    // PRE: -
    // POST: elimina el elemento de la posicion pos de la Listaa
    void eliminar_elemento(int posicion);

    // PRE: -
    // POST: devuelve true si la Lista está vacia
    bool esta_vacia();

    // PRE: -
    // POST: devuelve el elemento que se encuentra en la posicion pos
    Data obtener_datos(int posicion);

    // PRE: -
    // POST: devuelve la cantidad de elementos de la Listaa
    int obtener_cantidad_elementos();

    // PRE: -
    // POST: devuelve true si el puntero actual no es null
    bool tiene_siguiente();

    // PRE: -
    // POST: devuelve true si el puntero anterior no es null
    bool tiene_anterior();

    // PRE: -
    // POST: apunta el puntero actual al primer elemento de la Listaa
    void resetear();

    // PRE: -
    // POST: devuelve el nodo actual y avanza
    NodoSP<Data>* obtener_siguiente();

    // PRE: -
    // POST: devuelve el nodo anterior
    NodoSP<Data>* obtener_anterior();

    // PRE: -
    // POST: devuelve el nodo actual
    NodoSP<Data>* obtener_actual();

    // PRE: -
    // POST: avanza
    void avanzar();


    // DESTRUCTOR
    ~ListaSP();

};

template <typename Data>
ListaSP<Data>::ListaSP() 
{
    primero = nullptr;
    actual = nullptr;
    cantidad_elementos = 0;
    ultimo = nullptr;
    anterior = nullptr;
}

template <typename Data>
void ListaSP<Data>::insertar_elemento(Data o)
{

    NodoSP<Data>* nuevo = new NodoSP<Data>(o);

    if(primero == nullptr)
    {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
        actual = primero;
        ultimo = actual;
    }

    else
    {
        NodoSP<Data>* anterior = ultimo;
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
        nuevo->cambiar_anterior(ultimo);
        ultimo = nuevo;
    }

    cantidad_elementos++;
}

template <typename Data>
bool ListaSP<Data>::esta_vacia() 
{
    return (cantidad_elementos == 0);
}

template <typename Data>
Data ListaSP<Data>::obtener_datos(int posicion) 
{
    NodoSP<Data> * aux = obtener_nodo(posicion);
    return aux->obtener_data();
}

template <typename Data>
int ListaSP<Data>::obtener_cantidad_elementos() 
{
    return cantidad_elementos;
}

template <typename Data>
bool ListaSP<Data>::tiene_siguiente() 
{
    return actual != nullptr;

}

template <typename Data>
bool ListaSP<Data>::tiene_anterior() 
{
    return anterior != nullptr;

}

template <typename Data>
void ListaSP<Data>::resetear() 
{
    actual = primero;
    anterior = nullptr;
}

template <typename Data>
NodoSP<Data>* ListaSP<Data>::obtener_siguiente() 
{
    anterior = actual;
    NodoSP<Data>* aux = actual;
    actual = actual->obtener_siguiente();

    return aux;
}

template <typename Data>
NodoSP<Data>* ListaSP<Data>::obtener_actual() 
{
    return actual;
}

template <typename Data>
void ListaSP<Data>::avanzar() 
{
    anterior = actual;
    actual = actual->obtener_siguiente();
}

template <typename Data>
NodoSP<Data>* ListaSP<Data>::obtener_anterior()
{
    return anterior->obtener_anterior();
}

template <typename Data>
ListaSP<Data>::~ListaSP(){}

template <typename Data>
NodoSP<Data>* ListaSP<Data>::obtener_nodo(int obtener_anterior)
{
    NodoSP<Data>* aux = primero;
    for(int i = 1; i < obtener_anterior; i++)
    {
        aux = aux->obtener_siguiente();
    }
        
    return aux;
}

#endif //LISTA_SP_H