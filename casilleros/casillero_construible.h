#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "../edificio.h"
#include "../edificios/aserradero.h"
#include "../edificios/escuela.h"
#include "../edificios/fabrica.h"
#include "../edificios/mina.h"
#include "../edificios/obelisco.h"
#include "../edificios/planta_electrica.h"
#include "casillero.h"


class Casillero_construible : public Casillero {

private:
    Edificio * edificio_construido;

public:

    // Constructor
    //PRE: -
    //POS: Le da nombre = 'T', y inicializa al puntero edificio_construido en NULL
    Casillero_construible(int fila, int columna);

    //PRE: Recibiendo como parametros los necesarios para el constructor de edificio
    //POS: El puntero edificio_construido apuntara al nuevo espacio en memoria donde se guarda el edificio.
    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    //PRE:-
    //POS: En casilleros transitables hace apuntar el puntero material
    //a un objeto material
    void agregar_material(string nombre, int cantidad);

    //PRE: - 
    //POS: Getter , que me devuelve el nombre del edificio que hay en el casillero.
    string obtener_nombre_edificio();

    //PRE: - 
    //POS: Devuelve un string vacio pues no se pueden ubicar materiales en casilleros construibles
    string obtener_nombre_material();

    //PRE: En caso de existir un edificio, que el edificio_construido != NULL. 
    //POS: Voy a obtener el diminutivo del edificio que apunta edificio_construido.
    string obtener_diminutivo_edificio();

    //PRE: -  
    //PRE:
    //POST: Al ser un casillero construible devueve un string vacio pus
    string obtener_diminutivo_material();

    //PRE: En caso de existir un edificio , edificio_construido != NULL.
    //POS: Libero espacio en memoria y edificio_construido = 0.
    void eliminar_edificio();

    //PRE: Dos casos posibles , si existe o no edificio_construido 
    //POS: Si existe : se muestra el mensaje que el casillero no esta vacio y manda el mensaje del objeto,
    //     si no existe: muestra el mensaje del tipo de casillero y que se encuentra vacio.
    void mostrar_casillero();

    //PRE: -
    //POS: Devuelve el nombre del casillero ( getter ).
    string obtener_nombre();

    //PRE: En caso edificio_construido != NULL.  
    //POS: Muestra por pantalla las coordenadas del edificio y el nombre del edificio existente.
    void mostrar_coordenadas_edificio(string nombre);

    //PRE: -
    //POS: Chequeo el casillero si existe o no un edificio , devuelve true si edificio_construido != NULL.
    bool existe_edificio();

    //PRE: -
    //POS:  Devuelve false puesto que no se pueden colocar materiales en casilleros construibles
    bool existe_material();

    // Destructor
    //PRE: En caso de que el casillero contenga un edificio. 
    //POS: Libero la memoria y edificio_construido = 0.
    ~Casillero_construible();

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