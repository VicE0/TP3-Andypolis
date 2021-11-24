
#ifndef JUGADOR_H
#define JUGADOR_H

#include "lista.h"
#include "inventario.h"

#include <string>
using std::string;

class Jugador
{

    private:
        int numero_jugador;
        int energia;
        int objetivos_cumplidos;
        int turno;
        //AGREGAR PARTE DE MATERIALES HECHA POR GIAN

        Lista<Material> * inventario;

    public:

        Jugador();

        Jugador(int numero_jugador); //constructor

        //PRE: ~
        //POST: Devuelve el nombre del jugador
        string obtener_nombre();

        //PRE: ~
        //POST: Devuelve el numero del jugador (1 o 2)
        int dar_numero();

        // //PRE: ~
        // //POST: Devuelve TRUE si la energía del jugador es suficiente para realizar la opción
        // bool tiene_energia();


        // //Destructor, seguro lo necesitamos para liberar el inventario
        // ~Jugador();

        void agregar_material(Material * material);

        Material * obtener_material(string nombre);

        void mostrar_cantidad_material( string nombre );

        Lista<Material> * obtener_inventario();


        void establecer_turno(int turno);

        int obtener_turno();
  
        void sumar_cantidad_material(string nombre, int cantidad);

        void restar_cantidad_material(string nombre, int cantidad);

        void mostrar_inventario();

        bool alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza);

        void utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        void devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);


};


#endif //JUGADOR_H

