#ifndef MUELLE_H
#define MUELLE_H

#include "casillero.h"


class Muelle : public Casillero {
public:

    //Constructor de Muelle
    //PRE: Recibe un entero con la fila y otro con la columna
    //POST: Construye un Muelle con nombre = "M".
    Muelle(int fila, int columna);

    //PRE: -
    //POS: muestra por pantalla un mensaje diciendo que que el casillero es un Muelle.
    void mostrar_casillero();

    //PRE:
    //POST: Devuelve un string con el nombre del casillero, en este caso "M" pues es un Muelle
    string obtener_nombre();

    //PRE: Le pido el codigo paras aber que jugador es.
    //POST: Devuelve un int con el costo de energia para transitar por este casillero.
    int obtener_costo_energia(int codigo_jugador);
    
    //PRE: Recibiendo como parametros los necesarios para el constructor de edificio
    //POS: Al ser un muelle, muestra por pantalla un mensaje diciendo
    //que no se pueden construir edificios aqui
    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    //PRE: Recibe un string con el nombre del material y otro con la cantidad
    //que se desea gnerar del mismo
    //POS: En muelle hace apuntar el puntero material
    //a un objeto material
    void agregar_material(string nombre, int cantidad);

    //PRE: Debe haber un  material colocado en el casillero
    //POS: Getter Devuelve un string vacio porque no se pueden construir edificios en los muelles
    string obtener_nombre_edificio();

    //PRE: - 
    //POS: Getter Devuelve un string con el nombre del material ubicado en el casillero.
    string obtener_nombre_material();

    //PRE:
    //POST: Al ser un muelle no devueve un string vacio pus
    //no se pueden ubicar edificios en el.
    string obtener_diminutivo_edificio();

    //PRE: -
    //POST: Si existe un material ubicado en el casillero, devuelve un string con el diminutivo
    //del mismo
    string obtener_diminutivo_material();

    //PRE:
    //POST: Muestra un mensaje diciendo que no existe ningun edificio en
    //el casillero puesto que es un muelle
    void eliminar_edificio();

    //PRE: -
    //POST: Devuelve false puesto que no se pueden construir edificios en muelles
    bool existe_edificio();

    //PRE: -
    //POST: Devulve treu si existe un material en el casillero y false en caso contrario
    bool existe_material();

    //PRE: -
    //POST: Muestra por pantalla un mensaje diciendo que no existe edificio construido en
    //el casillero
    void mostrar_coordenadas_edificio(string nombre);

    //Obtener fila
    //PRE:-
    //POST: Devuelve un entero con la fila del casillero
    int obtener_fila();

    //Obtener columna
    //PRE:-
    //POST: Devuelve un entero con la columna del casillero
    int obtener_columna();

    //Destructor de Muelle
    ~Muelle();
};


#endif