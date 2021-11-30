
#ifndef JUGADOR_H
#define JUGADOR_H

const int ENERGIA_INICIAL = 50;

#include "material.h"
#include "lista.h"
#include "edificio.h"
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
        string diminutivo;
        Lista<Material> * inventario;
        Lista<Material> * inventario_a_recolectar;

    public:

        // -------------------------------- Constructores --------------------------------
        Jugador();

        Jugador(int id_jugador, string diminutivo); //constructor

        //PRE: ~
        //POST: Devuelve el numero del jugador (1 / 2)
        int dar_numero();

        Material * obtener_material(string nombre);
        Material * obtener_material_recolectar(string nombre);

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
  
        void sumar_cantidad_material(string nombre, int cantidad,bool recolectar);

        void restar_cantidad_material(string nombre, int cantidad,bool recolectar);

        void mostrar_inventario();

        bool alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza);

        void utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec,int cantidad_energia_nec);

        void devolver_materiales_recolectar(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec, int cantidad_energia_nec);

        void imprimir_materiales(int piedra_obtenida, int madera_obtenida, int metal_obtenida, int coins_obtenidos,int energia_obtenidos);
        
        void coincidir_valores(int *piedra,int *madera,int *metal,int *coins,string nombre,int cantidad);
        
        void sumar_materiales_recolectados();

        ~Jugador();

        
};


#endif //JUGADOR_H

