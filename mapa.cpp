#include "mapa.h"

Mapa::Mapa(){

    this -> cantidad_filas = 0;
    this -> cantidad_columnas = 0;
    this -> mapa = 0;
    this -> cantidad_edificios = 0;
    this -> vector_casilleros_lluvia = 0;
    this -> total_casilleros = 0;
    this -> mapa_bien_cargado = true;
    this -> ubicaciones_bien_cargadas = true;
    this -> diccionario = new Arbol;
    this -> grafo = 0;
    // this -> objetivos_jugador = 0;

}

bool Mapa::carga_incorrecta_archivos(){
    bool carga_incorrecta = ( ( ! mapa_bien_cargado ) || ( ! ubicaciones_bien_cargadas ) || (obtener_cantidad_edificios() == -1) );

    return carga_incorrecta;

}

void Mapa::ingreso_datos_mapa(Jugador * j1, Jugador * j2){

    procesar_archivo_materiales(j1,j2);
    cargar_edificios();
    procesar_archivo_mapa();
    procesar_archivo_ubicaciones( j1, j2);
    procesar_objetivos(j1,j2);

}

void Mapa::procesar_archivo_mapa(){
    ifstream arch;
    arch.open(ARCHIVO_MAPA);
    if(arch.is_open()){
        
        string filas, columnas, id_casillero, i_s, j_s;
        for ( int i = 0 ; i < 1 ; i++){
            arch >> filas; 
            arch >> columnas;
            cantidad_filas = stoi(filas);
            cantidad_columnas = stoi(columnas);
        }
        string nombre;
        grafo = new Grafo(cantidad_filas, cantidad_columnas);

        generar_matriz();

        for ( int i = 0; i < cantidad_filas; i++){
            for (int j = 0; j < cantidad_columnas; j++){
                arch >> nombre ;
                i_s = std::to_string(i);
                j_s = std::to_string(j);
                id_casillero = i_s + j_s;

                if ( nombre == "T") {
                    this->mapa[i][j] = new Terreno(i, j, id_casillero);
                } 
                else if (nombre == "C") {
                    this->mapa[i][j] = new Camino(i,j, id_casillero);
                }
                else if (nombre == "B") {
                    this->mapa[i][j] = new Betun(i,j, id_casillero);
                }
                else if (nombre == "M") {
                    this->mapa[i][j] = new Muelle(i,j, id_casillero);
                }
                else if (nombre == "L") {
                    this->mapa[i][j] = new Lago(i,j, id_casillero);
                }
                grafo->agregar_vertice(&mapa[i][j]);
            }
        }
        
    }else{
        mapa_bien_cargado = false;
    }
}

void Mapa::generar_matriz(){
    this->mapa = new Casillero ** [ cantidad_filas ];
    for ( int i = 0; i < cantidad_filas; i++){
        mapa[i] = new Casillero * [ cantidad_columnas ];
    }

}

// Proceso el archivo de materiales :
void Mapa::procesar_archivo_materiales(Jugador * j1, Jugador * j2){
    ifstream archivo;
    archivo.open(ARCHIVO_MATERIALES);

    if(archivo.is_open()){

        string nombre;
        string cantidad_1;
        string cantidad_2;

        Material * material_j1;
        Material * material_j2;
        Material * material_rec_j1;
        Material * material_rec_j2;
        
        while(archivo >> nombre){
            archivo >> cantidad_1;
            archivo >> cantidad_2;

            material_j1 = new Material(nombre, stoi(cantidad_1) );
            material_j2 = new Material(nombre, stoi(cantidad_2) );
            material_rec_j1 = new Material(nombre,0);
            material_rec_j2 = new Material(nombre,0);

            // dependiendo que jugador este , cargo sus datos en sus inventarios :
            j1->agregar_material(material_j1);
            j2->agregar_material(material_j2);
            j1->agregar_material_inv_recolectar(material_rec_j1);
            j2->agregar_material_inv_recolectar(material_rec_j2);
        }

        archivo.close();
    }
    else{

        j1->obtener_inventario()->cambiar_cantidad(ERROR);
        j2->obtener_inventario()->cambiar_cantidad(ERROR);

    }

    archivo.close();
}

void Mapa::procesar_objetivos(Jugador * j1, Jugador *  j2)
{   
    j1 -> asignar_objetivos();
    j2 -> asignar_objetivos();
}


void Mapa::insertar_jugador_mapa(string id_jugador,Jugador * j1,Jugador * j2, int fila, int columna){
    if ( id_jugador == "1" ){
        mapa[fila][columna]->agregar_jugador(j1);
    } else {
        mapa[fila][columna]->agregar_jugador(j2);
    }
}

bool Mapa::vacio(ifstream& pArchivo) { 
    return pArchivo.peek() == ifstream::traits_type::eof(); 
} 

