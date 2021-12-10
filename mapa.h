#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include <string>
#include "grafo.h"
#include "casilleros/casillero.h"
#include "casilleros/terreno.h"
#include "casilleros/lago.h"
#include "casilleros/betun.h"
#include "casilleros/camino.h"
#include "casilleros/muelle.h"
#include "jugador.h"
#include "edificio.h"
#include "ABB/ABB.h"
#include "Objetivos.h"
#include "objetivos/comprar_andypolis.h"
#include "objetivos/edad_piedra.h"
#include "objetivos/bombardero.h"
#include "objetivos/energetico.h"
#include "objetivos/letrado.h"
#include "objetivos/minero.h"
#include "objetivos/cansado.h"
#include "objetivos/constructor.h"
#include "objetivos/armado.h"
#include "objetivos/extremista.h"
#include "objetivos/obelisco.h"


using std::string;
using namespace std;

const int ERROR = -1;
const string ARCHIVO_MAPA = "mapa.txt";
const string ARCHIVO_UBICACIONES = "ubicaciones.txt";
const string ARCHIVO_EDIFICIO = "edificios.txt";
const string ARCHIVO_MATERIALES = "materiales.txt";
const int UNIDADES_POR_PACK_PIEDRA = 100;
const int UNIDADES_POR_PACK_MADERA = 50;
const int UNIDADES_POR_PACK_METAL = 50;
const int UNIDADES_POR_PACK_COINS = 250;
const int COSTO_BOMBA = 100;


class Mapa
{
private:
    int cantidad_filas;
    int cantidad_columnas;
    Casillero *** mapa;

    Grafo * grafo;

    Objetivo * obj;;

    int cantidad_edificios;

    Arbol * diccionario;

    Casillero ** vector_casilleros_lluvia;
    int total_casilleros;

    bool ubicaciones_bien_cargadas;
    bool mapa_bien_cargado;
    bool partida_empezada;

public:

    // Constructor
    //PRE: - 
    //POS: Inicializa el mapa con todos sus valores y punteros en 0.
    Mapa();

    //PRE: Utilizando los arhivos requeridos.
    //POS: Setea el mapa con sus valores ingresando cada uno de sus casilleros correspondientes y 
    //     en caso de existir ubicaciones de edificios o materiales.
    //     Ingresa los valores a los punteros usuarios_inventario y lista_edificio 
    //     haciendo lectura correspondiente de los arhivos
    void ingreso_datos_mapa(Jugador * j1, Jugador * j2);

    //PRE: Utilizando el archivo ubicaciones.txt.
    //POS: Agrega Edificios/Materiales en sus ubicaciones.
    void procesar_archivo_ubicaciones(Jugador * j1, Jugador * j2);

    //PRE: Utilizando el archivo mapa.txt.
    //POS: Obtiene la cantidad de filas y columnas. Ingresa los valores de los casilleros.
    void procesar_archivo_mapa();

    //PRE: -
    //POS: Inicializa la matriz del mapa con valor 0.
    void generar_matriz();

    //PRE: Para los metodos que necesitan usar filas y columnas ingresadas por el usuario.
    //POS: Hace un chequeo de las fila y columna ingresadas y en caso de estar fuera del rango , vuelve
    //     a pedir al usuario ingresar las coordenadas.
    void validar_coordenada(int &fila, int &columna);

    //PRE:
    //POS:
    bool aceptar_condiciones();

    //PRE:
    //POS:
    bool verificar_partida_empezada();

    //PRE:
    //POS:
    void insertar_jugador_mapa(string id_jugador,Jugador * j1,Jugador * j2, int fila, int columna);
    
    //PRE:
    //POS:
    void procesar_archivo_materiales(Jugador * j1, Jugador * j2);

    //PRE:
    //POS:
    void procesar_objetivos(Jugador * j1, Jugador *  j2);

    //PRE:
    //POS:
    bool verificacion_energia(int cantidad_disponible, int cantidad_necesaria);

    //PRE:
    //POS:
    Objetivo* sortear_objetivos(int id_objetivo);

    //--------------- DICCIONARIO : EDIFICIOS ----------------------------------------------------

    //PRE: Usando el archivo de edificios con por lo menos 1 edificio.
    //POS: Carga el archivo dentro del vector dinamico edificios_posibles.
    void cargar_edificios();

    //PRE: - 
    //POS: Obtenemos el valor del atributo : cantidad_edificios.
    int obtener_cantidad_edificios();


    // -------------- DIVISION PUNTO POR PUNTO : MENU -------------------------------

