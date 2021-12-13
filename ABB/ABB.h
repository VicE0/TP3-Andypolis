#ifndef ARBOL_H
#define ARBOL_H
#include <string>
#include <iostream>
#include "nodoABB.h"

using namespace std;

class Arbol
{
private:
    // Atributos : 
    Nodo_ABB * root;

    // insertar nodo dentro del arbol
    //PRE: -
    //POST: Inserta el nodo en el arbol dependiedno si hay o no raiz y de si es mayor o menor a la clave
    Nodo_ABB * insertar_nodo(Nodo_ABB * nodo, Edificio* edificio);

    //PRE: Le paso el arbol a buscar y la clave
    //POST: Busco un nodo en el arbol y lo devuelvo
    Nodo_ABB * encontrar_nodo(Nodo_ABB * nodo, string clave);

    //PRE: Necesito la lista de los edificios y el nombre del material a modificar
    //POST: Modifica el material necesario para construir dicho edificio
    void modificar_material(Edificio * edificio, string nombre_material);

    
public:

    //Constructor del arbol
    Arbol();

    // crear nodo con el dato edificio para luego insertarlo en el arbol
    //Pre: Le paso el puntero edificio
    //Post: Inserta el edificio dentro de un nodo el cual posteriormente sera agregado al arbol.
    void insertar(Edificio* edificio);

    //PRE: -
    //POST: Muestra por pantalla los edificos construidos, sus materiales necesarios y sus cantidades por jugador recorriendo todo el arbol
    void mostrar_arbol(Nodo_ABB * arbol);

    //PRE: -
    //POST: Ejecuta la funcion mostrar arbol en root
    void mostrar();

    //PRE: Paso la clave a buscar
    //POST: Devuelve el dato encontrado en el nodo
    Nodo_ABB * encontrar(string clave);

    //PRE: Necesito el nombre del edificio a modificar
    //POST: Modifica el material necesario para construir dicho edificio
    void modificar_datos_edificio(string clave);

    //PRE: Necesito el nombrre del edificio a buscar
    //POST: Devuelvo un bool en base a si existe o no el edificio
    bool existe_edificio(string clave);
    
    //PRE: Necesito el edificio a buscar y el id del jugador
    //POST: DEvuelvo un bool en base a si se supera la cantidad maxima de construidos o no
    bool supera_maximo(string clave, int id_jugador);

    void eliminar_arbol(Nodo_ABB * nodo);

    void eliminar_arbol();

    ~Arbol();

};

#endif //