void Mapa::procesar_archivo_ubicaciones(Jugador * j1, Jugador * j2){
    
    int madera, piedra, metal, maximo, id, vida;
    ifstream archivo(ARCHIVO_UBICACIONES);
    string nombre,segundo_nombre, barra, fila, columna, id_jugador;

        if (archivo && mapa_bien_cargado){
            if ( !vacio(archivo) ){

                while(archivo >> nombre){
                    if ( nombre == "1" || nombre == "2"){ // EVALUO SI ES UN JUGADOR
                        getline(archivo, barra, '(');
                        getline(archivo, fila, ',');
                        getline(archivo, barra, ' ');
                        getline(archivo, columna, ')');
                        id_jugador = nombre;
                        id = stoi(id_jugador);

                        insertar_jugador_mapa(id_jugador, j1, j2, stoi(fila), stoi(columna));

                    } else if ( nombre == PIEDRA || nombre == MADERA || nombre == METAL  ) { // EVALUO SI ES UN MATERIAL

                        getline(archivo, barra, '(');
                        getline(archivo, fila, ',');
                        getline(archivo, barra, ' ');
                        getline(archivo, columna, ')');
                        mapa[stoi(fila)][stoi(columna)]->agregar_material(nombre, 1);

                    } else { // EVALUO SI ES UN EDIFICIO 
                        if ( nombre == "planta"){
                            archivo >> segundo_nombre;
                            getline(archivo, barra, '(');
                            getline(archivo, fila, ',');
                            getline(archivo, barra, ' ');
                            getline(archivo, columna, ')');
                            nombre += " " + segundo_nombre;
                        }

                        if ( nombre == "mina"){
                            getline(archivo,segundo_nombre,'(');
                            if (segundo_nombre == " oro "){ //ver si hay q poner espacio o no
                                //getline(archivo, barra, '(');
                                getline(archivo, fila, ',');
                                getline(archivo, barra, ' ');
                                getline(archivo, columna, ')');
                                nombre += " oro";
                            } else {
                                getline(archivo, fila, ',');
                                getline(archivo, barra, ' ');
                                getline(archivo, columna, ')');
                                cout << nombre << fila << columna << endl;
                            }
                        } else {
                            getline(archivo, barra, '(');
                            getline(archivo, fila, ',');
                            getline(archivo, barra, ' ');
                            getline(archivo, columna, ')');
                        }

                        Edificio * edificio = diccionario->encontrar(nombre)->obtener_edificio();
                        vida = edificio -> devolver_vida();
                        piedra = edificio-> obtener_cantidad_piedra();
                        madera = edificio->obtener_cantidad_madera();
                        metal = edificio->obtener_cantidad_metal();
                        maximo = edificio->obtener_maximo_construir();

                        mapa[stoi(fila)][stoi(columna)]->agregar_edificio(nombre, vida, id, piedra, madera, metal, maximo);
                        edificio->sumar_cantidad(id);
                    }

                }
                
                partida_empezada = true;
                archivo.close();

            }
            else{
                partida_empezada = false;
            }
        }else{
            ofstream archivo(ARCHIVO_UBICACIONES);
            ubicaciones_bien_cargadas = false;
        }
}

bool Mapa::verificar_partida_empezada(){
    return partida_empezada;
}

void Mapa::validar_coordenada(int &fila, int &columna){
    cout << "\n Ingrese las coordenadas : \n" << endl;
    cout << "\n - Ingrese la fila -> ";
    cin >> fila;
    cout << " - Ingrese la columna -> ";
    cin >> columna;
    cout << "\n";

    while ( fila > cantidad_filas || columna > cantidad_columnas ){
        cout << "\n### Se ingresaron coordenadas fuera del limite : ";
        cout << "filas <= " << cantidad_filas << " - columnas <= " << cantidad_columnas << "###\n" << endl;

        cout << "\n Ingrese la fila -> ";
        cin >> fila;
        cout << " Ingrese la columna -> ";
        cin >> columna;
        cout << "\n";
    }
}

bool Mapa::aceptar_condiciones(){
    bool acepto = false;
    char opcion;
    cout << "\n Desea realizar la operacion ? ( s/n ) : ";
    cin >> opcion;
    cout << "\n";

    if ( opcion == 's'){
        acepto = true;
    }

    return acepto;
}

bool Mapa::verificacion_energia(int cantidad_disponible, int cantidad_necesaria){
    bool disponible = false;
    if ( cantidad_disponible >= cantidad_necesaria ){
        disponible = true;
    }
    return disponible;
}


// --------------- DICCIONARIO : EDIFICIOS --------------------------------------------------

