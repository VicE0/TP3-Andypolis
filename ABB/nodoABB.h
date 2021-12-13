#ifndef NODO_ABB_H
#define NODO_ABB_H
#include <string>
#include "../edificio.h"

using namespace std;

class Nodo_ABB
{
private:
    string clave;
    Nodo_ABB * derecho;
    Nodo_ABB * izquierdo;
    Edificio * edificio;


public:
    //Constructoor del nodo
    Nodo_ABB(Edificio* d);

    //PRE:
    //POST: Devuelve el eddificio que se encuentra en dicho nodo
    Edificio * obtener_edificio();

    //PRE:
    //POST: Devuelve la clave del nodo
    string obtener_clave();
    
    //PRE:
    //POST: Obtiene el nodo derecho
    Nodo_ABB * obtener_der();
    
    //PRE:
    //POST:Obtiene el nodo izquierdo
    Nodo_ABB * obtener_izq();
    
    //PRE: Le pido el puntero del nuevo edificio a modificar
    //POST: El nuevo dato del nodo es el edificio pedido
    void cambiar_dato(Edificio* d);

    //PRE: Le pido el puntero del nuevo nodo izquierdo
    //POST: Cambia la posicion izquierdo del nodo
    void cambiar_izq(Nodo_ABB * pi);
    
    //PRE: Le pido el puntero del nuevo nodo derecho
    //POST: Cambia la posicion derecho del nodo
    void cambiar_der(Nodo_ABB * pd);
};

#endif //NODO_ABB_H
