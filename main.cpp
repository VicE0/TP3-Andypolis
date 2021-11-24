#include <iostream>
#include "menu.h"
#include "mapa.h"
#include "edificio.h"

#include "jugador.h"

using namespace std;


int main(){

    Mapa * mapa = new Mapa;
    Jugador * j1 = new Jugador(1);
    Jugador * j2 = new Jugador(2);

    mapa->ingreso_datos_mapa();

    if ( ! (mapa->carga_incorrecta_archivos()) ){
    selector_de_menu(mapa, j1, j2);

    }else{
        cout <<"Uno o varios archivos no se pudieron abrir correctamente";
    }

    delete mapa;

    cout << "\n Muchas gracias por visitar la ciudad , nos vemos pronto ! \n" << endl; 


    return 0;
}