void Mapa::cargar_edificios(){
ifstream nuevo_archivo;
    nuevo_archivo.open(ARCHIVO_EDIFICIO);

    if(nuevo_archivo.is_open()){


        string nombre_edificio, segundo_nombre, cantidad_piedra, cantidad_madera, cantidad_metal, maximo;

        int piedra, madera, metal, maximo_construir;

        Edificio * nuevo_edificio;

        while (nuevo_archivo >> nombre_edificio){
            if ( nombre_edificio == "planta"){
                nuevo_archivo >> segundo_nombre;
                nuevo_archivo >> cantidad_piedra;
                nuevo_archivo >> cantidad_madera;
                nuevo_archivo >> cantidad_metal;
                nuevo_archivo >> maximo;

                nombre_edificio += " " + segundo_nombre;

            } else if ( nombre_edificio == "mina"){
                nuevo_archivo >> segundo_nombre;
                if (segundo_nombre == "oro"){
                    nuevo_archivo >> cantidad_piedra;
                    nuevo_archivo >> cantidad_madera;
                    nuevo_archivo >> cantidad_metal;
                    nuevo_archivo >> maximo;

                    nombre_edificio += " " + segundo_nombre;
                }else{
                    cantidad_piedra = segundo_nombre;
                    nuevo_archivo >> cantidad_madera;
                    nuevo_archivo >> cantidad_metal;
                    nuevo_archivo >> maximo;
                }
            }else {
                nuevo_archivo >> cantidad_piedra;
                nuevo_archivo >> cantidad_madera;
                nuevo_archivo >> cantidad_metal;
                nuevo_archivo >> maximo;

            }

            piedra = stoi(cantidad_piedra);
            madera = stoi(cantidad_madera);
            metal = stoi(cantidad_metal);
            maximo_construir = stoi(maximo);

            if (nombre_edificio == ASERRADERO){

                nuevo_edificio = new Aserradero(0, 1, piedra, madera, metal, maximo_construir);

            }
            else if ( nombre_edificio == ESCUELA){

                nuevo_edificio = new Escuela(0, 1, piedra, madera, metal, maximo_construir);

            }
            else if ( nombre_edificio == FABRICA){

                nuevo_edificio = new Fabrica(0, 2,piedra, madera, metal, maximo_construir);

            }
            else if ( nombre_edificio == MINA){

                nuevo_edificio = new Mina(0, 2, piedra, madera, metal, maximo_construir);

            }
            else if ( nombre_edificio == OBELISCO){

                nuevo_edificio = new Obelisco(0, 1, piedra, madera, metal, maximo_construir);

            }
            else if ( nombre_edificio == PLANTA_ELECTRICA){
                nuevo_edificio = new Planta_electrica(0, 1, piedra, madera, metal, maximo_construir);

            }
            else if ( nombre_edificio == MINA_ORO){

                nuevo_edificio = new Mina_oro(0, 2, piedra, madera, metal, maximo_construir);
            }
            
            this -> diccionario -> insertar(nuevo_edificio);
            cantidad_edificios++;

        }

        nuevo_archivo.close();
    }else{
        cantidad_edificios = ERROR;
    }
}

int Mapa::obtener_cantidad_edificios(){
    return cantidad_edificios;
}

// --------------  MENU JUGADOR -------------------------------

// 1) CONSTRUIR EDIFICIO POR NOMBRE ------------------------------------
void Mapa::construir_edificio_nombre(Jugador * jugador){

    int energia_jugador = jugador->obtener_energia();
    string nombre_nuevo;
    cout << "\n -> Ingrese el nombre del nuevo edificio que desea construir : ";
    cin.ignore();
    getline(cin , nombre_nuevo);

    if ( verificacion_energia( energia_jugador, 15) ){

        bool existe_edificio = diccionario->existe_edificio(nombre_nuevo);
        if ( existe_edificio ){

            realizar_construccion(nombre_nuevo, jugador);

        } else {
            cout << "\n El edificio buscado NO existe . \n" << endl;
        }
    } else {
        cout << "\n -> Usted no puede construir por falta de energia.\n" << endl;
    }

}

void Mapa::realizar_construccion(string nombre_nuevo, Jugador * jugador){

        int id_jugador = jugador->dar_numero();
        Edificio * edificio = diccionario->encontrar(nombre_nuevo)->obtener_edificio();

        int piedra_necesaria = edificio->obtener_cantidad_piedra();
        int madera_necesaria = edificio->obtener_cantidad_madera();
        int metal_necesario = edificio->obtener_cantidad_metal();
        int maximo = edificio->obtener_maximo_construir();
        int vida = edificio -> devolver_vida();

        bool supera_max = diccionario -> supera_maximo(nombre_nuevo, id_jugador);
        bool alcanzan_materiales = jugador -> alcanzan_materiales(piedra_necesaria, madera_necesaria, metal_necesario);

        if ( !supera_max){
            if (alcanzan_materiales){
                if ( aceptar_condiciones() ){

                    int fila , columna;
                    cout << "\n ### En esta seccion podra CONSTRUIR un EDIFICIO : ###\n" << endl;
                    validar_coordenada( fila, columna);
                    if ( mapa[fila][columna]->obtener_nombre() == "T" ){
                        
                        bool existe_edificio_construido = mapa[fila][columna]->existe_edificio();
                        if ( ! existe_edificio_construido ){
                            mapa[fila][columna]->agregar_edificio(nombre_nuevo,id_jugador, vida, piedra_necesaria, madera_necesaria, metal_necesario, maximo);

                            edificio->sumar_cantidad(jugador->obtener_id());

                            jugador->restar_energia(15);
                            jugador->utilizar_materiales(piedra_necesaria, madera_necesaria, metal_necesario);

                            cout << "\n ¡ FELICITACIONES : El edificio " << nombre_nuevo << " fue creado exitosamente ! \n" << endl;
                        }else{
                            cout << "\n El casillero ya contiene un edificio .\n" << endl;
                        }
                    }else{
                        cout <<"\nEste no es un terreno por lo que no se pueden construir edificios en el\n"<<endl;
                        mapa[fila][columna]->mostrar_casillero();
                        cout<<endl;
                    }
                }
            }
            else{
                cout<<"\n No se puede construir el edificio de tipo " << nombre_nuevo << " ya que no alcanzan los materiales para construirlo.\n"<<endl;
            }
        }else {
            cout << "\n No se pueden construir mas " << nombre_nuevo << " ya que supera el maximo permitido. \n" << endl; 
        }

}

