#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>

using namespace std;

const string BOMBA = "bombas";
const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";
const string ENERGIA = "energia";
const string COINS = "andycoins";
const string MINA = "mina";
const string ASERRADERO = "aserradero";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string OBELISCO = "obelisco";
const string PLANTA_ELECTRICA = "planta electrica";
const string MINA_ORO = "mina oro";


class Edificio
{
protected:

    int id_jugador;
    string nombre;
    string diminutivo;
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int brinda;
    int maximo_construir;
    int construidos_j1;
    int construidos_j2;
    int vida;
    int vida_max;

    void modificar_cantidad_piedra(int nueva_cantidad);
    void modificar_cantidad_metal(int nueva_cantidad);
    void modificar_cantidad_madera(int nueva_cantidad);

public:

    // Constructor
    // PRE: -
    // POS: Inicializa el edificio con todos los valores en 0 
    Edificio();

    // PRE: -
    // POS: Como es una clase abstracta cada edificio va a implementar su nombre, aca se
    //      establecen las cantidades requeridas a partir del archivo edificios.txt.
    Edificio(int id_jugador, int vida, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir);

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve el nombre del edificio ( getter )
    string obtener_nombre();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve el diminutivo del edificio, siendo este la primer letra de la palabra ( getter ).
    string obtener_diminutivo();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la cantidad de piedra necesaria para construir.
    int obtener_cantidad_piedra();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la cantidad de madera necesaria para construir.
    int obtener_cantidad_madera();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la cantidad de metal necesaria para construir.
    int obtener_cantidad_metal();

    //PRE> -
    //POST: Devuelve la cantidad de edificios construidos de un determinado jugador.
    int obtener_cantidad_construidos();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la cantidad que se encuentran construidos en el mapa hasta el momento.
    int obtener_cantidad_construidos(int id_jugador);

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la maxima cantidad de edificios que se pueden construir , informacion que viene dada
    //      en edificio.txt.
    int obtener_maximo_construir();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la mitad del material, metodo utilizado en caso de eliminar el edificio.
    int obtener_mitad_piedra();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la mitad del material, metodo utilizado en caso de eliminar el edificio.
    int obtener_mitad_madera();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la mitad del material, metodo utilizado en caso de eliminar el edificio.
    int obtener_mitad_metal();

    // PRE: Que la cantidad maxima de edificios no sea menor que la cantidad de edificios construidos.
    // POS: Devuelve una resta entre el maximo y la cantidad de edificios construidos, para saber cuantos 
    //      mas puedo construir.
    int obtener_cuantos_puedo_construir(int id_jugador);

    // PRE: En caso de que se pueda construir edificio sin superar el maximo.
    // POS: suma 1 a la cantidad de edificios.
    void sumar_cantidad(int id_jugador);

    // PRE: En caso de que exista por lo menos 1 edificio creado.
    // POS: Resta 1 a cantidad_edificios.
    void restar_cantidad(int id_jugador);

    // PRE: -
    // POS: Por cada uno de los edificios muestra por pantalla su respectivo mensaje.
    virtual void mostrar_mensaje() = 0;

    // PRE: Dependiendo al edificios que me diriga.
    // POS: Devuelve una cierta cantidad de material que brinda el edificio en particular.
    virtual int obtener_cantidad_brindada() = 0;

    //PRE: -
    //POST: Si lo hay, devuelve el id perteneciente al dueño del edificio.
    int devolver_id_jugador();

    // Destructor
    // PRE: -
    // POS: -
    virtual ~Edificio();

    // PRE: Recibe el nombre del material a modificar y la nueva cantidad para modificar.
    // POS: Cambia el valor almacenado del material otorgado por la nueva cantidad brindada.
    void modificar_cantidad_material(string nombre_material, int nueva_cantidad);

    // PRE: -
    // POS: Retorna la vida de un jugador.
    int devolver_vida();

    // PRE: -
    // POS: Retorna la vida maxima como entero.
    int devolver_vida_max();

    void reparar();

    void atacar();

    int obtener_restantes_j1();

    int obtener_restantes_j2();
};




#endif // EDIFICIO_H