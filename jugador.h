
#ifndef JUGADOR_H
#define JUGADOR_H

const int ENERGIA_INICIAL = 50;

#include "lista.h"
#include "inventario.h"

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

        // -------------------------------- Funciones jugador --------------------------------
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

        ~Jugador();

        
};


#endif //JUGADOR_H

