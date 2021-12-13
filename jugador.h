
#ifndef JUGADOR_H
#define JUGADOR_H

const int ENERGIA_INICIAL = 50;

#include "material.h"
#include "lista.h"
#include "edificio.h"
#include "Objetivos.h"
#include <string>
#include <fstream>
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

        // PRE: - 
        // POS: Inicializo los valores en 0 o valores iniciales.
        Jugador();

        // PRE: Le pido el id del jugador y su diminutivo para almacenarlo en su informacion
        // POS: Inicializo los valores correctos del jugador con los datos disponibles
        Jugador(int id_jugador, string diminutivo); 

        // -------------------------------- Funciones jugador --------------------------------
        //PRE: ~
        //POST: Devuelve el numero del jugador (1 / 2)
        int dar_numero();

        //PRE: Le paso el nombre del material a buscar
        //POST: Devuelve el puntero del material buscado
        Material * obtener_material(string nombre);

        //PRE: Le paso el nombre del material a buscar
        //POST: Devuelve el puntero del material buscado en el inventario a recolectar
        Material * obtener_material_recolectar(string nombre);

        //PRE: ~
        //POST: Me devuelve la lista del inventario principal
        Lista<Material> * obtener_inventario();

        
        // -------------------------------- Funciones jugador --------------------------------
        //PRE: ~
        //POST:Devuelve el id del jugador seleccionado
        int obtener_id();

        //PRE: ~
        //POST: Devuelve la energia de dicho jugador
        int obtener_energia();

        //PRE: Le paso un entero de la cantidad a sumar de energia
        //POST: Le suma la energia ingresada al jugador.
        void sumar_energia(int cantidad);

        //PRE: Le paso un entero de la cantidad de energia a restar
        //POST: Le resto la cnatidad brindada de energia
        void restar_energia(int cantidad);

        //PRE: Paso el puntero material paa pasarle la informacion del mismo y poder agregarlo al inventario
        //POST:Doy de alta un material en el inventario del jugador
        void agregar_material(Material * material);

        //PRE: Paso el puntero material paa pasarle la informacion del mismo y poder agregarlo al inventario de recoleccion
        //POST:Doy de alta un material en el inventario del jugador
        void agregar_material_inv_recolectar(Material * material);

        //PRE: Paso el doble puntero objetivo para pasarle la informacion del mismo y poder agregarlo al jugador
        //POST:Doy de alta un objetivo en la lista d eobjetivos del jugador
        void agregar_objetivo(Objetivo ** objetivo);

        //PRE: -
        //POST: Asigno los tres objetivos aleatorios a la lista de objetivos del jugador.
        void asignar_objetivos();

        //PRE: Le paso el string del nombre del material a buscar
        //POST: Imprime por pantalla la cantidad de dicho material.
        void mostrar_cantidad_material( string nombre );

        //PRE: -
        //POST: Obtengo el diminutivo del jugador.
        string obtener_diminutivo();

        //PRE: Le paso el entero del turno
        //POST: Establezco el turno en la informacion del jugador
        void establecer_turno(int turno);

        //PRE: -
        //POST: Me devuleve el turno del jugador
        int obtener_turno();
  
        //PRE: Le pido el nombre del material a modificar, la cantidad a sumar y el booleano para ver en que inventario almacenar.
        //POST: Me suma la cantidad pedida del material pedido. Si recolectar es verdadero, modifica la cantidad del inventario; de lo contrario, lo almacena en el inventario que no fue recolectado
        void sumar_cantidad_material(string nombre, int cantidad,bool recolectar);

        //PRE: Le pido el nombre del material a modificar, la cantidad a restar y el booleano para ver en que inventario almacenar.
        //POST: Me Resta la cantidad pedida del material pedido. Si recolectar es verdadero, modifica la cantidad del inventario; de lo contrario, lo almacena en el inventario que no fue recolectado 
        void restar_cantidad_material(string nombre, int cantidad,bool recolectar);

        //PRE: -
        //POST: Muetsra por pantalla el inventario.
        void mostrar_inventario();

        //PRE: -
        //POST: Muestra por pantalla los objetivos del jugador
        void mostrar_objetivos();

        //PRE: -
        //POST: Muestra por pantalla el inventario a recolectar.
        void mostrar_inventario_recolectar();

        //PRE: Le paso las cantidades de los materiales necesarios para la construccion de dicho edificio
        //POST: Devuelve un bool para verificar si se puede construir dicho edificio con los materiales actuales
        bool alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        //PRE: Le paso el entero de la cantidad disponible, y la necesaria y un puntero del booleano que cambia si no alcanzan.
        //POST: Verifica si la cantidad disponible es mayor a la necesitada y modifica el booleano en base a eso
        void chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza);

        //PRE: Le ingreso las cantidades a restar de los materiales para la construccion
        //POST: Me modifica las cantidades de los materiales en el inventario en base a los parametros ingresados
        void utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec);

        //PRE: Le ingreso las cantidades a sumar de los materiales recolectados
        //POST: Me modifica las cantidades de los materiales en el inventario en base a los parametros ingresados
        void devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec,int cantidad_energia_nec);

        //PRE: Le ingreso las cantidades a sumar de los materiales recolectados
        //POST: Me modifica las cantidades de los materiales en el inventario a recolectar en base a los parametros ingresados
        void devolver_materiales_recolectar(int cantidad_piedra_nec, int cantidad_madera_nec, int cantidad_metal_nec,int cantidad_coins_nec, int cantidad_energia_nec);

        //PRE: Le paso como parametro las cantidades obtenidas de los materiales
        //POST: Imprime por pantalla los materiales con las cantidades ingresadas
        void imprimir_materiales(int piedra_obtenida, int madera_obtenida, int metal_obtenida, int coins_obtenidos,int energia_obtenidos);

        //PRE: Le paso un puntero de cada material para pasarle la cantidad a dicho puntero en base al nombre ingresado
        //POST: Relaciono las cantidades con el nombre y las almaceno en los punteros recibidos
        void coincidir_valores(int *piedra,int *madera,int *metal,int *coins,string nombre,int cantidad);

        //PRE: -
        //POST: Sumo los materiales del inventario a recolectar al inventario del jugador y dejo el inventario a recolectar en 0.
        void sumar_materiales_recolectados();

        //PRE: Le paso el id el objetivo que le toco aleatoriamente
        //POST: Inicializo el objetivo asignado al jugador en la lista de objetivos
        void sortear_objetivos(int id_objetivo);

        void saludar();

        void agregar_codigo_posicion(string codigo_posicion);

        string obtener_codigo_posicion();

        void vaciar_inventario();

        //Destructor de jugador
        ~Jugador();

        
};


#endif //JUGADOR_H

