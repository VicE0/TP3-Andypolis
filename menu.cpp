#include "menu.h"

void mostrar_menu(){
cout << "1.Construir edificio por nombre." << endl;
cout << "2.Listar los edificios construidos." << endl;
cout << "3.Listar todos los edificios." << endl;
cout << "4.Demoler un edificio por coordenada." << endl;
cout << "5.Mostrar mapa." << endl;
cout << "6.Consultar coordenada." << endl;
cout << "7.Mostrar inventario." << endl;
cout << "8.Recolectar recursos producidos." << endl;
cout << "9.Lluvia de recursos." << endl;
cout << "10.Guardar y salir." << endl;

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

void procesar_opcion(int opcion, Mapa * mapa){

    switch (opcion)
    {
    case CONSTRUIR_EDIFICIO:
            mapa->construir_edificio_nombre();
        break;

    case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mapa->listar_edificios_construidos();
        break;

    case LISTAR_TODOS_EDIFICIOS:
            mapa->listar_todos_edificios();
        break;

    case DEMOLER_EDIFICIO:
            mapa->demoler_edificio();
        break;

    case MOSTRAR_MAPA:
            mapa->mostrar_mapa();
        break;

    case CONSULTAR_COORDENADA:
            mapa->consultar_coordenada();
        break;

    case MOSTRAR_INVENTARIO:
            mapa->mostrar_inv();
        break;

    case RECOLECTAR_RECURSOS:
            mapa->recolectar_recursos_producidos();
        break;

    case LLUVIA_RECURSOS:
            mapa->lluvia_recursos();
        break;
    }
}
