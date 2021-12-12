#include "constructor.h"

Constructor::Constructor(int id_objetivo,int cantidad, bool cumplido) : Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = CONSTRUCTOR;
    this -> cantidad = 6; //cantidad de edificios diferentes (sin contar obelisco)
    this -> cumplido = false;
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

void Constructor::progreso(Lista <Material> *inventario, int &energia)
 {
     cout << endl;
 }

//linkear con edificios ;-;