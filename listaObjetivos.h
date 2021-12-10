#ifndef LISTA_OBJETIVOS_H
#define LISTA_OBJETIVOS_H

#include "nodoObjetivos.h"
#include <iostream>

template <typename Data>

class ListaObjetivos
{

private:
    // ATRBUTOS

    NodoObjetivos<Data>* primero;
    NodoObjetivos<Data>* ultimo;
    NodoObjetivos<Data>* actual;
    NodoObjetivos<Data>* anterior;

    int cantidad_elementos;

    NodoObjetivos<Data>* obtener_nodo(int posicion);

public:
    // CONSTRUCTOR
    // PRE: -
    // POST: crea una Lista vacia
    ListaObjetivos();

    // PRE: -
    // POST: inserta un nuevo elemento en la lista
    void insertar_elemento(Data o);

    // PRE: -
    // POST: elimina el elemento de la posicion posicion dada de la Listaa
    void eliminar_elemento(int posicion);

    // PRE: -
    // POST: devuelve true si la lista está vacia
    bool esta_vacia();

    // PRE: -
    // POST: devuelve el elemento que se encuentra en la posicion pedida
    Data obtener_datos(int posicion);

    // PRE: -
    // POST: devuelve la cantidad de elementos de la lista
    int obtener_cantidad_elementos();

    // PRE: -
    // POST: devuelve true si el puntero actual no es null
    bool tiene_siguiente();

    // PRE: -
    // POST: devuelve true si el puntero anterior no es null
    bool tiene_anterior();

 

    // PRE: -
    // POST: devuelve el nodo actual y avanza
    NodoObjetivos<Data>* obtener_siguiente();

    // PRE: -
    // POST: devuelve el nodo anterior
    NodoObjetivos<Data>* obtener_anterior();

    // PRE: -
    // POST: devuelve el nodo actual
    NodoObjetivos<Data>* obtener_actual();



    // DESTRUCTOR
    ~ListaObjetivos();

};

template <typename Data>
ListaObjetivos<Data>::ListaObjetivos() 
{
    primero = nullptr;
    actual = nullptr;
    cantidad_elementos = 0;
    ultimo = nullptr;
    anterior = nullptr;
}

template <typename Data>
void ListaObjetivos<Data>::insertar_elemento(Data o)
{

    NodoObjetivos<Data>* nuevo = new NodoObjetivos<Data>(o);

    if(primero == nullptr)
    {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
        actual = primero;
        ultimo = actual;
    }

    else
    {
        NodoObjetivos<Data>* anterior = ultimo;
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
        nuevo->cambiar_anterior(ultimo);
        ultimo = nuevo;
    }

    cantidad_elementos++;
}


template <typename Data>
bool ListaObjetivos<Data>::esta_vacia() 
{
    return (cantidad_elementos == 0);
}

template <typename Data>
Data ListaObjetivos<Data>::obtener_datos(int posicion) 
{
    NodoObjetivos<Data> * aux = obtener_nodo(posicion);
    return aux->obtener_data();
}

template <typename Data>
int ListaObjetivos<Data>::obtener_cantidad_elementos() 
{
    return cantidad_elementos;
}

template <typename Data>
bool ListaObjetivos<Data>::tiene_siguiente() 
{
    return actual != nullptr;

}

template <typename Data>
bool ListaObjetivos<Data>::tiene_anterior() 
{
    return anterior != nullptr;

}

template <typename Data>
NodoObjetivos<Data>* ListaObjetivos<Data>::obtener_siguiente() 
{
    anterior = actual;
    NodoObjetivos<Data>* aux = actual;
    actual = actual->obtener_siguiente();

    return aux;
}

template <typename Data>
NodoObjetivos<Data>* ListaObjetivos<Data>::obtener_actual() 
{
    return actual;
}

template <typename Data>
NodoObjetivos<Data>* ListaObjetivos<Data>::obtener_anterior()
{
    return anterior->obtener_anterior();
}

template <typename Data>
ListaObjetivos<Data>::~ListaObjetivos(){}

template <typename Data>
NodoObjetivos<Data>* ListaObjetivos<Data>::obtener_nodo(int obtener_anterior)
{
    NodoObjetivos<Data>* aux = primero;
    for(int i = 1; i < obtener_anterior; i++)
    {
        aux = aux->obtener_siguiente();
    }
        
    return aux;
}

#endif //LISTA_OBJETIVOS_H