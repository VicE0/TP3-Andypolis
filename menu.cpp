#include "menu.h"

void mostrar_menu_principal(){
    cout << "1.Modificar edificio por nombre." << endl;
    cout << "2.Listar todos los edificios." << endl;
    cout << "3.Mostrar mapa." << endl;
    cout << "4.Comenzar partida." << endl;
    cout << "5.Guardar y salir." << endl;
}

void mostrar_menu_partida(){

    cout << "1.Construir edificio por nombre." << endl;
    cout << "2.Listar los edificios construidos." << endl;
    cout << "3.Demoler un edificio por coordenada." << endl;
    cout << "4.Atacar un edificio por coordenada" << endl;
    cout << "5.Reparar un edificio por coordenada." << endl;
    cout << "6.Comprar bombas." << endl;
    cout << "7.Consultar coordenada." << endl;
    cout << "8.Mostrar inventario." << endl;
    cout << "9.Mostrar objetivos." << endl;
    cout << "10.Recolectar recursos producidos." << endl;
    cout << "11.Moverse a una coordenada." << endl;
    cout << "12.Finalizar turno." << endl;
    cout << "13.Guardar y salir." << endl;

}

bool opcion_valida(int opcion){
    if ( opcion <= 0 || opcion > GUARDAR_SALIR){
        return false;
    }else {
        return true;
    }
}

int elegir_opcion(){
    // validar la opcion elegida por el usuario: 
    int opcion;

    cout << " -> ";
    cin >> opcion;

    while (!opcion_valida(opcion)){
        cout << "Ingrese una opcion valida : ";
        cin >> opcion;
    }

    return opcion;
}

void procesar_opcion_principal(int opcion, Mapa * mapa){
    switch (opcion)
    {

    case P_MODIFICAR_EDIFICIO:
        cout << "Modificar edificio" << endl;
        break;
    
    case P_LISTAR_TODOS_EDIFICIOS:
            mapa->listar_todos_edificios();
        break;
    
    case P_MOSTRAR_MAPA:
            mapa->mostrar_mapa();
        break;
    
    case P_COMENZAR_PARTIDA:
            partida(mapa);
        break;

    }
}

void procesar_opcion_jugador(int opcion, Mapa * mapa, Jugador * jugador){

    switch (opcion)
    {
    case CONSTRUIR_EDIFICIO:
            mapa->construir_edificio_nombre();
        break;

    case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mapa->listar_edificios_construidos();
        break;

    case DEMOLER_EDIFICIO:
            cout << "Demoler edificio" << endl;
        break;

    case ATACAR_EDIFICIO:
            cout << "Atacar edificio" << endl;
        break;

    case REPARAR_EDIFICIO:
            cout << "Reparar edificio" << endl;
        break;

    case COMPRAR_BOMBAS:
            cout << "Comprar bombas" << endl;
        break;

    case CONSULTAR_COORDENADA:
            mapa->consultar_coordenada();
        break;

    case MOSTRAR_INVENTARIO:
            mapa->mostrar_inv();
        break;

    case MOSTRAR_OBJETIVOS:
            cout << "mostrar objetivos" << endl;
        break;

    case RECOLECTAR_RECURSOS:
            mapa->recolectar_recursos_producidos();
        break;

    case MOVERSE:
            cout << "moverse a una coordenada" << endl;
        break;

    case FINALIZAR_TURNO:
            cout << "finalizo el turno" << endl;
        break;
    }
}

void partida(Mapa * mapa){
    int opcion;
    do {

        mostrar_menu_partida();
        opcion = elegir_opcion();
        procesar_opcion_jugador(opcion, mapa);

    }while ( opcion != GUARDAR_SALIR );
}

void selector_de_menu(Mapa * mapa){

    int opcion;
    if (mapa -> verificar_partida_empezada()){
        partida(mapa);
    }

    else{
    cout << "\n ¡ BIENVENIDOS A ANDYPOLIS ! \n" << endl;
        do {

            mostrar_menu_principal();
            opcion = elegir_opcion();
            procesar_opcion_principal(opcion, mapa);

        }while ( opcion != P_GUARDAR_SALIR );
    }
}