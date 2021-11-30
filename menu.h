#include <iostream>

#include "mapa.h"
#include "objetivos/jugada.h"

using namespace std;

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
void procesar_opcion_jugador(int opcion, Mapa * mapa, Jugador * jugador,bool recolecto);

//Pre : 0 < opcion < 5 
//Pos : Se dirige a la opcion elegida por los usuarios.
void procesar_opcion_principal(int opcion, Mapa * mapa, Jugador * j1, Jugador * j2);

void selector_de_menu(Mapa * mapa, Jugador * j1, Jugador * j2);

void partida(Mapa * mapa, Jugador * j1, Jugador * j2);

void verificar_lluvia_de_materiales(int turno, Mapa * mapa);

void randomizador_de_turnos(Jugador * j1, Jugador * j2);

Jugador * verificar_turno_jugador(int turno, Jugador * j1, Jugador * j2);