    //PRE: Debe crearse un edificio con el nombre de algun edificio que exista ( se encuentre en caracteristicas_edificios)
    //     solicitando las coordenadas , se chequea si se poseen los materiales necesarios, si no supero el maximo de edificios y si se puede
    //     construir en tales coordenadas, debe ser un casillero_construible.
    //POS: Agrega el edificio dentro del casillero solicitado.
    void construir_edificio_nombre(Jugador * jugador);

    //PRE: Una vez se solicite construir el edificio y se tenga por validado que existe el nombre del edificio solicitado.
    //POS: Se realizan las validaciones de que no supere el maximo a construir , que se tengan los materiales y que en ese casillero no 
    //     exista edificio_construido.Luego se agrega el edificio , se suma la cantidad y se eliminan los materiales.
    void realizar_construccion(string nombre_nuevo, Jugador * jugador);

    //PRE: En caso de que existan edificios construidos en los casilleros.
    //POS: Muestra cuales edificios estan construidos con su cantidad y en que coordenadas se encuentran.
    void listar_edificios_construidos(Jugador * jugador);

    //PRE: - 
    //POS: Recorre el vector mostrandonos las caracteristicas de los edificios que vienen en el archivo.
    void listar_todos_edificios();

    //PRE: Solicitando coordenadas, fila <= cantidad_filas, columna <= cantidad_columnas.
    //POS: Elimina el edificio solicitado del casillero correspondiente y retorna la mitad de los materiales usados al inventario.
    void demoler_edificio(Jugador * jugador);

    //PRE: Con el nombre del edificio que se desea demoler y sus coordenadas (fila y columna).
    //POS: Obtengo los valores de los materiales a retornar luego de la demolicion y elimino el edificios , 
    //     restando 1 a la cantidad de edificios y sumando los materiales obtenidos al inventario.
    void obtengo_materiales_elimino_edificio(Jugador * jugador, string nombre_edificio, int fila, int columna);

    //PRE: Una vez demolido el edificio.
    //POS: Muestro por pantalla los materiales obtenidos. 
    void imprimir_materiales(int piedra_obtenida, int madera_obtenida, int metal_obtenida, int coins_obtenidos,int energia_obtenidos);

    //PRE: Teniendo cargada la matriz dinamica.
    //POS: Recorro la matriz y muestro los nombres de los casilleros. 
    void mostrar_mapa();

    //PRE: Solicitando las coordenadas, fila <= cantidad_filas, columna <= cantidad_columnas.
    //POS: Muestra por pantalla el mensaje del casillero.
    void consultar_coordenada();

    //PRE: - 
    //POS: Imprime por pantalla las cantidades de los materiales que se poseen.
    void mostrar_inv(Jugador * jugador);


    //PRE: ~
    //POS: Imprime por pantalla los objetivos del jugador correspondiente
    void mostrar_objetivos_jugadores(Jugador* jugador);

    //PRE: En caso de tener edificios construidos que brinden materiales.
    //POS: Obtengo los materiales que brindan los edificios y se guardan en el inventario.
    void almacenar_recursos_producidos(Jugador * jugador);

    //PRE: Recibe los eneteros "max_fila" y  "max_col" con los vaores de las maxima columna y la maxima fila que
    //hay en el mapa
    //POST: Coloca en el mapa 1 unidad de cada material generado. Si la posicion random en la que se lo colocaria
    //resulta estar ocupada, no se coloca dicho material.
    void lluvia_recursos();

    //Carga incorrecta archivos
    //PRE: Todos los archivos se deben haber intentado abrir y cargar
    //POST: Chequea si todos los archivos fueron cargados correctamente. Devuelve true si la carga fue INCORRECTA, y flase 
    //en caso contrario
    bool carga_incorrecta_archivos();

    // -------------- LLUVIA DE RECURSOS -------------------------------
    
    //Generar numero random
    //PRE: Recibe los enteros "min" y "max" con los valores limite (inclusives) entre los cuales se desea generar el numero random 
    //POST: Devuelve un valor random entre "min" y "max"
    int generar_numero_random(int min, int max);
    
    //Cargar vector_casilleros
    //PRE: -
    //POST: Carga en vector_casilleros_lluvia los casilleros habilitados para que puedan llover materiales(son transitables
    //y no tienen ningun material ya ubicado en ellos).
    void cargar_vector_casilleros_lluvia_con_casileros_permitidos();

    //PRE: Recibe un string con el nombre del material a colocar.
    //POST: Con el nombre, identifica la cantidad a agregar de dicho material y retorna el entero
    int definir_cantidad_material(string material_a_colocar);

