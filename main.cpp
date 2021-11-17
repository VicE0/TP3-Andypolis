#include <iostream>
#include "menu.h"
#include "mapa.h"
#include "edificio.h"

using namespace std;


int main(){

    Mapa * mapa = new Mapa;

    mapa->ingreso_datos_mapa();

    if ( ! (mapa->carga_incorrecta_archivos()) ){
    selector_de_menu(mapa);

    }else{
        cout <<"Uno o varios archivos no se pudieron abrir correctamente";
    }

    delete mapa;

    cout << "\n Muchas gracias por visitar la ciudad , nos vemos pronto ! \n" << endl; 

    return 0;
}