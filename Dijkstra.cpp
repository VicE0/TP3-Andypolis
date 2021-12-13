#include "Dijkstra.h"

Dijkstra::Dijkstra(Lista<Casillero*> * vertices, int ** matriz_adyacente) : CaminoMinimo( vertices, matriz_adyacente){
    this->vertices_visitados = new bool[ canitdad_vertices ];
    this->distancia = new int [ canitdad_vertices ];
    this->recorrido = new int [ canitdad_vertices ];
    this->camino_recorrido = new ListaObjetivos<string>;
    this->energia_gastada = INFINITO;
}

void Dijkstra::camino_minimo(int origen, int destino){
    inicializar_visitados(origen);
    inicializar_distancia(matriz_adyacente[origen]);
    inicializar_recorrido(origen);

    int minimo_vertice;
    bool destino_arribado = origen == destino;
    int vertice_recorrido = 1;

    while ( !destino_arribado ){

        minimo_vertice = vertice_minima_distancia();
        destino_arribado = minimo_vertice == destino;

        if ( !destino_arribado ){
            vertices_visitados[minimo_vertice] = true;
            actualizar_distancia(minimo_vertice);
        }

        vertice_recorrido++;
    }

    mostrar_recorrido(origen, destino);
}

int Dijkstra::vertice_minima_distancia(){
    int minima_distancia = INFINITO;
    int minimo_vertice;

    for ( int i = 0; i < canitdad_vertices; i++ ){
        if ( !vertices_visitados[i] && distancia[i] <= minima_distancia ){
            minima_distancia = distancia[i];
            minimo_vertice = i;
        }
    }

    return minimo_vertice;
}

void Dijkstra::inicializar_visitados(int origen){
    for ( int i = 0; i < canitdad_vertices ; i++){
        vertices_visitados[i] = false;
    }
    vertices_visitados[origen] = true;
}

void Dijkstra::inicializar_recorrido(int origen){
    for ( int i = 0; i < canitdad_vertices ; i++){
        recorrido[i] = origen;
    }
}

void Dijkstra::inicializar_distancia(const int * distancia_origen){
    for ( int i = 0; i < canitdad_vertices ; i++){
        distancia[i] = distancia_origen[i];
    }
}

void Dijkstra::actualizar_distancia(int vertice){
    for ( int i = 0; i < canitdad_vertices; i++){
        if ( !vertices_visitados[i] && distancia[vertice] != INFINITO && distancia[i] > matriz_adyacente[vertice][i] + distancia[vertice]){
            distancia[i] = matriz_adyacente[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}
void Dijkstra::mostrar_recorrido(int origen, int destino) {
    if(distancia[destino] == INFINITO){
        cout << " No hay un camino que conecte " <<  vertices->obtener_nombre(origen + 1) << " con " << vertices->obtener_nombre(destino + 1);

    }else{
        cout << " El camino minimo que une " <<  vertices->obtener_nombre(origen + 1) << " con " << vertices->obtener_nombre(destino + 1);
        cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
        cout << vertices->obtener_nombre(destino + 1);
        camino_recorrido -> insertar_elemento(vertices -> obtener_nombre(destino + 1));   

        energia_gastada = distancia[destino];
        do{
            destino = recorrido[destino];
            camino_recorrido -> insertar_elemento(vertices -> obtener_nombre(destino + 1));
            cout << " <- " << vertices->obtener_nombre(destino + 1);
        }while(origen != destino);
    }
    cout << endl;
}

ListaObjetivos<string> * Dijkstra::obtener_camino_recorrido(){
    return camino_recorrido;
}

int Dijkstra::obtener_energia_gastada(){
    return energia_gastada;
}

Dijkstra::~Dijkstra(){
    delete [] vertices_visitados;
    delete [] recorrido;
    delete [] distancia;
    delete camino_recorrido;
    energia_gastada = INFINITO;
}