#include "grafo.h"

Grafo::Grafo(int filas, int columnas){
    this->filas = filas;
    this->columnas = columnas;
    this->matriz_adyacente_j1 = 0;
    this->matriz_adyacente_j2 = 0;
    this->vertices = new Lista<Casillero*>;

}

void Grafo::agrandar_matrices(){
    int ** matriz_aux;
    int nueva_cantidad_vertices = vertices->obtener_cantidad() + 1;

    for ( int i = 1; i <= 2 ; i ++ ){

        matriz_aux = new int * [ nueva_cantidad_vertices ];
        for ( int i = 0; i < nueva_cantidad_vertices ; i++ ){
            matriz_aux[i] = new int [ nueva_cantidad_vertices ];
        }

        copiar_matriz_adyacente(matriz_aux , i);
        inicializar_nuevo_vertice( matriz_aux);
        liberar_matriz_adyacente(i);

        if ( i == 1 ){
            matriz_adyacente_j1 = matriz_aux;
        } else {
            matriz_adyacente_j2 = matriz_aux;
        }
    }

}

void Grafo::copiar_matriz_adyacente(int ** matriz_aux ,int id){
    int cantidad_elementos = vertices->obtener_cantidad();
    if ( id == 1 ){

        for ( int i = 0; i < cantidad_elementos; i++ ){
            for ( int j = 0; j < cantidad_elementos; j ++ ){
                matriz_aux[i][j] = matriz_adyacente_j1[i][j];
            }
        } 
    } else {
        for ( int i = 0; i < cantidad_elementos; i++ ){
            for ( int j = 0; j < cantidad_elementos; j ++ ){
                matriz_aux[i][j] = matriz_adyacente_j2[i][j];
            }
        } 
    }

}

void Grafo::inicializar_nuevo_vertice(int ** matriz_aux){
    int cantidad_elementos = vertices->obtener_cantidad();
    for ( int i = 0; i < cantidad_elementos; i++){
        matriz_aux[cantidad_elementos][i] = INFINITO;
        matriz_aux[i][cantidad_elementos] = INFINITO;
    }
    matriz_aux[cantidad_elementos][cantidad_elementos] = 0;
}

void Grafo::liberar_matriz_adyacente(int id){
    if ( id == 1 ){
        for ( int i = 0; i < vertices->obtener_cantidad(); i++ ){
            delete [] matriz_adyacente_j1[i];
        }
        delete [] matriz_adyacente_j1;
    } else {
        for ( int i = 0; i < vertices->obtener_cantidad(); i++ ){
            delete [] matriz_adyacente_j2[i];
        }
        delete [] matriz_adyacente_j2;
    }
}

void Grafo::agregar_vertice(Casillero ** nuevo_casillero){
    agrandar_matrices();
    vertices -> alta(nuevo_casillero, vertices->obtener_cantidad());
}

void Grafo::mostrar_vertices(){
    cout << vertices->obtener_cantidad() << endl;
    for ( int i = 0; i < vertices->obtener_cantidad(); i++){
        if ( i%10 == 0 ){
            cout << "\n";
        }
        cout << (*vertices->obtener_nodo(i)->obtener_dato())->obtener_nombre();
    }
}

void Grafo::mostrar_adyacente(){
    cout << "\nAdyacente 1" << endl;
    int cantidad_elementos = vertices->obtener_cantidad();
    for ( int i = 0; i < 30; i++ ){
        cout << endl;
        for ( int j = 0; j < 30; j ++ ){
            if ( matriz_adyacente_j1[i][j] == INFINITO ){
                cout << "∞";
            } else {
                cout << matriz_adyacente_j1[i][j];
            }
            cout << "|";
        }
    }
    cout << endl;
    cout << "\nAdyacente 2" << endl;
    for ( int i = 0; i < 30; i++ ){
        cout << endl;
        for ( int j = 0; j < 30; j ++ ){
            if ( matriz_adyacente_j2[i][j] == INFINITO ){
                cout << "∞";
           } else {
                cout << matriz_adyacente_j2[i][j];
            }
            cout << "|";
        }
    }
    cout << endl;
}

