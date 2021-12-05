#include "ABB.h"

Arbol::Arbol(){
    root = NULL;
}

void Arbol::insertar(Edificio* edificio){
    this -> root = insertar_nodo(this->root, edificio);
}

Nodo_ABB * Arbol::insertar_nodo(Nodo_ABB * nodo, Edificio * edificio){

    // El primer caso en que no haya raiz , inicializo el arbol :
    if (nodo == NULL){
        nodo = new Nodo_ABB(edificio);
    }

    // Evaluo si es mayor : 
    else if ( edificio -> obtener_nombre() > nodo -> obtener_clave()) {
        nodo -> cambiar_der(insertar_nodo(nodo -> obtener_der(), edificio));
    }

    // Evaluo si es menor : ( es la ultima opcion que queda )
    else {
       nodo -> cambiar_izq(insertar_nodo(nodo -> obtener_izq(), edificio));
    }
    return nodo;
}

void Arbol::mostrar_arbol(Nodo_ABB * nodo){
    if ( nodo != NULL ){
        cout << "\n";
        cout << " -> " << nodo->obtener_edificio()->obtener_nombre() << " "
        << nodo->obtener_edificio()->obtener_cantidad_piedra() << " "
        << nodo->obtener_edificio()->obtener_cantidad_madera() << " "
        << nodo->obtener_edificio()->obtener_cantidad_metal() << " "
        << nodo->obtener_edificio()->obtener_cantidad_construidos() << " " << "Jugador 1 : " 
        << nodo->obtener_edificio()->obtener_restantes_j1() << " " << " Jugador 2 : "
        << nodo->obtener_edificio()->obtener_restantes_j2() << endl;
        cout << "_________________________________________________________________" << endl;
        cout << "\n";
        mostrar_arbol(nodo->obtener_der());
        mostrar_arbol(nodo->obtener_izq());
    }
}

void Arbol::mostrar(){
    mostrar_arbol(root);
}


Nodo_ABB * Arbol::encontrar_nodo(Nodo_ABB * nodo, string clave){
    if ( nodo == NULL ){
        return NULL;
    } else if ( clave > nodo->obtener_clave() ){
        return encontrar_nodo(nodo->obtener_der(), clave) ;

    } else if ( clave < nodo->obtener_clave() ){
        return encontrar_nodo(nodo->obtener_izq(), clave);

    } else {
        return nodo;
    }
}

Nodo_ABB * Arbol::encontrar(string clave){
    Nodo_ABB * dato = encontrar_nodo(root, clave);
    return dato;
}

void Arbol::modificar_datos_edificio(string clave){
    if (clave == "obelisco"){
        cout << "ERROR: Datos del obelisco son inmodificables" << endl;
    }
    else{
        Nodo_ABB * dato = encontrar(clave);
        if (dato == NULL){
        cout << "ERROR: Edificio no encontrado" << endl;
        }
        else{
            modificar_material(dato ->obtener_edificio(), PIEDRA);
            modificar_material(dato ->obtener_edificio(), MADERA);
            modificar_material(dato ->obtener_edificio(), METAL);
        }
    }
}

void Arbol::modificar_material(Edificio * edificio, string nombre_material){
    string respuesta;
    int nueva_cantidad;

    cout << "\nQueres modificar la cantidad de " << nombre_material << " del edificio seleccionado? s/n ";
    cin >> respuesta;
    cout << endl;
    if (respuesta == "s"){
        cout << "\nIngrese la nueva cantidad: ";
        cin >> nueva_cantidad;
        edificio -> modificar_cantidad_material(nombre_material,nueva_cantidad);
    }
}

bool Arbol::existe_edificio(string clave){
    bool existe = false;
    Nodo_ABB * dato = encontrar_nodo(root, clave);

    if ( dato != NULL ){
        existe = true;
    }

    return existe;
}

bool Arbol::supera_maximo(string clave, int id_jugador){

    bool supera = true;
    Edificio * dato = encontrar_nodo(root, clave)->obtener_edificio();

    int maximo = dato -> obtener_maximo_construir();
    int construidos = dato -> obtener_cantidad_construidos(id_jugador);

    int restantes = maximo - construidos;

    if ( restantes > 0 ){
        supera = false;
    }

    return supera;

}