
#ifndef JUGADOR_H
#define JUGADOR_H

const int ENERGIA_INICIAL = 50;

#include "material.h"
#include "lista.h"
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
#include <string>

using std::string;

const int MAX_ENERGIA = 100;

class Jugador
{

    private:
        int id_jugador;
        int energia;
        int objetivos_cumplidos;
        int turno;
        int objetivo_principal;
        int cantidad_objetivos;
        string diminutivo;
        Objetivo * objetivos;
        Lista <Material> * inventario;


    public:

        // -------------------------------- Constructores --------------------------------
        Jugador();

        Jugador(int id_jugador, string diminutivo); //constructor

        // -------------------------------- Funciones jugador --------------------------------
        //PRE: ~
        //POST: Devuelve el numero del jugador (1 / 2)
        int dar_numero();

        Material * obtener_material(string nombre);

        Lista<Material> * obtener_inventario();

        int obtener_id();

        int obtener_energia();

        void sumar_energia(int cantidad);

        void restar_energia(int cantidad);

        void agregar_material(Material * material);

        void mostrar_cantidad_material( string nombre );

        string obtener_diminutivo();

        void establecer_turno(int turno);

        int obtener_turno();

        void sumar_cantidad_material(string nombre, int cantidad);

        void restar_cantidad_material(string nombre, int cantidad);

        void mostrar_inventario();

        bool alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza);

        void utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void cargar_objetivos();

        void mostrar_objetivos_jugador();

        int randomizar_objetivo();


        ~Jugador();

        
};


#endif //JUGADOR_H