// 2) LISTAR EDIFICIOS DEL JUGADOR ------------------------------------
void Mapa::listar_edificios_construidos(Jugador * jugador){
    int id_jugador = jugador->dar_numero();
    int cantidad_construidos;
    int codigo_edificio;
    string nombre_edificio;
    Edificio * aux = nullptr;

    cout << "\n";
    for ( int i = 0; i < cantidad_filas; i++){
        for ( int j = 0; j < cantidad_columnas ; j++ ){
            
            if ( mapa[i][j]->existe_edificio() ){
                aux = mapa[i][j]->obtener_edificio_construido();
                codigo_edificio = aux->devolver_id_jugador();
                
                if ( id_jugador == codigo_edificio ){

                    nombre_edificio = aux->obtener_nombre();
                    cout << "Edificio construido : " << nombre_edificio << " (" << i << ", "<< j << ") " << endl;
                }
            }
        }
    }
    cout << "\n";
}

// 3) DEMOLER UN EDIFICIO ------------------------------------
void Mapa::demoler_edificio(Jugador * jugador){

    int id_jugador = jugador->dar_numero();
    int energia_jugador = jugador->obtener_energia();
    cout << "\n\t\t ###   En esta seccion podra DEMOLER un EDIFICIO :   ###" << endl;
    cout << "\n";
    
    if ( verificacion_energia(energia_jugador, 15 )){
        int fila, columna;
        cout << " Ingrese las coordenadas del edificio a demoler : \n" << endl;

        validar_coordenada( fila, columna);

        string nombre_edificio = mapa[fila][columna]->obtener_nombre_edificio();

        if ( nombre_edificio != ""){
            int codigo_edificio = mapa[fila][columna]->obtener_edificio_construido()->devolver_id_jugador();

            if ( id_jugador == codigo_edificio ){
                if ( aceptar_condiciones() ){

                obtengo_materiales_elimino_edificio(jugador, nombre_edificio, fila, columna);
                cout << "\n\t\t ###   El edificio : " << nombre_edificio << ", ha sido DEMOLIDO exitosamente !   ###\n" << endl;

                }

            } else {
                cout << "\n\t -> No se puede demoler un edificio que no es propio.\n" << endl;
            }

        } else {
            cout << "\n En la coordenada ingresada no existe ningun edificio ...\n" << endl;
        }
    } else {
        cout << "\n -> Usted no cuenta con la cantidad de enrgia necesaria. \n" << endl;
    }

}

void Mapa::obtengo_materiales_elimino_edificio(Jugador * jugador, string nombre_edificio, int fila, int columna){

    int mitad_piedra, mitad_madera, mitad_metal;
    Edificio * edificio = diccionario->encontrar(nombre_edificio)->obtener_edificio();

    mitad_piedra = edificio->obtener_mitad_piedra();
    mitad_madera = edificio->obtener_mitad_madera();
    mitad_metal = edificio->obtener_mitad_metal();

    // NO SE OBTIENE ANDYCOINS CUANDO DEMUELO UN EDIFICIO : 
    jugador-> imprimir_materiales(mitad_piedra, mitad_madera, mitad_metal, 0, 0);
    jugador->devolver_materiales(mitad_piedra, mitad_madera, mitad_metal,0,0);

    mapa[fila][columna]->eliminar_edificio();
}



// 4) ATACAR UN EDIFICIO ------------------------------------
void Mapa::atacar_edificios(Jugador * jugador){
    int energia_jugador = jugador->obtener_energia();
    cout << "\n\t\t ###   En esta seccion podra REPARAR un EDIFICIO :   ###" << endl;
    cout << "\n";
    
    if ( verificacion_energia(energia_jugador, 30 )){
        bool tiene_bombas = jugador->obtener_material(BOMBA)->obtener_cantidad_disponible() > 0;
        if (tiene_bombas){
            realizar_ataque(jugador);
        }else{
            cout << "\n -> Usted no tiene ninguna bomba para usar. \n" << endl;
        }
    }else {
        cout << "\n -> Usted no cuenta con la cantidad de energia necesaria. \n" << endl;
    }
}

