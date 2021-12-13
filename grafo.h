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

public:
    //Constructor
    Grafo(int filas, int columnas);

    //PRE: Le paso el doble puntero del vertice del casillero
    //POST: Da de alta un nuevo vertice en el grafo.
    void agregar_vertice(Casillero ** nuevo_vertice);

    //PRE: -
    //POST: Crea una matriz auxiliar para poder agrandar una posicion a la matriz
    void agrandar_matrices();

    //PRE: -
    //POST: Muestra por pantalla la matriz adyacente
    void mostrar_adyacente();

    //PRE: -
    //POST: Muestra por pantalla los vertices
    void mostrar_vertices();

    //PRE: -
    //POST: Crea una copia de la matriz adyacente y la llena en el doble puntero de la matriz auxiliar
    void copiar_matriz_adyacente(int ** matriz_aux ,int id);

    //PRE: Necesito el doble puntero de la matriz a la cual le voy a inicializar un nuevo vertice
    //POST: Inicializa un nuevo vertice en la matriz que le ingrso por parametro
    void inicializar_nuevo_vertice( int ** matriz_aux );

    //Destructor matriz adyacencia del jugador ingresado
    void liberar_matriz_adyacente(int id);

    void agregar_caminos();

    //Destructor del grafo
    ~Grafo();
};

#endif