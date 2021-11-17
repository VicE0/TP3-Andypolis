#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>

using namespace std;

class Casillero
{
protected:
    int fila;
    int columna;
    string nombre;

public:
    // Constructor
    // PRE: - 
    // POS: Inicializo los valores en con los valores de fila y columna correspondientes,
    //      y nombre vacio.
    Casillero(int fila, int columna);
    
    // Constructor
    // PRE: - 
    // POS: Inicializo los valores en 0 fila y columna, y "A" al nombre.
    Casillero();

    // PRE: - 
    // POS: Implementada en los casilleros_construibles, creara un nuevo edificio en el casillero.
    virtual void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo) = 0;

    // PRE: -
    // POS: En casillero transitable, en caso de estar vacio, coloca un objeto material. 
    //En los casilleros inaccesibles y construibles no hace nada.
    virtual void agregar_material(string nombre, int cantidad) = 0;

    // PRE: -
    // POST: Muestra informacion sobre el casillero.
    virtual void mostrar_casillero() = 0;

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
    
    // PRE: -
    // POS: En el casillero_construible, podremos visualizar por pantalla las coordenadas del casillero donde
    //      se encuentra el edificio, en caso que este exista.
    virtual void mostrar_coordenadas_edificio(string nombre) = 0;

    // Destructor
    // PRE: -
    // POS: - 
    virtual ~Casillero();
    
    //Obtener fila
    //PRE:-
    //POST: Devuelve un entero con la fila del casillero
    virtual int obtener_fila() = 0;

    //Obtener columna
    //PRE:-
    //POST: Devuelve un entero con la columna del casillero
    virtual int obtener_columna() = 0;

};


#endif // CASILLERO_H