#include "constructor.h"

Constructor::Constructor(int id_objetivo,int cantidad) :Objetivo(id_objetivo,cantidad)
{
    this -> id_objetivo = CONSTRUCTOR;
    this -> cantidad = 6; //cantidad de edificios diferentes (sin contar obelisco)
}

void Constructor::mostrar_progreso()
{
    cout << "Progreso: " << andycoins_totales << "/" << cantidad << endl;

}

void Constructor::mostrar_descripcion()
{
    cout << "\nConstructor: haber construido un edificio de cada tipo "<<endl;
    mostrar_progreso();
}



//linkear con edificios ;-;