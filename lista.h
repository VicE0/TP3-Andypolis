#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"

using namespace std;

template <typename T>
class Lista {

private:

    int cantidad;
    Nodo<T> * primero;
    T** datos;
    int capacidad;


public:
    //PRE: -
    //POST: Inicializa la lista
    Lista();

    //PRE: Le ingreso el entero de la posicion a buscar
    //POST: Obtengo el nodo buscado
    Nodo<T> * obtener_nodo(int pos); 

    //PRE: Le ingreso el string del nombre a buscar
    //POST: Devuelve la posicion del elemento buscado en caso de encontrarlo
    int obtener_pos(string nombre);

    //PRE: -
    //POST: Devuelve la cantidad almacenada en dicho nodo
    int obtener_cantidad();

    //PRE: -
    //POST: Cambia la cantidad de dicho nodo
    void cambiar_cantidad(int nueva_cantidad);

    //PRE: -
    //POST: Devuelve el puntero del dato del nodo pedido.
    T * consulta(int pos); 
    
    //PRE: Le pido un entero que va a ser la posicion
    //POST: Da de alta un nuevo nodo en la lista en la posicion pedida
    void alta(T * d, int pos); 

    //PRE: Le pido un entero que va a ser la posicion a eliminar
    //POST: Da de baja un nodo en la lista en la posicion pedida
    void baja(int pos); 

    //PRE: -
    //POST: Me devuelve un booleano al verificar si la canrtidad esta vacia o no
    bool vacia();

    //PRE: -
    //POST: Muestra por pantalla todos los datos almacenados en la lista
    void mostrar();

    //Destructor de lista
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
        return -1;
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

template <typename T>
Lista<T>::~Lista(){
    int pos = cantidad - 1;
    while( !vacia() ){
        baja(pos);
        pos--;
    }
}


#endif