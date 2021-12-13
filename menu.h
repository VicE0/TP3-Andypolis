#include <iostream>

#include "mapa.h"
#include "jugador.h"
#include "colors.h"

using namespace std;

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

// MENU PRINCIPAL
int const P_MODIFICAR_EDIFICIO = 1;
int const P_LISTAR_TODOS_EDIFICIOS = 2;
int const P_MOSTRAR_MAPA = 3;
int const P_COMENZAR_PARTIDA = 4;
int const P_GUARDAR_SALIR = 5;


// MENU TURNO
int const CONSTRUIR_EDIFICIO = 1;
int const LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
int const DEMOLER_EDIFICIO = 3;
int const ATACAR_EDIFICIO = 4;
int const REPARAR_EDIFICIO = 5;
int const COMPRAR_BOMBAS = 6;
int const CONSULTAR_COORDENADA = 7;
int const MOSTRAR_INVENTARIO = 8;
int const MOSTRAR_OBJETIVOS = 9;
int const RECOLECTAR_RECURSOS = 10;
int const MOVERSE = 11;
int const FINALIZAR_TURNO = 12;
int const GUARDAR_SALIR = 13;

//Pre : El archivo ubicaciones se encuentra vacio o sin escribir
//Pos : muestra el menu por terminal.
void mostrar_menu_principal();

// Pre: El archivo ubicaciones se encuentra escrito.
// Pos: Se mostraran las opciones que puede elegir el jugador que inicia el turno.
void mostrar_menu_partida();

// Pre: - 
// Pos: Devuelve la opcion elegida , ya validada , del usuario.
int elegir_opcion();

// Pre: 0 < opcion < 12 , y la ciudad andynopolis con los archivos ya procesados 
// Pos: Se dirige a la opcion elegida por el jugador en turno.
void procesar_opcion_jugador(int opcion, Mapa * mapa, Jugador * jugador, bool recolecto);

//Pre : 0 < opcion < 5 
//Pos : Se dirige a la opcion elegida por los usuarios.
void procesar_opcion_principal(int opcion, Mapa * mapa, Jugador * j1, Jugador * j2);

//PRE: Necesito que el archivo ubicaciones este procesado ya que en base a eso decide si el programa esta comenzado o no
//POST: Verifica si la partida esta empezada o no y ejecuta las funciones correspondientes para que comienze el juego en ambos casos
void selector_de_menu(Mapa * mapa, Jugador * j1, Jugador * j2);

//PRE: Necesito que este procesado el mapa y creado los jugadores para comenzar
//POST: Ejecuta las funciones en orden para jugar la partida.
void partida(Mapa * mapa, Jugador * j1, Jugador * j2);

//PRE: Necesito que ya esten creados los turnos para pasarlo y en base a eso verificar si hay quee hacer la lluvia o no
//POST: Si el numero es par ejecuta la lluvia de materiales
void verificar_lluvia_de_materiales(int turno, Mapa * mapa);

//PRE: Necesito tener creados los jugadores y pasarlos como parametro
//POST: Hago un random y asigno los turnos en base a ese random que define quien comienza
void randomizador_de_turnos(Jugador * j1, Jugador * j2);

//PRE:Necesito que me pasen un turno para verificar a quien le toca
//POST: Verifica de quien es el turno y retorna el jugador a utilizar
Jugador * verificar_turno_jugador(int turno, Jugador * j1, Jugador * j2);

//PRE: Tienen que estar creados los jugadores y el mapa
//POST: Le pregunta a los jugadores donde desean comenzar y pasa esos datos al mapa para ponerlos en el mismo y comenzar el juego
void empezar_partida(Mapa * mapa, Jugador * j1, Jugador * j2);

//PRE: Necesito que el usuario haya ingresado una posicion en el mapa
//POST: Verifica que la posicion elegida por el usuario sea valida
bool verificador_de_limite(int posicion, int verificacion_columna_fila);

//PRE: Recibe el jugador y valuea si es el Jugador1 o el Jugador2
//POS: Muestra un mensajen para el jugador ganador
void mensaje_ganador(Jugador * jugador);