    //Colocar materiales llovidos en mapa
    //PRE: Recibe enteros con las cantidades totales y pariciales de materiales generados.
    //POST: Coloca en el mapa en las posicione aleatorias generadas por generar_numeros_random() los materiales generados.
    void colocar_materiales_llovidos(int tot_materiales_gen, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales, int cant_gen_coins);

    //Consultar material a colocar
    //PRE: Recibe los enteros "cant_gen_piedras", "cant_gen_maderas", "cant_gen_metales" y "cant_gen_coins" y el string material_a_colocar
    //POST: Modifica por parametro "material_a_colocar" y las cantidades de piedra y madera restantes.
    void consultar_material_a_colocar(int &cant_gen_piedras, int &cant_gen_maderas, int &cant_gen_metales, int &cant_gen_coins, string &material_a_colocar);

    //mostrar alerta materiales no colocados
    //PRE: Recibe 5 enteros con las cantidades de madera piedra metal y coins que han quedado sin colocar
    //Muestra una alerta por pantalla indicando que materiales no se pudieron colocar
    void mostrar_alerta_materiales_no_colocados(int materiales_restantes, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales,int cant_gen_coins);

    //Ejecutar lluvia
    //PRE: Recibe un entero con la cantidad total de materiales y otros 4 enteros con las cantiades de piedra,
    //madera, metal y coins generadas.
    //POST: Efectua la lluvia de materiales colocando en el mapa en las posiciones hablitadas y generadas por
    //la funcion "generar_numero_random".
    void ejecutar_lluvia(int tot_materiales_gen, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales, int cant_gen_coins);

    //Agregar casillero a vector casilleros lluvia
    //PRE: Recibe un puntero a casillero transitable, un entero con el nuevo tamanio del vector y el entero posicion con la posicion
    //en la que se desea agregar el casillero en el vector (sera siempre al final)
    void agregar_casillero_a_vector_casilleros_lluvia (Casillero* casillero, int tam_nuevo, int pos );

    //Swap casiillero
    //PRE: Recibe 2 posiciones
    //POST: Intercambia los elementos de dichas posiciones en el vectorcasilleros_lluvia
    void swap_casillero(int posicion_1, int posicion_2);

    //Sacar_casillero
    //PRE: Recibe un entero con las posicion dentro del vector_casilleros_lluvia que se deasea eliminar (sacar)
    //POST: Quita el casillero que se encuentre en dicha posicion del vector
    void sacar_casillero(int posicion_numero_a_sacar);

    //Obtener_casillero del vector casilleros lluvia
    //PRE: Recibe un entero con la posicion del casillero que se desea obtener
    //POST: Devuelve un puntero casillero transitable con el casillero que se encontraba en la posicion pos del 
    //vector casilleros lluvia
    Casillero* obtener_casillero_vector_casilleros_lluvia( int pos);

    //PRE:
    //POS:
    void guardar_materiales(std::ofstream &archivo_ubicaciones);
    
    //PRE:
    //POS:
    void guardar_jugador(std::ofstream &archivo_ubicaciones, int id_jugdor);

    //PRE:
    //POS:
    void guardar_edificios(std::ofstream &archivo_ubicaciones, int id_jugador);


    //PRE:
    //POS:
    void modificar_edificios();

    //PRE:
    //POS:
    void reparar_edificios(Jugador * jugador);

    //PRE:
    //POS:
    void realizar_reparacion(Jugador * jugador);

    //PRE:
    //POS:
    void comprar_bombas(Jugador * jugador);

    //PRE:
    //POS:
    bool verificacion_andycoins(int requerido, int disponible);

    //PRE:
    //POS:
    bool vacio(ifstream& pArchivo);

    //PRE:
    //POS:
    void atacar_edificios(Jugador * jugador);

    //PRE:
    //POS:
    void realizar_ataque(Jugador * jugador);

    //PRE:
    //POS:
    int devolver_cantidad_filas();

    //PRE:
    //POS:
    int devolver_cantidad_columnas();

    //Detructor
    //PRE: - 
    //POS: Libero la memoria reservada por el mapa y los casilleros creados , liberando los edificios y materiales 
    //     que se encuentran en los casilleros y se guarda la informacion en el archivo ubicaciones.txt,
    //     tambien se libera la memoria reservada por el inventario y las caracteristicas_edificios.
    //     Se vuelve a setear todos los valores en 0.
    ~Mapa();
};



#endif // MAPA_H