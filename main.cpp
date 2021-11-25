#include <iostream>
#include "menu.h"
#include "mapa.h"
#include "edificio.h"
#include "jugada.h"
#include "jugador.h"

using namespace std;


int main(){

    Mapa * mapa = new Mapa;
    Jugada* partida_jugador = new Jugada;

    mapa->ingreso_datos_mapa();

    if ( ! (mapa->carga_incorrecta_archivos()) ){
    selector_de_menu(mapa, partida_jugador);

    }else{
        cout <<"Uno o varios archivos no se pudieron abrir correctamente";
    }

    delete mapa;
    delete partida_jugador;

    cout << "\n Muchas gracias por visitar la ciudad , nos vemos pronto ! \n" << endl; 


    return 0;
}