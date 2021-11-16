#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string ARCHIVO_UBICACIONES = "ubicaciones.txt";

bool verificar_ubicaciones();

int main(){
    
    bool partida_empezada;
    
    partida_empezada = verificar_ubicaciones();

    cout<<partida_empezada<<endl;

    return 0;
}

bool verificar_ubicaciones(){ //Adentro iria un objeto mapa para poner los datos correspondientes de ubicaciones
    bool partida_empezada = false;


    ifstream archivo(ARCHIVO_UBICACIONES);

    if (archivo && archivo.get() != archivo.eof()){
        partida_empezada = false;
    }

    else{
        partida_empezada = true;
    }
    archivo.close();
    return partida_empezada;
}