#include "grafo.h"

Grafo::Grafo(int filas, int columnas){
    this->filas = filas;
    this->columnas = columnas;
    this->matriz_adyacente_j1 = 0;
    this->matriz_adyacente_j2 = 0;
    this->vertices = new Lista<Casillero*>;
    this->camino_minimo = nullptr;

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
    int i_menos, i_mas, j_menos, j_mas;
    string origen, destino1, destino2, destino3, destino4, i_s, j_s;
    int pos_origen, pos_destino1, pos_destino2, pos_destino3, pos_destino4, peso_origen1, peso_origen2;
    int cantidad_elementos = vertices->obtener_cantidad();

    for ( int i = 0; i < filas ; i++ ){ 
        for ( int j = 0; j < columnas ; j++ ){ 
            i_menos = i - 1;
            i_mas = i + 1;
            j_menos = j - 1;
            j_mas = j + 1;
            i_s = std::to_string(i);
            j_s = std::to_string(j);

            origen = i_s + j_s; 
            destino1 = i_s + std::to_string(j_mas); 
            destino2 = std::to_string(i_mas) + j_s; 
            destino3 = i_s + std::to_string(j_menos);  
            destino4 = std::to_string(i_menos) + j_s; 

            pos_origen = vertices->obtener_pos(origen);
            pos_destino1 = vertices->obtener_pos(destino1);
            pos_destino2 = vertices->obtener_pos(destino2);
            pos_destino3 = vertices->obtener_pos(destino3);
            pos_destino4 = vertices->obtener_pos(destino4);

            peso_origen1 = (*vertices->obtener_nodo(pos_origen)->obtener_dato())->obtener_costo_energia(1);
            peso_origen2 = (*vertices->obtener_nodo(pos_origen)->obtener_dato())->obtener_costo_energia(2);

            if ( !(pos_destino1 == -1)){
                int peso_des_1 = (*vertices->obtener_nodo(pos_destino1)->obtener_dato())->obtener_costo_energia(1);
                matriz_adyacente_j1[pos_origen][pos_destino1] = peso_des_1;
                matriz_adyacente_j1[pos_destino1][pos_origen] = peso_origen1;
                peso_des_1 = (*vertices->obtener_nodo(pos_destino1)->obtener_dato())->obtener_costo_energia(2);
                matriz_adyacente_j2[pos_origen][pos_destino1] = peso_des_1;
                matriz_adyacente_j2[pos_destino1][pos_origen] = peso_origen2;
            }

            if ( !(pos_destino2 == -1)){
                int peso_des_2 = (*vertices->obtener_nodo(pos_destino2)->obtener_dato())->obtener_costo_energia(1);
                matriz_adyacente_j1[pos_origen][pos_destino2] = peso_des_2;
                matriz_adyacente_j1[pos_destino2][pos_origen] = peso_origen1;
                peso_des_2 = (*vertices->obtener_nodo(pos_destino2)->obtener_dato())->obtener_costo_energia(2);
                matriz_adyacente_j2[pos_origen][pos_destino2] = peso_des_2;
                matriz_adyacente_j2[pos_destino2][pos_origen] = peso_origen2;
            }

            if ( !(pos_destino3 == -1 )){
                int peso_des_3 = (*vertices->obtener_nodo(pos_destino3)->obtener_dato())->obtener_costo_energia(1);
                matriz_adyacente_j1[pos_origen][pos_destino3] = peso_des_3;
                matriz_adyacente_j1[pos_destino3][pos_origen] = peso_origen1;
                peso_des_3 = (*vertices->obtener_nodo(pos_destino3)->obtener_dato())->obtener_costo_energia(2);
                matriz_adyacente_j2[pos_origen][pos_destino3] = peso_des_3;
                matriz_adyacente_j2[pos_destino3][pos_origen] = peso_origen2;
            }

            if ( !(pos_destino4 == -1 )){
                int peso_des_4 = (*vertices->obtener_nodo(pos_destino4)->obtener_dato())->obtener_costo_energia(1);
                matriz_adyacente_j1[pos_origen][pos_destino4] = peso_des_4;
                matriz_adyacente_j1[pos_destino4][pos_origen] = peso_origen1;
                peso_des_4 = (*vertices->obtener_nodo(pos_destino4)->obtener_dato())->obtener_costo_energia(2);
                matriz_adyacente_j2[pos_origen][pos_destino4] = peso_des_4;
                matriz_adyacente_j2[pos_destino4][pos_origen] = peso_origen2;
            }
        }
    }
}

void Grafo::usar_camino_minimo(string origen, string destino, int id){
    int pos_origen = vertices->obtener_pos(origen);
    int pos_destino = vertices->obtener_pos(destino);

    if ( pos_origen == -1){
        cout << " El vertice " << origen << " no existe en el grafo." << endl;
    }

    if ( pos_destino == -1){
        cout << " El vertice " << destino << " no existe en el grafo." << endl;
    }

    usar_camino_minimo(pos_origen, pos_destino, id);
}

void Grafo::usar_camino_minimo(int origen, int destino, int id){
    if ( id == 1){
        camino_minimo = new Dijkstra(vertices, matriz_adyacente_j1);
    } else {
        camino_minimo = new Dijkstra(vertices, matriz_adyacente_j2);
    }
    camino_minimo->camino_minimo(origen, destino);

    delete camino_minimo;
}


Grafo::~Grafo(){
    liberar_matriz_adyacente(1);
    matriz_adyacente_j1 = nullptr;
    liberar_matriz_adyacente(2);
    matriz_adyacente_j2 = nullptr;
    this->vertices = 0;
}