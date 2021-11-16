#include <iostream>
#include "menu.h"
#include "mapa.h"
#include "edificio.h"

#include "jugador.h"

using namespace std;


int main(){

    Mapa * mapa = new Mapa;
    mapa->ingreso_datos_mapa();

    cout << "\n ¡ BIENVENIDOS A ANDYPOLIS ! \n" << endl;

    if ( ! (mapa->carga_incorrecta_archivos()) ){

        mostrar_menu_partida();
        int opcion = elegir_opcion();

        while ( opcion != GUARDAR_SALIR ){

            procesar_opcion_jugador(opcion, mapa);
            mostrar_menu_partida();
            opcion = elegir_opcion();

        }
    }else{
        cout <<"Uno o varios archivos no se pudieron abrir correctamente";
    }

    delete mapa;

    cout << "\n Muchas gracias por visitar la ciudad , nos vemos pronto ! \n" << endl; 


    return 0;
}