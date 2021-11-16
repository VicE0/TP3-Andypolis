#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "casillero.h"
#include "../material.h"


class Casillero_transitable : public Casillero {
private:
    Material * material;
public:

    //Constructor de casillero transitable
    //PRE: Recibe un entero con la fila y otro con la columna
    //POST: Construye un casillero transitable con nombre = "c" e inicializa el puntero material en null.
    Casillero_transitable(int fila, int columna);

    //PRE: Dos casos posibles , si existe o no un materiaal ubicado en e 
    //POS: Si existe : se muestra el mensaje que el casillero no esta vacio y manda el mensaje del material,
    //     si no existe: muestra el mensaje del tipo de casillero y que se encuentra vacio.
    void mostrar_casillero();
    
    //PRE: Recibiendo como parametros los necesarios para el constructor de edificio
    //POS: Al ser un casillero transitable, muestra por pantalla un mensaje diciendo
    //que no se pueden construir edificios aqui
    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    //PRE: Recibe un string con el nombre del material y otro con la cantidad
    //que se desea gnerar del mismo
    //POS: En casilleros transitables hace apuntar el puntero material
    //a un objeto material
    void agregar_material(string nombre, int cantidad);

    //PRE: Debe haber un  material colocado en el casillero
    //POS: Getter Devuelve un string vacio poruqe no se pueden construir edificios en los
    //casilleros transitables.
    string obtener_nombre_edificio();

    //PRE: - 
    //POS: Getter Devuelve un string con el nombre del material ubicado en el casillero.
    string obtener_nombre_material();

    //PRE:
    //POST: Al ser un casillero transitable no devueve un string vacio pus
    //no se pueden ubicar edificios en el.
    string obtener_diminutivo_edificio();

    //PRE: -
    //POST: Si existe un material ubicado en el casilero, devuelve un string con el diminutivo
    //del mismo
    string obtener_diminutivo_material();

    //PRE:
    //POST: Muestra un mensaje diciendo que no existe ningun edificio en
    //el casillero puesto que es transitable
    void eliminar_edificio();

    //PRE: -
    //POST: Devuelve false puesto que no se pueden construir edificios en casilleros
    //transitables
    bool existe_edificio();

    //PRE: -
    //POST: Devulve treu si existe un material en el casillero y false en caso contrario
    bool existe_material();

    //PRE:
    //POST: Devuelve un string con el nombre del casillero, en este caso "C" pues es un camino
    string obtener_nombre();

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

    //Destructor de casillero transitable
    ~Casillero_transitable();
};


#endif