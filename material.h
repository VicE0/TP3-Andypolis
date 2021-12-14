#ifndef MATERIAL_H
#define MATERIAL_H

#include<iostream>
#include<string>


using namespace std;


class Material{

private:

    string nombre;
    int cantidad;
    string diminutivo;
    int bombas_compradas;
    int bombas_usadas;
    int andycoins_totales;

public:

    //Constructor de material con 2 parametros
    //PRE:-
    //POST: Construye un material sin parametros
    Material(string nombre, int cantidad);

    virtual ~Material();

    //Obtener nombre
    //PRE: -
    //POST: Devuelve un string con el nombre del material
    string obtener_nombre();
    
    //Obtener diminutivo
    //PRE: -
    //POST: Devuelve un string con el diminutivo del material (diminutivo = primer letra del material)
    string obtener_diminutivo();

    //Obtener cantidad
    //PRE: -
    //POST: Devuelve un enetro con la cantidad disponible del material 
    int obtener_cantidad_disponible();
    
    //Restar material
    //PRE: Recibe un entero con la cantidad de material que es necesario restar
    //POST: Actualiza la cantiad de material disponible con el valor luego de la resta
    void restar_material(int cantidad_material_nec);

    //Sumar mitad material
    //PRE: Recibe el entero "cantidad_material_nec" con la cantidad de material necesaria para la 
    //construccion.
    //POST: Suma en la lista de materiales, al material en cuestion la mitad de los necesarios para 
    //la construccion.
    void sumar_mitad_material(int cantidad_material_nec);
    
    //Sumar material
    //PRE: Recibe el entero "cantidad_material_recolectado" con la cantidad de material que se desea sumar.
    //POST: Suma en la lista de materiales, al material encuestion dicho entero.
    void sumar_material(int cantidad_material_recolectado);

    //Asignar valores al material
    //PRE: Recibe el string "nombre" con el nombre del material y el entero "cantidad" con la cantidad de dicho material
    //POST: Asigna los valores anteriores a nombre y cantidad respectivamente
    void asignar_valores(string nombre, int cantidad);

    //Mostrar nombre material
    //PRE:-
    //POST: Muestra el nombre del material
    void mostrar_nombre();

    //Mostrar cantidad material
    //PRE:-
    //POST: Muestra la cantiad del material
    void mostrar_cantidad();
    
    //PRE:-
    //POST: Le muestra por pantalla un mensaje al jugador explicando que es.
    void saludar();

    //PRE:-
    //POST: Reduce la cantidad del material a 0.
    void vaciar();

    //PRE:-
    //POST: obtiene el atributo bombas compradas.
    int obtener_bombas_compradas();

    //PRE: recibe un entero cantidad
    //POST: suma las bombas compradas.
    void sumar_bombas_compradas(int cantidad);

    //PRE:-
    //POST: obtiene el atributo bombas usadas.
    int obtener_bombas_usadas();

    //PRE: recibe un entero cantidad
    //POST: suma las bombas usadas
    void sumar_bombas_usadas(int cantidad);

    //PRE:-
    //POST: obtiene el atributo andycoins totales.
    int obtener_andycoins_totales();

    //PRE:recibe una cantidad
    //POST: suma las andycoins.
    void sumar_andycoins_totales(int cantidad);

};


#endif // MATERIAL_H_INCLUDED