void Mapa::realizar_ataque(Jugador * jugador){
    int fila, columna;
    int id_jugador = jugador->dar_numero();
    

    cout << " Ingrese las coordenadas del edificio a atacar : \n" << endl;

    validar_coordenada(fila, columna);

    string nombre_edificio = mapa[fila][columna]->obtener_nombre_edificio();

    if ( nombre_edificio != ""){
        Edificio * edificio = mapa[fila][columna]->obtener_edificio_construido();
        int codigo_edificio = edificio->devolver_id_jugador();

        if ( id_jugador != codigo_edificio ){
            if ( aceptar_condiciones() ){
                jugador->obtener_material(BOMBA)->restar_material(1);
                edificio -> atacar();
                mapa[fila][columna]->comprobar_destruccion_edificio();
                jugador->restar_energia(30);
            }
        }else {
                cout << "\n\t -> No se puede atacar a tu propio edificio.\n" << endl;
        }
    }else {
        cout << "\n En la coordenada ingresada no existe ningun edificio ...\n" << endl;
    }
}

// 5) REPARAR UN EDIFICIO ------------------------------------
void Mapa::reparar_edificios(Jugador * jugador){
    int energia_jugador = jugador->obtener_energia();
    cout << "\n\t\t ###   En esta seccion podra ATACAR un EDIFICIO :   ###" << endl;
    cout << "\n";
    
    if ( verificacion_energia(energia_jugador, 25 )){
            realizar_reparacion(jugador);
        }
    else {
        cout << "\n -> Usted no cuenta con la cantidad de energia necesaria. \n" << endl;
    }

}

void Mapa::realizar_reparacion(Jugador * jugador){
    int fila, columna;
    int id_jugador = jugador->dar_numero();
    

    cout << " Ingrese las coordenadas del edificio a reparar : \n" << endl;

    validar_coordenada(fila, columna);

    string nombre_edificio = mapa[fila][columna]->obtener_nombre_edificio();

    if ( nombre_edificio != ""){
        Edificio * edificio = mapa[fila][columna]->obtener_edificio_construido();
        int codigo_edificio = edificio->devolver_id_jugador();

        if ( id_jugador == codigo_edificio ){
            if ( aceptar_condiciones() ){
                bool edificio_reparable = edificio -> devolver_vida() < edificio -> devolver_vida_max();

                if (edificio_reparable){
                    int piedra_necesaria = edificio-> obtener_cantidad_piedra()/4;
                    int madera_necesaria = edificio-> obtener_cantidad_madera()/4;
                    int metal_necesario = edificio-> obtener_cantidad_metal()/4;
                    bool alcanzan_materiales = jugador -> alcanzan_materiales(piedra_necesaria, madera_necesaria, metal_necesario);

                    if (alcanzan_materiales){
                        jugador->utilizar_materiales(piedra_necesaria, madera_necesaria, metal_necesario);
                        edificio -> reparar();
                        cout << "\n\t\t ###   El edificio ha sido REPARADO exitosamente !   ###\n" << endl;
                        jugador->restar_energia(25);
                    }else{
                        cout << "\n\t No tenes materiales suficientes.\n" << endl;
                    }
                    
                }else{
                    cout << "\n\t El edificio esta totalmente arreglado.\n" << endl;
                }
            }
        }else {
                cout << "\n\t -> No se puede reparar un edificio que no es propio.\n" << endl;
        }
    }else {
        cout << "\n En la coordenada ingresada no existe ningun edificio ...\n" << endl;
    }
}


// 6) COMPRAR BOMBAS ------------------------------------
void Mapa::comprar_bombas(Jugador * jugador){
    int cantidad_requerida, precio_total;
    int cantidad_andycoins = jugador->obtener_material(COINS)->obtener_cantidad_disponible();
    if ( verificacion_energia(jugador->obtener_energia(), 5) ){
        cout << "Ingrese la cantidad que desea comprar : ";
        cin >> cantidad_requerida;

        precio_total *= COSTO_BOMBA * cantidad_requerida;
        if ( verificacion_andycoins(precio_total, cantidad_andycoins) ){
            // Sumo la cantidad de bombas compradas al inventario: 
            jugador->obtener_material(BOMBA)->sumar_material(cantidad_requerida);
            // Resto los andycoins utilizados: 
            jugador->obtener_material(COINS)->restar_material(precio_total);
        } else {
            cout << "\n -> No tenes la cantidad necesaria de Andycoins para comprar tantas bombas.\n" << endl;
        }

    } else {
        cout << "\n -> No tenes la cantidad suficiente de energia para realizar la compra. \n" << endl;
    }
}

bool Mapa::verificacion_andycoins(int requerido, int disponible){
    bool alcanza = false;
    if ( requerido < disponible ){
        alcanza = true;
    }
    return alcanza;
}

// 7) CONSULTAR COORDENADA ------------------------------------
void Mapa::consultar_coordenada(){
    int fila , columna;

    validar_coordenada( fila, columna);

    mapa[fila][columna]->mostrar_casillero() ;
    cout << "\n";
}

// 8) MOSTRAR INVENTARIO ------------------------------------
void Mapa::mostrar_inv(Jugador * jugador){
    jugador->mostrar_inventario();
}

// 9) MOSTRAR OBJETIVOS
void Mapa::mostrar_objetivos_jugadores(Jugador * jugador)
{
    jugador -> mostrar_objetivos();
}

