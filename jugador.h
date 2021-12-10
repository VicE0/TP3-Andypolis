
#ifndef JUGADOR_H
#define JUGADOR_H

const int ENERGIA_INICIAL = 50;

#include "material.h"
#include "lista.h"
#include "listaObjetivos.h"
#include "edificio.h"
#include "Objetivos.h"
#include <string>
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
        string codigo_posicion;
    
        string diminutivo;

        Lista<Objetivo*> * lista_objetivos;
        Lista<Material> * inventario;
        Lista<Material> * inventario_a_recolectar;


    public:

        // -------------------------------- Constructores --------------------------------
        Jugador();

        Jugador(int id_jugador, string diminutivo); //constructor

        // -------------------------------- Funciones jugador --------------------------------
        //PRE: ~
        //POST: Devuelve el numero del jugador (1 / 2)
        int dar_numero();

        Material * obtener_material(string nombre);

        Material * obtener_material_recolectar(string nombre);

        Lista<Material> * obtener_inventario();

        
        // -------------------------------- Funciones jugador --------------------------------
        int obtener_id();

        int obtener_energia();

        void sumar_energia(int cantidad);

        void restar_energia(int cantidad);

        void agregar_material(Material * material);

        void agregar_material_inv_recolectar(Material * material);

        void agregar_objetivo(Objetivo ** objetivo);

        void asignar_objetivos();

        void mostrar_cantidad_material( string nombre );

        string obtener_diminutivo();

        void establecer_turno(int turno);

        int obtener_turno();
  
        void sumar_cantidad_material(string nombre, int cantidad,bool recolectar);

        void restar_cantidad_material(string nombre, int cantidad,bool recolectar);

        void mostrar_inventario();

        void mostrar_objetivos();

        void mostrar_inventario_recolectar();

        bool alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza);

        void utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec,int cantidad_energia_nec);

        void devolver_materiales_recolectar(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec, int cantidad_energia_nec);

        void imprimir_materiales(int piedra_obtenida, int madera_obtenida, int metal_obtenida, int coins_obtenidos,int energia_obtenidos);
        
        void coincidir_valores(int *piedra,int *madera,int *metal,int *coins,string nombre,int cantidad);
        
        void sumar_materiales_recolectados();

        void sortear_objetivos(int id_objetivo);

        void saludar();

        void agregar_codigo_posicion(string codigo_posicion);

        string obtener_codigo_posicion();

        ~Jugador();

        
};


#endif //JUGADOR_H

