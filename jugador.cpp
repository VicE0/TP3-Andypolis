#include "jugador.h"

Jugador::Jugador(string nombre, int numero_jugador ,int energia, int objetivos_cumplidos)
{
    this -> numero_jugador = 0;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
}

string Jugador::obtener_nombre()
{
    return this -> nombre;
}

int Jugador::dar_numero()
{
    return this ->numero_jugador;
}

