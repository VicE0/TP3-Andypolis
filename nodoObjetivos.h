#ifndef NODO_OBJETIVOS_H
#define NODO_OBJETIVOS_H

template <typename Data>

class NodoObjetivos
{

    private:
        // ATRIBUTOS
        Data data;
        NodoObjetivos<Data>* siguiente;
        NodoObjetivos<Data>* anterior;

    public:
        // METODOS

        // CONSTRUCTOR
        NodoObjetivos(Data o); //o de objeto! 

        // PRE: -
        // POST: cambia el nodo siguiente por ps
        void cambiar_siguiente(NodoObjetivos* posicion);

        // PRE: -
        // POST: cambia el nodo anterior por ps
        void cambiar_anterior(NodoObjetivos* posicion);

        // PRE: -
        // POST: devuelve el nodo anterior
        NodoObjetivos* obtener_anterior();

        // PRE: -
        // POST: devuelve el nodo siguiente
        NodoObjetivos* obtener_siguiente();

        // PRE: -
        // POST: devuelve el dato que contiene el nodo
        Data obtener_data();

};

template <typename Data>
NodoObjetivos<Data>::NodoObjetivos(Data o) 
{
    data = o;
    siguiente = 0;
    anterior = 0;
}

template <typename Data>
void NodoObjetivos<Data>::cambiar_siguiente(NodoObjetivos* posicion) 
{
    siguiente = posicion;
}

template <typename Data>
void NodoObjetivos<Data>::cambiar_anterior(NodoObjetivos* posicion) 
{
    anterior = posicion;
}

template <typename Data>
NodoObjetivos<Data>* NodoObjetivos<Data>::obtener_anterior() 
{
    return anterior;
}

template <typename Data>
NodoObjetivos<Data>* NodoObjetivos<Data>::obtener_siguiente() 
{
    return siguiente;
}

template <typename Data>
Data NodoObjetivos<Data>::obtener_data() 
{
    return data;
}

#endif //NODO_OBJETIVOS_H