// 10) RECOLECTAR RECURSOS PRODUCIDOS ------------------------------------
void Mapa::almacenar_recursos_producidos(Jugador * jugador){
    string nombres_edificios[] = {MINA, ASERRADERO, FABRICA, ESCUELA, PLANTA_ELECTRICA, MINA_ORO};
    int piedra = 0;
    int madera = 0;
    int metal = 0;
    int andycoin = 0;
    int energia_rec = 0;
    int cantidad_edificios, total_brindado , cantidad_construidos, cantidad_a_brindar;
    string nombre_edificio;

    cantidad_edificios = obtener_cantidad_edificios();

    Edificio * edificio_seleccionado;

    for ( int i = 0; i < 6; i++ ){ //menor a la cantidad contruida
        edificio_seleccionado = diccionario -> encontrar( nombres_edificios[i] ) -> obtener_edificio();
        nombre_edificio = edificio_seleccionado->obtener_nombre();
        cantidad_construidos = edificio_seleccionado->obtener_cantidad_construidos(jugador->obtener_id());
        cantidad_a_brindar = edificio_seleccionado->obtener_cantidad_brindada();
        total_brindado = cantidad_construidos * cantidad_a_brindar;

        if (nombre_edificio == MINA){
            piedra += total_brindado;
        } 
        else if (nombre_edificio == FABRICA){
            metal += total_brindado;
        }
        else if (nombre_edificio == ASERRADERO){     
            madera += total_brindado;
        } 
        else if (nombre_edificio == MINA_ORO || nombre_edificio == ESCUELA ){
            andycoin += total_brindado;
        } 
        else if (nombre_edificio == PLANTA_ELECTRICA){
            energia_rec += total_brindado;
        }
    }
    jugador -> devolver_materiales_recolectar(piedra, madera, metal, andycoin, energia_rec);
}

int Mapa::generar_numero_random(int min, int max){
    int range = max + 1  - min;  
    return min + ( rand() % range);

}

void Mapa::consultar_material_a_colocar(int &cant_gen_piedras, int &cant_gen_maderas, int &cant_gen_metales, int &cant_gen_coins,string &material_a_colocar ){
    if (cant_gen_piedras){
        material_a_colocar = PIEDRA;
        cant_gen_piedras --;

    } else if (cant_gen_maderas){
        material_a_colocar = MADERA;
        cant_gen_maderas --;

    } else if (cant_gen_metales){
        material_a_colocar = METAL;
        cant_gen_metales --;

    } else if (cant_gen_coins){
        material_a_colocar = COINS;
        cant_gen_coins --;
    }

}

void Mapa::mostrar_alerta_materiales_no_colocados(int materiales_restantes, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales,int cant_gen_coins){
    cout <<endl<<"No se pudieron colocar los siguientes " << materiales_restantes
    << " conjuntos porque los casilleros transitables ya estan todos ocupados: "<<endl;
    if (cant_gen_piedras > 0){
        cout<<cant_gen_piedras * UNIDADES_POR_PACK_PIEDRA <<" unidades de piedra"<<endl;
    }
    if (cant_gen_maderas > 0){
        cout<<cant_gen_maderas * UNIDADES_POR_PACK_MADERA <<" unidades de madera" <<endl;
    }
    if (cant_gen_metales > 0){
        cout<<cant_gen_metales * UNIDADES_POR_PACK_METAL <<" unidades de metal " <<endl;
    }
    if (cant_gen_coins > 0){
        cout<<cant_gen_coins * UNIDADES_POR_PACK_COINS <<" unidades de andycoins " <<endl;
    }
}

int Mapa::definir_cantidad_material(string material_a_colocar){
    int cantidad = 0;
    if (material_a_colocar == PIEDRA){
        cantidad = UNIDADES_POR_PACK_PIEDRA;
    } else if (material_a_colocar == MADERA){
        cantidad = UNIDADES_POR_PACK_MADERA;
    }else if (material_a_colocar == METAL){
        cantidad = UNIDADES_POR_PACK_METAL;
    }else if (material_a_colocar == COINS){
        cantidad = UNIDADES_POR_PACK_COINS;
    }
    return cantidad;
}

void Mapa::colocar_materiales_llovidos(int tot_materiales_gen, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales, int cant_gen_coins){

    string material_a_colocar = "";
    int materiales_restantes = tot_materiales_gen;

    while (materiales_restantes > 0 && total_casilleros >0){

        consultar_material_a_colocar(cant_gen_piedras, cant_gen_maderas, cant_gen_metales, cant_gen_coins, material_a_colocar);

        int pos_coordenada =  generar_numero_random( 0, total_casilleros - 1);
        
        int fila =  obtener_casillero_vector_casilleros_lluvia(pos_coordenada) ->obtener_fila() ;
        int columna =  obtener_casillero_vector_casilleros_lluvia(pos_coordenada) ->obtener_columna() ;

        int cantidad = definir_cantidad_material(material_a_colocar);
        mapa[fila][columna] -> agregar_material(material_a_colocar, cantidad);

        cout << "Cayeron " << cantidad << " unidades de " << material_a_colocar << " en " <<"("<< fila << ","  << columna <<")" << endl;

        sacar_casillero(pos_coordenada);

        materiales_restantes --;
    }

    if ( materiales_restantes != 0 ){
        mostrar_alerta_materiales_no_colocados(materiales_restantes, cant_gen_piedras, cant_gen_maderas, cant_gen_metales,cant_gen_coins);
    }

}

