#include "grafo.h"

Grafo::Grafo(){
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
    for ( int i = 0; i < 20; i++ ){
        cout << endl;
        for ( int j = 0; j < 20; j ++ ){
            if ( matriz_adyacente_j1[i][j] == INFINITO ){
                cout << "∞";
            } else {
                cout << matriz_adyacente_j1[i][j];
            }
            cout << "|";
        }
    }
    cout << endl;
    //cout << "\nAdyacente 2" << endl;
    //for ( int i = 0; i < 10; i++ ){
    //    cout << endl;
    //    for ( int j = 0; j < 10; j ++ ){
    //        if ( matriz_adyacente_j2[i][j] == INFINITO ){
    //            cout << "∞";
    //        } else {
    //            cout << matriz_adyacente_j2[i][j];
    //        }
    //        cout << "|";
    //    }
    //}
    //cout << endl;
}

void Grafo::agregar_caminos(){
    
    int peso, fil, col;

    for ( int i = 0 ; i < vertices->obtener_cantidad(); i++ ){

        for ( int j = 0; j < vertices->obtener_cantidad(); j++){

            if ( i != j ) { // cuando i != j entonces veo cuando pesa ir de un casillero al otro
                cout << "No entiendo nada " << endl;
            }

        }
    }

}


Grafo::~Grafo(){
    delete vertices;
    this->vertices = 0;
}