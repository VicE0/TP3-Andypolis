
#ifndef JUGADOR_H
#define JUGADOR_H

const int ENERGIA_INICIAL = 50;

#include "material.h"
#include "lista.h"
#include "listaObjetivos.h"
#include "edificio.h"
#include "Objetivos.h"
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
  
    
        string diminutivo;
        
        ListaObjetivos<Objetivo *>  * lista_objetivos;
        Lista<Material> * inventario;


    public:

        // -------------------------------- Constructores --------------------------------
        Jugador();

        Jugador(int id_jugador, string diminutivo); //constructor

        //PRE: ~
        //POST: Devuelve el numero del jugador (1 / 2)
        int dar_numero();

        Material * obtener_material(string nombre);

        Lista<Material> * obtener_inventario();

        //devuelve la lista de objs
        ListaObjetivos<Objetivo*> * obtener_lista_objetivos();
        // -------------------------------- Funciones jugador --------------------------------
        int obtener_energia();

        void sumar_energia(int cantidad);

        void restar_energia(int cantidad);

        void agregar_material(Material * material);

        void agregar_objetivo(Objetivo * objetivo);

        void mostrar_cantidad_material( string nombre );

        string obtener_diminutivo();

        void establecer_turno(int turno);

        int obtener_turno();
  
        void sumar_cantidad_material(string nombre, int cantidad);

        void restar_cantidad_material(string nombre, int cantidad);

        void mostrar_inventario();

        void mostrar_objetivos();

        bool alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza);

        void utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

       

        // void asignar_objetivos(Objetivo* obj);

        // void mostrar_objetivos_jugador();

        // int randomizar_objetivo();


        ~Jugador();

        
};


#endif //JUGADOR_H