Casillero* Mapa::obtener_casillero_vector_casilleros_lluvia ( int pos) {
	return vector_casilleros_lluvia[pos];
}

void Mapa::sacar_casillero(int posicion_numero_a_sacar){
    int nuevo_total = total_casilleros - 1;
    if (total_casilleros > 1) {

        //mando el q quiero elimnar a la ult pos y lo intercambio con ese
        swap_casillero(nuevo_total, posicion_numero_a_sacar);
        
        Casillero **vector_aux_casilleros_lluvia = new Casillero*[nuevo_total];

        for(int i = 0; i < total_casilleros - 1; i++){
            vector_aux_casilleros_lluvia[i] = vector_casilleros_lluvia[i];
            //Como esta en la ult pos nunca lo copio!
        }

        delete vector_casilleros_lluvia[nuevo_total];
        delete[] vector_casilleros_lluvia;

        vector_casilleros_lluvia = vector_aux_casilleros_lluvia;

    }else{
        delete vector_casilleros_lluvia[nuevo_total];
        delete[] vector_casilleros_lluvia;
    }

    total_casilleros --;
}

void Mapa::swap_casillero(int posicion_1, int posicion_2){
    Casillero *aux = vector_casilleros_lluvia[posicion_1];
    vector_casilleros_lluvia[posicion_1] = vector_casilleros_lluvia[posicion_2]; //mando al final (pos_1) el quiero eliminar(pos_2)
    vector_casilleros_lluvia[posicion_2] = aux; //el ultimo lo pongo en donde estaba el que quiero eliminar
}

void Mapa::agregar_casillero_a_vector_casilleros_lluvia (Casillero *casillero, int tam_nuevo, int pos ) {
    
    Casillero** vector_aux = new Casillero*[tam_nuevo];

    for (int i = 0; i<pos; i++){
        vector_aux[i] = vector_casilleros_lluvia[i];
    }

    vector_aux[pos] = casillero;

    if (total_casilleros != 0){
        delete [] vector_casilleros_lluvia;
        }

    total_casilleros = tam_nuevo;
    vector_casilleros_lluvia = vector_aux;
}

void Mapa::cargar_vector_casilleros_lluvia_con_casileros_permitidos(){
    
    int pos = 0;   
    Camino *camino_aux;
    Muelle *muelle_aux;
    Betun *betun_aux;   
    string id_casillero;


    for ( int i = 0; i < cantidad_filas; i++){
        for ( int j = 0; j < cantidad_columnas ; j++){
            id_casillero = std::to_string(i) + std::to_string(j);
            if (mapa[i][j] -> obtener_nombre() =="C" && !( mapa[i][j] -> existe_material() ) ){    
                
                camino_aux  = new Camino (i, j,id_casillero);

                agregar_casillero_a_vector_casilleros_lluvia(camino_aux,pos+1, pos);
                
                pos+=1;
            }else if (mapa[i][j] -> obtener_nombre() =="M" && !( mapa[i][j] -> existe_material() ) ){    
                
                muelle_aux  = new Muelle(i, j,id_casillero);

                agregar_casillero_a_vector_casilleros_lluvia(muelle_aux,pos+1, pos);
                
                pos+=1;
            }else if (mapa[i][j] -> obtener_nombre() =="B" && !( mapa[i][j] -> existe_material() ) ){ 
                
                betun_aux  = new Betun(i, j,id_casillero);

                agregar_casillero_a_vector_casilleros_lluvia(betun_aux,pos+1, pos);
                
                pos+=1;
            }
        }
    }
}

void Mapa::ejecutar_lluvia(int tot_materiales_gen, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales, int cant_gen_coins){

    cargar_vector_casilleros_lluvia_con_casileros_permitidos();

    colocar_materiales_llovidos(tot_materiales_gen, cant_gen_piedras, cant_gen_maderas, cant_gen_metales, cant_gen_coins);
    
    int total_cas = total_casilleros;

    for ( int i = 0; i < total_cas; i++){
        delete vector_casilleros_lluvia[i];
        total_casilleros--;
    }
    if (total_cas !=0){
        delete [] vector_casilleros_lluvia;
        vector_casilleros_lluvia = nullptr;
    }
}

void Mapa::lluvia_recursos(){

    srand( (unsigned)time(0) );

    int cant_gen_piedras = generar_numero_random(1,2); 
    int cant_gen_maderas = generar_numero_random(0,3);
    int cant_gen_metales = generar_numero_random(2,4);
    int cant_gen_coins = generar_numero_random(0,1);
    
    int tot_materiales_gen = cant_gen_piedras + cant_gen_maderas + cant_gen_metales + cant_gen_coins;
    
    cout << "\n\t.:Lluvia de materiales:. \n" << endl;

    cout << "\nHan llovido los siguientes articulos en el mapa: \n" <<endl
    <<cant_gen_piedras * UNIDADES_POR_PACK_PIEDRA <<" unidades de piedra"<<endl
    <<cant_gen_maderas * UNIDADES_POR_PACK_MADERA <<" unidades de madera" <<endl
    <<cant_gen_metales * UNIDADES_POR_PACK_METAL <<" unidades de metal " <<endl
    <<cant_gen_coins * UNIDADES_POR_PACK_COINS << " andycoins" <<endl<<endl
    <<"\nen las siguientes posiciones: "<< endl;
    cout << "_____________________________________________________" << endl;
    ejecutar_lluvia(tot_materiales_gen,cant_gen_piedras, cant_gen_maderas, cant_gen_metales,cant_gen_coins);
    cout << "_____________________________________________________" << endl;


    cout <<endl;
}

