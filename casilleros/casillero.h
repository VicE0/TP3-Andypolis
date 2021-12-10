#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "../edificio.h"
#include "../jugador.h"

using namespace std;

const int JUGADOR_1 = 1;
const int JUGADOR_2 = 2;

class Casillero
{
protected:
    string id_casillero; // "ij"
    int fila;
    int columna;
    string nombre;
    Jugador * jugador;
    int peso;

public:
    // Constructor
    // PRE: - 
    // POS: Inicializo los valores en con los valores de fila y columna correspondientes,
    //      y nombre vacio.
    Casillero(int fila, int columna, string id_casillero);
    
    // Constructor
    // PRE: - 
    // POS: Inicializo los valores en 0 fila y columna, y "A" al nombre.
    Casillero();

    // PRE: - 
    // POS: Implementada en los casilleros_construibles, creara un nuevo edificio en el casillero.
    virtual void agregar_edificio(string nombre, int id_jugador,int vida,int piedra, int madera, int metal, int maximo) = 0;

    // PRE: -
    // POS: En casillero transitable, en caso de estar vacio, coloca un objeto material. 
    //En los casilleros inaccesibles y construibles no hace nada.
    virtual void agregar_material(string nombre, int cantidad) = 0;

    // PRE: -
    // POST: Muestra informacion sobre el casillero.
    virtual void mostrar_casillero() = 0;

    //PRE: -
    //POST: Devuelve la cantidad de energia necesaria para transitar un determinado casillero.
    virtual int obtener_costo_energia(int id_jugador) = 0;

    // PRE: -
    // POS: Se obtiene el nombre del casillero solicitado siendo estos = T,C,L.
    virtual string obtener_nombre() = 0;

    // PRE: -
    // POS: En el casillero_construible, podremos obtener el nombre del
    //      edificio consultado en caso que exista.
    virtual string obtener_nombre_edificio() = 0;

    // PRE: -
    // POS: En el casillero_transitable, podremos obtener el nombre del
    //      material ubicado en el, en caso que exista. En construible e inaccesible devuelve un string vacio.
    virtual string obtener_nombre_material() = 0;

    // PRE: -
    // POS: En el casillero_construible, nos devolvera en caso de existir edificio, su 
    //      su diminutivo, diminutivo = 'La primer palabra del nombre del edificio'.
    virtual string obtener_diminutivo_edificio() = 0;

    // PRE: -
    // POS: En el casillero_transitable, nos devolvera en caso de existir material, su 
    //su diminutivo, diminutivo = 'La primer palabra del nombre del material'.
    virtual string obtener_diminutivo_material() = 0;

    // PRE: -
    // POS: En el casillero_construible, en caso de existir edificio , lo elimina.
    virtual void eliminar_edificio() = 0;

    // PRE: -
    // POS: En el casillero_construible, obtendremos verdadero o falso , si existe retorna verdadero.
    virtual bool existe_edificio() = 0;

    // PRE: -
    // POS: En el casillero_transitable, obtendremos verdadero si hay un material y falso en caso contrario. En casilleros transitables
    //y inaccesibles devolvera false siempre puesto que no se pueden ubicar materiales en ellos.
    virtual bool existe_material() = 0;

    //PRE: -
    //POST: En el casillero_transitable, obtendremos verdadero si hay un jugador y falso en caso contrario. En casilleros construibles
    //e inaccesibles devolvera false siempre puesto que no se pueden ubicar jugadores en ellos.
    bool existe_jugador();

    //PRE: -
    //POST: Si lo hay, devuelve el id perteneciente al jugador dueño de lo que haya en dicho casillero.
    int devolver_id_jugador();
    
    // PRE: -
    // POS: En el casillero_construible, podremos visualizar por pantalla las coordenadas del casillero donde
    //      se encuentra el edificio, en caso que este exista.
    virtual void mostrar_coordenadas_edificio(string nombre) = 0;

    // Destructor
    // PRE: -
    // POS: - 
    virtual ~Casillero(){};
    
    //Obtener fila
    //PRE:-
    //POST: Devuelve un entero con la fila del casillero
    virtual int obtener_fila() = 0;

    //Obtener columna
    //PRE:-
    //POST: Devuelve un entero con la columna del casillero
    virtual int obtener_columna() = 0;

    virtual Edificio * obtener_edificio_construido() = 0;

    virtual void comprobar_destruccion_edificio() = 0;

    void agregar_jugador(Jugador * jugador);

    int obtener_peso();

    string obtener_diminutivo_jugador();

    string obtener_id_casillero();

};


#endif // CASILLERO_H