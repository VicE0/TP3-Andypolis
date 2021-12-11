#ifndef BETUN_H
#define BETUN_H

#include "casillero.h"
#include "../material.h"



class Betun : public Casillero {
private:
    Material * material;
public:

    //Constructor de Betun
    //PRE: Recibe un entero con la fila y otro con la columna
    //POST: Construye un Betun con nombre = "B".
    Betun(int fila, int columna, string id_casillero);

    //PRE: -
    //POS: muestra por pantalla un mensaje diciendo que que el casillero es un Betun.
    void mostrar_casillero();

    //PRE:
    //POST: Devuelve un string con el nombre del casillero, en este caso "C" pues es un Betun
    string obtener_nombre();

    //PRE: Le pide el numero del jugador (indiferente ya q ambos gastan lo mismo).
    //POST: Devuelve un int con el costo de energia para transitar por este casillero.
    int obtener_costo_energia(int id_jugador);

    //PRE: Recibiendo como parametros los necesarios para el constructor de edificio
    //POS: Al ser un casillero transitable, muestra por pantalla un mensaje diciendo
    //que no se pueden construir edificios aqui
    void agregar_edificio(string nombre, int id_jugador,int vida,int piedra, int madera, int metal, int maximo);

    //PRE: Recibe un string con el nombre del material y otro con la cantidad
    //que se desea gnerar del mismo
    //POS: En casilleros transitables hace apuntar el puntero material
    //a un objeto material
    void agregar_material(string nombre, int cantidad);

    //PRE: Debe haber un  material colocado en el casillero
    //POS: Getter Devuelve un string vacio poruqe no se pueden construir edificios en los Betunes
    string obtener_nombre_edificio();

    //PRE: - 
    //POS: Getter Devuelve un string con el nombre del material ubicado en el casillero.
    string obtener_nombre_material();

    //PRE:
    //POST: Al ser un Betun nos devueve un string vacio pues no se pueden ubicar edificios en el.
    string obtener_diminutivo_edificio();

    //PRE: -
    //POST: Si existe un material ubicado en el casilero, devuelve un string con el diminutivo
    //del mismo
    string obtener_diminutivo_material();

    //PRE:
    //POST: Muestra un mensaje diciendo que no existe ningun edificio en
    //el casillero puesto que es un Betun
    void eliminar_edificio();

    //PRE: -
    //POST: Devuelve false puesto que no se pueden construir edificios en los Betunes
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

    Edificio * obtener_edificio_construido();

    // PRE: -
    // POS: Comprueba la destruccion del edificio e imprime un mensjae en base a eso.
    void comprobar_destruccion_edificio();

    //Destructor de Betun
    ~Betun();
    };
    
#endif