// SOLO APLICADO AL JUGADOR 1 , FALTARIA IMPLEMENTAR PARA AMBOS : []
void Grafo::agregar_caminos(){
    int fila_anterior, fila_siguiente, columna_anterior, columna_siguiente;
    string origen, casillero_derecho, casillero_inferior, casillero_superior, casillero_izquierdo, fila_string, columna_string;
    int pos_origen, pos_casillero_derecho, pos_casillero_inferior, pos_casillero_superior, pos_casillero_izquierdo, peso_origen_j1, peso_origen_j2;

    for ( int fila = 0; fila < filas ; fila++ ){ 
        for ( int columna = 0; columna < columnas ; columna++ ){ 
            fila_anterior = fila - 1;
            fila_siguiente = fila + 1;
            columna_anterior = columna - 1;
            columna_siguiente = columna + 1;
            fila_string = std::to_string(fila);
            columna_string = std::to_string(columna);

            origen = fila_string + columna_string; 
            casillero_derecho = fila_string + std::to_string(columna_siguiente); 
            casillero_inferior = std::to_string(fila_siguiente) + columna_string; 
            casillero_superior = fila_string + std::to_string(columna_anterior);  
            casillero_izquierdo = std::to_string(fila_anterior) + columna_string; 

            pos_origen = vertices->obtener_pos(origen);
            pos_casillero_derecho = vertices->obtener_pos(casillero_derecho);
            pos_casillero_inferior = vertices->obtener_pos(casillero_inferior);
            pos_casillero_superior = vertices->obtener_pos(casillero_superior);
            pos_casillero_izquierdo = vertices->obtener_pos(casillero_izquierdo);

            peso_origen_j1 = (*vertices->obtener_nodo(pos_origen)->obtener_dato())->obtener_costo_energia(1);
            peso_origen_j2 = (*vertices->obtener_nodo(pos_origen)->obtener_dato())->obtener_costo_energia(2);

            actualizar_matrices_de_adyacencia(pos_origen, pos_casillero_derecho, peso_origen_j1, peso_origen_j2);
            actualizar_matrices_de_adyacencia(pos_origen, pos_casillero_inferior, peso_origen_j1, peso_origen_j2);
            actualizar_matrices_de_adyacencia(pos_origen, pos_casillero_superior, peso_origen_j1, peso_origen_j2);
            actualizar_matrices_de_adyacencia(pos_origen, pos_casillero_izquierdo, peso_origen_j1, peso_origen_j2);
        }
    }
}

void Grafo::actualizar_matrices_de_adyacencia(int posicion_origen, int posicion_destino, int peso_origen_j1, int peso_origen_j2){
    if (posicion_destino != NO_ENCONTRADO){
        actualizar_matriz_de_adyacencia_j1(posicion_origen, posicion_destino, peso_origen_j1);
        actualizar_matriz_de_adyacencia_j2(posicion_origen, posicion_destino, peso_origen_j2);        
    }
}

void Grafo::actualizar_matriz_de_adyacencia_j1(int posicion_origen, int posicion_destino, int peso_origen_j1){
    int peso_destino = (*vertices->obtener_nodo(posicion_destino)->obtener_dato())->obtener_costo_energia(1);
    matriz_adyacente_j1[posicion_origen][posicion_destino] = peso_destino;
    matriz_adyacente_j1[posicion_destino][posicion_origen] = peso_origen_j1;
}

void Grafo::actualizar_matriz_de_adyacencia_j2(int posicion_origen, int posicion_destino, int peso_origen_j2){
    int peso_destino = (*vertices->obtener_nodo(posicion_destino)->obtener_dato())->obtener_costo_energia(2);
    matriz_adyacente_j2[posicion_origen][posicion_destino] = peso_destino;
    matriz_adyacente_j2[posicion_destino][posicion_origen] = peso_origen_j2;
}

Grafo::~Grafo(){
    delete vertices;
    this->vertices = 0;
}