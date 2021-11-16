#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <iomanip>

//class Material;
#include "material.h"

using namespace std;

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

class Inventario { 
private:

	Material** lista_materiales;
    int cantidad_de_materiales;

public:

    //Constructor de inventario sin parametros
    //PRE: -
    //POST: Construye un inventario
    Inventario();

    //Destructor de inventario
    //PRE:-
    //POST: Liberar la memoria que se uso en la creacion del inventario y escribe el 
    //archivo materiales.txt con la info actulizada
    ~Inventario();

    //Cargar materiales
    //PRE: -
    //POST: Abre el archivo materiales.txt y carga la lista de materiales del iventario 
    //con los materiales del archivo. Si no lo logra abrir, carga -1 en cantidad_de_materiales
    void cargar_materiales();

    //Agregar material a la lista de materiales
    //PRE: Recibe un objeto de tipo "material"
    //POST: agrega el material a la lista de materiales
    void agregar_material(Material* material);

    //Obtener cantidad_de_materiales
    //PRE:-
    //POST: Devuelve un entero con la cantidad de materiales en lista_materiales.
    int obtener_cantidad_de_materiales();

    //PRE: Recibe el entero "posicion" con la posicion dentro del vector lista_materiales
    //POST: Devuelve un puntero al material que se encuentra dicha posicion
    Material* obtener_material_de_lista_materiales(int posicion);

    //Mostrar inventario
    //PRE: -
    //POST: Muestra por pantalla el inventario de materiales
    void mostrar_inventario();

    //Chequear si alcanzan materiales
    //PRE: Recibe tres enteros con las cantidades de piedra madera y metal necesarios para construir un 
    //edificio
    //POST: Devuelve el booleano alcanza por true si alcanzan los materiales y por false en caso contrario
    bool alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

    //chequar si alcanza material en cuestion
    // PRE: Recibe los enteros "cantidad_disponible" con la cantidad desponible de un material y  
    //"cantidad_material_necesaria" con la cantidad necesaria de ese mismo material para la construccion de
    //un edificio y la direecion de memoria del booleano "alcanza".
    //POST: Guarda true en "alcanza" si la cantidad de material disponible supera la cantidad necesaria de 
    //dicho material y false en caso contrario
    void chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza);

    //Utilizar materiales
    //PRE: Recibe el struct 3 eneteros con las cantidades de piedra, madera y metal necesarias
    //para la construccion de un edificio
    // POST: Modifica la cantidad disponible de piedra, madera y metal restandole las que 
    //son necesarias para necesarias para la construccion de un edificio a traves del metodo
    //restar_material() del objeto material
    void utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);


    //Devolver materiales
    //PRE: Recibe 3 enteros con las cantidades de piedra, madera y metal necesarias para la construccion
    //de un edificio.
    //POST: Modifica la cantidad disponible de piedra, madera y metal sumandole la mitad 
    //de las que son necesarias para necesarias para la construccion de un edificio.
    void devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);
    
    //Recolectar materiales
    //PRE: Recibe 3 enteros con las cantidades de piedra, madera y metal que han sido recolectados
    //POST: Modifica la cantidad disponible de piedra, madera y metal sumandole las cantidades
    //de dichos enteros
    void recolectar_materiales(int cantidad_piedra_rec, int cantidad_madera_rec, int cantidad_metal_rec);


    //Obtener posicion material
    //PRE: Recibe el string "material_a_buscar" con el nombre del material a buscar
    //POST: Devuelve el entero "posicion" con la posicion del edificio
    int obtener_posicion_material(string material_a_buscar);

};

#endif // INVENTARIO_H
