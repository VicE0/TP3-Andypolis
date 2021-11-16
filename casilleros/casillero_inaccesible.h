#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "casillero.h"

class Casillero_inaccesible : public Casillero {


public:

    //Constructor de casillero inaccesible
    //PRE: Recibe un entero con la fila y otro con la columna
    //POST: Construye un casillero inaccesible con nombre = "L".
    Casillero_inaccesible(int fila, int columna);

    //PRE: -
    //POS: muestra por pantalla un mensaje diciendo que que el casillero es inaccesible
    void mostrar_casillero();

    //PRE: Recibiendo como parametros los necesarios para el constructor de edificio
    //POS: Al ser un casillero inaccesible, muestra por pantalla un mensaje diciendo
    //que no se pueden construir edificios aqui
    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    //PRE: Recibe un string con el nombre del material y otro con la cantidad
    //que se desea gnerar del mismo
    //POS:Al ser un casillero inaccesible, no hace nada pues no se pueden 
    //agregar materiales en ellos
    void agregar_material(string nombre, int cantidad);

    //PRE: - 
    //POS: Getter Devuelve un string vacio poruqe no se pueden construir edificios en los
    //casilleros inaccesibles.
    string obtener_nombre_edificio();
    
    //PRE: - 
    //POS: Devuelve un string vacio pues no se pueden ubicar materiales en 
    //casilleros construibles
    string obtener_nombre_material();

    //PRE:
    //POST: Al ser un casillero inaccesible devueve un string vacio pues 
    //no se pueden ubicar edificios en el
    string obtener_diminutivo_edificio();

    
    //PRE: -
    //POST: Al ser un casillero inaccesible devuelve un string vacio
    //del mismo
    string obtener_diminutivo_material();

    //PRE:
    //POST: Muestra un mensaje diciendo que no existe ningun edificio en
    //el casillero puesto que es inaccesible
    void eliminar_edificio();

    //PRE: -
    //POST: Devuelve un string con el nombre del casillero, en este caso "C" pues es un camino
    string obtener_nombre();

    //PRE:
    //POST: Muestra por pantalla un mensaje diciendo que no existe edificio construido en
    //el casillero
    void mostrar_coordenadas_edificio(string nombre);
    
    //PRE: -
    //POST: Devuelve false puesto que no se pueden construir edificios en casilleros
    //inaccesiibles
    bool existe_edificio();

    //PRE: -
    //POS:  Devuelve false puesto que no se pueden colocar materiales en casilleros inaccesibles
    bool existe_material();

    //Obtener fila
    //PRE:-
    //POST: Devuelve un entero con la fila del casillero
    int obtener_fila();

    //Obtener columna
    //PRE:-
    //POST: Devuelve un entero con la columna del casillero
    int obtener_columna();

};


#endif