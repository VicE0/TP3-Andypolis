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
    Nodo_ABB(Edificio* d);
    Edificio * obtener_edificio();
    string obtener_clave();
    Nodo_ABB * obtener_der();
    Nodo_ABB * obtener_izq();
    void cambiar_dato(Edificio* d);
    void cambiar_izq(Nodo_ABB * pi);
    void cambiar_der(Nodo_ABB * pd);
    ~Nodo_ABB();
};

#endif //NODO_ABB_H
