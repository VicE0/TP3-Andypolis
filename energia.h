#ifndef ENERGIA_H
#define ENERGIA_H

class Energia //?
{
    public:
        
        //PRE: ~
        //POST: Verifica si el jugador tiene la cantidad de energia necesaria para la accion
        virtual bool tiene_energia()=0;


        //PRE: ~
        //POST: Consume la energía del jugador
        virtual void consumir_energia()=0;
        

        //PRE: recibe el top de energia
        //POST: si la energía del jugador es igual o mayor al tope, resetea la energía a 0
        virtual void resetear_energia() = 0;

        //Cualquier cosa podemos implementar estos métodos en cada .h


};


#endif //ENERGIA_H