// -------------- FINALIZA PUNTOS DEL MENU -------------------------------
void Mapa::guardar_materiales(std::ofstream &archivo_ubicaciones){
    for ( int i = 0; i < cantidad_filas; i++){
            for ( int j = 0; j < cantidad_columnas ; j++){
                if ( mapa[i][j] -> existe_material() ){ 
                    archivo_ubicaciones << mapa[i][j] -> obtener_nombre_material() <<" ("
                    << i << ", " << j << ")" << endl;
                }
            }
    }
    
}

void Mapa::guardar_jugador(std::ofstream &archivo_ubicaciones,int id_jugador){
    for ( int i = 0; i < cantidad_filas; i++){
            for ( int j = 0; j < cantidad_columnas ; j++){
                if ( mapa[i][j] -> existe_jugador() && id_jugador == mapa[i][j] -> devolver_id_jugador() ){ 
                    archivo_ubicaciones << mapa[i][j] -> devolver_id_jugador() <<" ("
                    << i << ", " << j << ")" << endl;
                }
            }
    }
}

void Mapa::guardar_edificios(std::ofstream &archivo_ubicaciones,int id_jugador){
    
    int id_edificio;

    for ( int i = 0; i < cantidad_filas; i++){
        for ( int j = 0; j < cantidad_columnas ; j++){
            if (mapa[i][j] -> existe_edificio() ){
                id_edificio = mapa[i][j]->obtener_edificio_construido() ->devolver_id_jugador();
                if ( id_edificio == id_jugador ){
                    archivo_ubicaciones << mapa[i][j] -> obtener_nombre_edificio() << " ("
                    << i << ", " << j << ")" << endl;
                }
            }
        }
    }
}

Mapa::~Mapa(){

    if (mapa_bien_cargado && ubicaciones_bien_cargadas){
        ofstream archivo_ubicaciones;
        archivo_ubicaciones.open(ARCHIVO_UBICACIONES, std::ios_base::app);

        guardar_materiales(archivo_ubicaciones);
        guardar_jugador(archivo_ubicaciones,1);
        guardar_edificios(archivo_ubicaciones,1);
        guardar_jugador(archivo_ubicaciones,2);
        guardar_edificios(archivo_ubicaciones,2);
        archivo_ubicaciones.close();          
        }
    

    if (mapa_bien_cargado){
        for ( int i = 0; i < cantidad_filas; i++){
            for ( int j = 0; j < cantidad_columnas ; j++){
                
                delete mapa[i][j];
            }
            delete [] mapa[i];
        }
        delete [] mapa;
        this->mapa = 0;
    }

    int total = cantidad_edificios;
    for ( int i = 0; i < total; i++){
        cantidad_edificios--;
    }
}

// ----------------------- MENU PRINCIPAL : -----------------------

// MODIFICAR EDIFICIO 1)
void Mapa::modificar_edificios(){
    string nombre_edificio;
    cout<<"Deci el nombre de un edificio "<<endl;
    cin >> nombre_edificio;
    diccionario -> modificar_datos_edificio(nombre_edificio);
}

// LISTAR TODOS LOS EDIFICIOS 2)
void Mapa::listar_todos_edificios(){
    cout << "\n";
    cout << "\t\t###   Listado de todos los edificios :   ###" << endl;
    cout << "\nOrden de los elementos :  " << endl;
    cout << "\n -> nombre / piedra / madera / metal / cuantos puedo construir " << endl;
    cout << "_________________________________________________________________" << endl;
    this -> diccionario -> mostrar();
    cout << "\n";
}

// MOSTRAR MAPA 3)
void Mapa::mostrar_mapa(){
    cout << " -------------------------------------------------------------------------- " << endl;
    cout << "\n";
    for (int i = 0; i < cantidad_filas ; i++){
        for ( int j = 0; j < cantidad_columnas; j++){
        cout << "  ";
           cout << mapa[i][j]->obtener_nombre()
                << mapa[i][j]->obtener_diminutivo_edificio()
                << mapa[i][j]->obtener_diminutivo_material()
                << mapa[i][j]->obtener_diminutivo_jugador()
                << "\t";
        }
        cout << "\n" << endl;
    }
    cout << "\n";
    cout << " -------------------------------------------------------------------------- " << endl;
    cout << "\n";

}

// COMENZAR PARTIDA 4)
// SE REALIZA DESDE EL MENU

// GUARDAR SALIR 5)
// SE REALIZA DESDE EL MENU 
