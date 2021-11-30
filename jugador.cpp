#include "jugador.h"

Jugador::Jugador(){
    this -> id_jugador = 0;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
    this -> inventario = new Lista<Material>;
    this -> inventario_a_recolectar = new Lista<Material>;
    this -> turno = 0;
    this -> diminutivo = "";
}

Jugador::Jugador(int id_jugador, string diminutivo)
{
    this -> id_jugador = id_jugador;
    this -> energia = 0;
    this -> objetivos_cumplidos = 0;
    this -> inventario = new Lista<Material>;
    this -> inventario_a_recolectar = new Lista<Material>;
    this -> turno = 0;
    this -> diminutivo = diminutivo;
}

/*
string Jugador::obtener_nombre()

Jugador::Jugador(int id_jugador ,int energia, int objetivos_cumplidos, int andycoins_totales)
{
    this -> id_jugador = 0;
    this -> energia = ENERGIA_INICIAL; //dudoso, es solo al inicio
    this -> objetivos_cumplidos = 0;
    this -> andycoins_totales = 0;
    this->inventario = new Lista<Material>;
}

*/

int Jugador::dar_numero()
{
    return id_jugador;
}


Lista<Material> * Jugador::obtener_inventario(){
    return inventario;
}

string Jugador::obtener_diminutivo(){
    return diminutivo;
}


void Jugador::agregar_material(Material * material)
{
    inventario->alta(material, inventario->obtener_cantidad());
}


Material * Jugador::obtener_material(string nombre){
    Material * aux;

    for ( int i = 0 ; i < inventario->obtener_cantidad(); i++){
        if ( inventario->obtener_nodo(i)->obtener_dato()->obtener_nombre() == nombre ) {
            aux = inventario->obtener_nodo(i)->obtener_dato();
        }
    }

    return aux;
}

Material * Jugador::obtener_material_recolectar(string nombre){
    Material * aux;

    for ( int i = 0 ; i < inventario_a_recolectar->obtener_cantidad(); i++){
        if ( inventario_a_recolectar->obtener_nodo(i)->obtener_dato()->obtener_nombre() == nombre ) {
            aux = inventario_a_recolectar->obtener_nodo(i)->obtener_dato();
        }
    }

    return aux;
}
void Jugador::mostrar_cantidad_material(string nombre){

    Material * aux = obtener_material(nombre);

    aux->mostrar_nombre();

}


void Jugador::establecer_turno(int turno){
    this -> turno = turno;
}

int Jugador::obtener_turno(){
    return turno;
}

void Jugador::sumar_cantidad_material(string nombre, int cantidad, bool recolectar){
    if (recolectar){
        Material * aux = obtener_material(nombre);
        aux->sumar_material(cantidad);
    } 
    else{
        Material * aux = obtener_material_recolectar(nombre);
        aux->sumar_material(cantidad);
        }
}

void Jugador::restar_cantidad_material(string nombre, int cantidad,bool recolectar){
    if (recolectar){
    Material * aux = obtener_material(nombre);
    aux->restar_material(cantidad);
    }else{
        Material * aux = obtener_material_recolectar(nombre);
    aux->restar_material(cantidad);
    }

}

void Jugador::mostrar_inventario(){
    int cantidad = inventario->obtener_cantidad();
    for ( int i = 0; i < cantidad; i++){
        Material * aux = inventario->obtener_nodo(i)->obtener_dato();
        cout << "Nombre : " << aux->obtener_nombre();
        cout << " - Cantidad : " << aux->obtener_cantidad_disponible() << endl;
    }
}

bool Jugador::alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int 
cantidad_metal_nec){

    bool alcanza = true;
    int i = 0;
    int cantidad_de_materiales = inventario->obtener_cantidad();
    while (alcanza && i < cantidad_de_materiales){
        
        string material_a_chequear = inventario->obtener_nodo(i)->obtener_dato()->obtener_nombre();

        int cantidad_disponible = inventario->obtener_nodo(i)->obtener_dato()->obtener_cantidad_disponible();
        
        if (material_a_chequear == PIEDRA){
            chequear_material(cantidad_disponible, cantidad_piedra_nec, alcanza);
        } 
        if (material_a_chequear == MADERA){
            chequear_material(cantidad_disponible, cantidad_madera_nec, alcanza);
        } 
        if (material_a_chequear == METAL){
            chequear_material(cantidad_disponible, cantidad_metal_nec, alcanza);
        } 
        i++;
    }
    return alcanza;
}

void Jugador::chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza){
    if (cantidad_disponible < cantidad_material_nec){
                alcanza = false;
    }
}


