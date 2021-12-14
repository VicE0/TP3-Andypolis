#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "CaminoMinimo.h"
#include "listaSP.h"

class Dijkstra: public CaminoMinimo {

private:

    bool * vertices_visitados;
    int * distancia;
    int * recorrido;
    int energia_gastada;
    ListaSP<string> * camino_recorrido;

    // METODOS : 
    void inicializar_visitados(int origen);

    void inicializar_distancia(const int * distancia_origen);

    void inicializar_recorrido(int origen);

    int vertice_minima_distancia();

    void actualizar_distancia(int vertice);

    void mostrar_recorrido(int origen, int distancia);

public:
    Dijkstra(Lista<Casillero*> * vertices, int ** matriz_adyacente);

    void camino_minimo(int origen, int destino);

    ListaSP<string> * obtener_camino_recorrido();

    int obtener_energia_gastada();

    ~Dijkstra() override;

};


#endif 