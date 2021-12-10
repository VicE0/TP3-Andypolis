#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "CaminoMinimo.h"
#include "listaObjetivos.h"

class Dijkstra: public CaminoMinimo {

private:

    bool * vertices_visitados;
    int * distancia;
    int * recorrido;
    ListaObjetivos<string> * camino_recorrido;

    // METODOS : 
    void inicializar_visitados(int origen);

    void inicializar_distancia(const int * distancia_origen);

    void inicializar_recorrido(int origen);

    int vertice_minima_distancia();

    void actualizar_distancia(int vertice);

    bool mostrar_recorrido(int origen, int distancia);

public:
    Dijkstra(Lista<Casillero*> * vertices, int ** matriz_adyacente);

    bool camino_minimo(int origen, int destino);

    ~Dijkstra() override;

};


#endif 