void Jugador::utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec){
    
    int i = 0;
    int cantidad_de_materiales = inventario->obtener_cantidad();
    while (i < cantidad_de_materiales){
    
        string material_a_chequear = inventario->obtener_nodo(i)->obtener_dato()->obtener_nombre();

        if (material_a_chequear == PIEDRA){
            restar_cantidad_material(material_a_chequear, cantidad_piedra_nec,true);
        }
        if (material_a_chequear == MADERA){
            restar_cantidad_material(material_a_chequear,cantidad_madera_nec,true);
        } 
        if (material_a_chequear == METAL){
            restar_cantidad_material(material_a_chequear,cantidad_metal_nec,true);
        }
        i++;
    }
}

void Jugador::devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec,int cantidad_energia_nec){
    
    int i = 0;
    int cantidad_de_materiales = inventario->obtener_cantidad();

    while (i < cantidad_de_materiales){
    
        string material_a_chequear = inventario->obtener_nodo(i)->obtener_dato()->obtener_nombre();
        
        if (material_a_chequear == PIEDRA){
            sumar_cantidad_material(material_a_chequear,cantidad_piedra_nec,true);
        }
        if (material_a_chequear == MADERA){
            sumar_cantidad_material(material_a_chequear,cantidad_madera_nec,true);        
        } 
        if (material_a_chequear == METAL){
            sumar_cantidad_material(material_a_chequear,cantidad_metal_nec,true);
        }
        if (material_a_chequear == COINS){
            sumar_cantidad_material(material_a_chequear,cantidad_coins_nec,true);
        }
        if (material_a_chequear == ENERGIA){
            energia += cantidad_energia_nec;
        }
        i++;
    }

};

void Jugador::devolver_materiales_recolectar(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec, int cantidad_energia_nec){
    
    int i = 0;
    int cantidad_de_materiales = inventario_a_recolectar->obtener_cantidad();

    while (i < cantidad_de_materiales){
    
        string material_a_chequear = inventario_a_recolectar->obtener_nodo(i)->obtener_dato()->obtener_nombre();
        
        if (material_a_chequear == PIEDRA){
            sumar_cantidad_material(material_a_chequear,cantidad_piedra_nec,false);
        }
        if (material_a_chequear == MADERA){
            sumar_cantidad_material(material_a_chequear,cantidad_madera_nec,false);        
        } 
        if (material_a_chequear == METAL){
            sumar_cantidad_material(material_a_chequear,cantidad_metal_nec,false);
        }
        if (material_a_chequear == COINS){
            sumar_cantidad_material(material_a_chequear,cantidad_coins_nec,false);
        }
        if (material_a_chequear == ENERGIA){
            sumar_cantidad_material(material_a_chequear,cantidad_energia_nec,false);
        }
        i++;
    }

};

void Jugador::imprimir_materiales(int piedra_obtenida, int madera_obtenida, int metal_obtenida, int coins_obtenidos,int energia_obtenidos){

    cout << "\n------------------------------\n" << endl;
    cout << "\nMateriales obtenidos \n" << endl;
    cout << PIEDRA << " : " << piedra_obtenida << endl;
    cout << MADERA <<" : " << madera_obtenida << endl;
    cout << METAL << " : " << metal_obtenida << endl;
    cout << COINS << " : " << coins_obtenidos << endl;
    cout << ENERGIA << " : " << energia_obtenidos << endl;
    cout << "\n------------------------------\n" << endl;

}

void Jugador::coincidir_valores(int *piedra,int *madera,int *metal,int *coins,string nombre,int cantidad){
    if (nombre == PIEDRA){
        *piedra = cantidad;
    }
    else if (nombre == MADERA){
        *madera = cantidad;
    }
    else if (nombre == METAL){
        *metal = cantidad;
    }
    else if (nombre == COINS){
        *coins = cantidad;
    }
}

void Jugador::sumar_materiales_recolectados(){
    int i = 0;
    int piedra,madera,metal,coins;
    int cantidad_de_materiales = inventario_a_recolectar->obtener_cantidad();
    
    while (i < cantidad_de_materiales){
        string material = inventario_a_recolectar->obtener_nodo(i)->obtener_dato()->obtener_nombre();
        int cantidad_recolectada = inventario_a_recolectar->obtener_nodo(i)->obtener_dato()->obtener_cantidad_disponible();

        coincidir_valores(&piedra,&madera,&metal,&coins,material,cantidad_recolectada);
        
        sumar_cantidad_material(material,cantidad_recolectada,true);
        restar_cantidad_material(material,cantidad_recolectada,false);}

    imprimir_materiales(piedra,madera,metal,coins,energia_recolectada);
    energia += energia_recolectada;
    energia_recolectada = 0;
}

int Jugador::obtener_energia(){
    return energia;
}

void Jugador::sumar_energia(int cantidad){
    energia += cantidad;
}

void Jugador::restar_energia(int cantdiad){
    energia -= cantdiad;
}

Jugador::~Jugador(){
    delete inventario;
    inventario = 0;
}
