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
    Nodo_ABB * insertar_nodo(Nodo_ABB * nodo, Edificio* edificio);

    Nodo_ABB * encontrar_nodo(Nodo_ABB * nodo, string clave);

    void modificar_material(Edificio * edificio, string nombre_material);

    
public:
    Arbol();

    // crear nodo con el dato edificio para luego insertarlo en el arbol
    void insertar(Edificio* edificio);

    void mostrar_arbol(Nodo_ABB * arbol);

    void mostrar();

    Nodo_ABB * encontrar(string clave);

    void modificar_datos_edificio(string clave);

    bool existe_edificio(string clave);

    bool supera_maximo(string clave, int id_jugador);

};

#endif //