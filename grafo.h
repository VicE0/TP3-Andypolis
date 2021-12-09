#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"
#include "nodo.h"
#include "casilleros/casillero.h"
#include "casilleros/terreno.h"
#include "casilleros/lago.h"
#include "casilleros/betun.h"
#include "casilleros/camino.h"
#include "casilleros/muelle.h"
#include "jugador.h"
#include "edificio.h"

const int INFINITO = 99999999;

class Grafo
{
private:

    int filas;
    int columnas;
    int ** matriz_adyacente_j1;
    int ** matriz_adyacente_j2;
    Lista<Casillero*> * vertices;

    void copiar_matriz_adyacente(int ** matriz_aux ,int id);

    void inicializar_nuevo_vertice( int ** matriz_aux );

    void liberar_matriz_adyacente(int id);

    void actualizar_matrices_de_adyacencia(int posicion_origen, int posicion_destino, int peso_origen_j1, int peso_origen_j2);

    void actualizar_matriz_de_adyacencia_j1(int posicion_origen, int posicion_destino, int peso_origen_j1);

    void actualizar_matriz_de_adyacencia_j2(int posicion_origen, int posicion_destino, int peso_origen_j2);

public:
    Grafo(int filas, int columnas);
    void agregar_vertice(Casillero ** nuevo_vertice);

    void agrandar_matrices();

    void mostrar_adyacente();

    void mostrar_vertices();

    void agregar_caminos();

    ~Grafo();
};

#endif