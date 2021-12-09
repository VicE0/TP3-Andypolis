#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "CaminoMinimo.h"

class Dijkstra: public CaminoMinimo {

private:

    bool * vertices_visitados;
    int * distancia;
    int * recorrido;

    // METODOS : 
    void inicializar_visitados(int origen);

    void inicializar_distancia(const int * distancia_origen);

    void inicializar_recorrido(int origen);

    int vertice_minima_distancia();

    void actualizar_distancia(int vertice);

    void mostrar_recorrido(int origen, int distancia);

    void mostrar_iteracion(int iteracion);

public:
    Dijkstra(Lista<Casillero*> * vertices, int ** matriz_adyacente);

    void camino_minimo(int origen, int destino) override;

    ~Dijkstra() override;

};


#endif 