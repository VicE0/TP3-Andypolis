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
#include "Dijkstra.h"

class Grafo {
private:

    int filas;
    int columnas;
    int ** matriz_adyacente_j1;
    int ** matriz_adyacente_j2;
    Lista<Casillero*> * vertices;

    // probando camino_minimo
    CaminoMinimo * camino_minimo;

    //PRE: -
    //POST: Crea una copia de la matriz adyacente y la llena en el doble puntero de la matriz auxiliar
    void copiar_matriz_adyacente(int ** matriz_aux ,int id);

    //PRE: Necesito el doble puntero de la matriz a la cual le voy a inicializar un nuevo vertice
    //POST: Inicializa un nuevo vertice en la matriz que le ingrso por parametro
    void inicializar_nuevo_vertice( int ** matriz_aux );

    //Destructor matriz adyacencia del jugador ingresado
    void liberar_matriz_adyacente(int id);

    void actualizar_matrices_de_adyacencia(int posicion_origen, int posicion_destino, int peso_origen_j1, int peso_origen_j2);

    void actualizar_matriz_de_adyacencia_j1(int posicion_origen, int posicion_destino, int peso_origen_j1);

    void actualizar_matriz_de_adyacencia_j2(int posicion_origen, int posicion_destino, int peso_origen_j2);

public:
    //Constructor
    Grafo(int filas, int columnas);

    CaminoMinimo * obtener_camino();


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

    

    ListaObjetivos<string> * obtener_recorrido();

    Casillero * obtener_casillero(string pos);

    int obtener_energia_camino();

    //Destructor del grafo
    ~Grafo();
};

#endif