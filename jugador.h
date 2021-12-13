
#ifndef JUGADOR_H
#define JUGADOR_H

const int ENERGIA_INICIAL = 50;

#include "material.h"
#include "lista.h"
#include "listaObjetivos.h"
#include "edificio.h"
#include "Objetivos.h"
#include "objetivos/comprar_andypolis.h"
#include "objetivos/edad_piedra.h"
#include "objetivos/bombardero.h"
#include "objetivos/energetico.h"
#include "objetivos/letrado.h"
#include "objetivos/minero.h"
#include "objetivos/cansado.h"
#include "objetivos/constructor.h"
#include "objetivos/armado.h"
#include "objetivos/extremista.h"
#include "objetivos/objetivo_obelisco.h"
#include <string>


using std::string;

const int MAX_ENERGIA = 100;

class Jugador
{

    private:
        int id_jugador;
        int energia;
        int energia_recolectada;
        int objetivos_cumplidos;
        int turno;
        Objetivo* objetivo_principal;

        Edificio* edificio_objetivo;

        string diminutivo;

        ListaObjetivos<Objetivo*>  *lista_objetivos;
        Lista<Material> * inventario;
        Lista<Material> * inventario_a_recolectar;

       



    public:

        //CONSTRUCTORES
        //Inicializa la clase del jugador con todos sus valores en 0
        Jugador();

        //PRE:
        //POS:
        Jugador(int id_jugador, string diminutivo); 
        
        // -------------------------------- Funciones jugador --------------------------------
        //PRE: ~
        //POST: Devuelve el numero del jugador (1 / 2)
        int dar_numero();


        Material * obtener_material(string nombre);

        //PRE: Recibe el nombre respectivo del matrerial que se desea recolectar
        //POS: Devuelve un puntero del material al que le pertenece el nombre
        Material * obtener_material_recolectar(string nombre);

        //PRE: ~
        //POS: Devuelve el inventario(lista de materiales) del jugador
        Lista<Material> * obtener_inventario();

        //PRE: ~
        //POS: Devuelve la lista de objetivos del jugador
        ListaObjetivos<Objetivo*> *obtener_lista_objetivos();

        //PRE: ~
        //POS: Devuelve el numero del jugador (1/2)
        int obtener_id();

        //PRE: ~
        //POS: Devuelve la energia del jugador
        int obtener_energia();

        //PRE: Recibe la cantidad que corresponde
        //POS: Suma la energia al jugador
        void sumar_energia(int cantidad);

        //PRE: Recibe la cantidad que corresponde
        //POS: Resta la energia al jugador 
        void restar_energia(int cantidad);

        //PRE: Recibe un puntero al objeto material
        //POS: Agrega el objeto a la lista de materiales (inventario) en la posicion que le corresponde
        void agregar_material(Material * material);

        //PRE:
        //POS:
        void agregar_material_inv_recolectar(Material * material);

        //PRE: Recibe un puntero al objeto objetivo
        //POS: Inserta el objetivo en la ultima posicion de la lista de objetivos
        void agregar_objetivo(Objetivo * objetivo);

        //PRE:
        //POS:
        void mostrar_cantidad_material( string nombre );

        //PRE: ~
        //POS: Devuelve el diminutivo correspondiente del jugador para el mapa
        string obtener_diminutivo();

        //PRE: Recibe un entero
        //POS: Settea el turno al inicio
        void establecer_turno(int turno);

        //PRE: ~
        //POS: Devuelve el turno
        int obtener_turno();

        //PRE:
        //POS: 
        void sumar_cantidad_material(string nombre, int cantidad,bool recolectar);

        //PRE:
        //POS:
        void restar_cantidad_material(string nombre, int cantidad,bool recolectar);

        //PRE: ~
        //POS: Muestra el inventario del jugador
        void mostrar_inventario();

        //PRE: ~
        //POS: Muestra los objetivos del jugador
        void mostrar_objetivos();

        //PRE: ~
        //POS: Muestra los materiales que puede recolectar el jugador
        void mostrar_inventario_recolectar();

        //PRE:
        //POS:
        bool alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        //PRE:
        //POS:
        void chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza);

        //PRE:
        //POS:
        void utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        //PRE:
        //POS:
        void devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec,int cantidad_energia_nec);

        //PRE:
        //POS:
        void devolver_materiales_recolectar(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec, int cantidad_energia_nec);

        //PRE:
        //POS:
        void imprimir_materiales(int piedra_obtenida, int madera_obtenida, int metal_obtenida, int coins_obtenidos,int energia_obtenidos);

        //PRE:
        //POS:       
        void coincidir_valores(int *piedra,int *madera,int *metal,int *coins,string nombre,int cantidad);

        //PRE:
        //POS:      
        void sumar_materiales_recolectados();


        //PRE: ~
        //POS: Crea el array con los objetivos
        Objetivo * sortear_objetivos(int id_objetivo);

        //PRE: ~
        //POS: Crea el array con el obelisco
        Objetivo * asignar_principal(int id_objetivo);

        void actualizar_progreso_objetivos(Edificio* edificio_objetivo);

        //PRE: ~
        //POS: Retorna TRUE si el jugador cumplió 2 de sus 3 objetivos secundarios
        bool objetivos_secundarios_cumplidos();


        bool objetivo_princiapal_cumplido();

        bool gano_juego();


        //DESTRUCTOR
        ~Jugador();

        
};


#endif //JUGADOR_H

