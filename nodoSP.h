#ifndef NODO_SP_H
#define NODO_SP_H

template <typename Data>

class NodoSP
{

    private:
        // ATRIBUTOS
        Data data;
        NodoSP<Data>* siguiente;
        NodoSP<Data>* anterior;

    public:
        // METODOS

        // CONSTRUCTOR
        NodoSP(Data o); //o de objeto! 

        // PRE: -
        // POST: cambia el nodo siguiente por ps
        void cambiar_siguiente(NodoSP* posicion);

        // PRE: -
        // POST: cambia el nodo anterior por ps
        void cambiar_anterior(NodoSP* posicion);

        // PRE: -
        // POST: devuelve el nodo anterior
        NodoSP* obtener_anterior();

        // PRE: -
        // POST: devuelve el nodo siguiente
        NodoSP* obtener_siguiente();

        // PRE: -
        // POST: devuelve el dato que contiene el nodo
        Data obtener_data();

};

template <typename Data>
NodoSP<Data>::NodoSP(Data o) 
{
    data = o;
    siguiente = 0;
    anterior = 0;
}

template <typename Data>
void NodoSP<Data>::cambiar_siguiente(NodoSP* posicion) 
{
    siguiente = posicion;
}

template <typename Data>
void NodoSP<Data>::cambiar_anterior(NodoSP* posicion) 
{
    anterior = posicion;
}

template <typename Data>
NodoSP<Data>* NodoSP<Data>::obtener_anterior() 
{
    return anterior;
}

template <typename Data>
NodoSP<Data>* NodoSP<Data>::obtener_siguiente() 
{
    return siguiente;
}

template <typename Data>
Data NodoSP<Data>::obtener_data() 
{
    return data;
}

#endif //NODO_SP_H