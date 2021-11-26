#include <iostream>
#include "menu.h"
#include "mapa.h"
#include "edificio.h"
#include "jugador.h"

using namespace std;


int main(){

    Arbol * diccionario = new Arbol();
    Mapa * mapa = new Mapa;
    Jugador * j1 = new Jugador(1, "J");
    Jugador * j2 = new Jugador(2, "U");

    mapa->ingreso_datos_mapa(j1,j2, diccionario);

    if ( ! (mapa->carga_incorrecta_archivos()) ){
    selector_de_menu(mapa, j1, j2, diccionario);

    }else{
        cout <<"Uno o varios archivos no se pudieron abrir correctamente";
    }

    delete j1;
    delete j2;
    delete mapa;
    delete diccionario;
    // delete partida_jugador;

    cout << "\n Muchas gracias por visitar la ciudad , nos vemos pronto ! \n" << endl; 


    return 0;
}