#include <iostream>

#include "mapa.h"

using namespace std;

int const CONSTRUIR_EDIFICIO = 1;
int const LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
int const LISTAR_TODOS_EDIFICIOS = 3;
int const DEMOLER_EDIFICIO = 4;
int const MOSTRAR_MAPA = 5;
int const CONSULTAR_COORDENADA = 6;
int const MOSTRAR_INVENTARIO = 7;
int const RECOLECTAR_RECURSOS = 8;
int const LLUVIA_RECURSOS = 9;
int const GUARDAR_SALIR = 10;

// Pre: -  
// Pos: Imprime por terminal el menu de opciones
void mostrar_menu();

// Pre: - 
// Pos: Devuelve la opcion elegida , ya validada , del usuario.
int elegir_opcion();

// Pre: 0 < opcion < 6 , y la ciudad andynopolis con los archivos ya procesados 
// Pos: Se dirige a la opcion elegida por el usuario.
void procesar_opcion(int opcion, Mapa * mapa);
