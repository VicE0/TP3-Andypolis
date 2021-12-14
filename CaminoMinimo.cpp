#include "CaminoMinimo.h"

CaminoMinimo::CaminoMinimo(Lista<Casillero*> * vertices, int ** matriz_adyacente){
    this->matriz_adyacente = matriz_adyacente;
    this->vertices = vertices;
    this->canitdad_vertices = vertices->obtener_cantidad();
}