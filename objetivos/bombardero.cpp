#include "bombardero.h"

Bombardero::Bombardero(int id_objetivo, int cantidad, bool cumplido) : Objetivo(id_objetivo, cantidad, cumplido)
{
    this -> id_objetivo = BOMBARDERO;
    this -> cantidad = 5;
    this -> bombas_usadas = 0;
    this ->cumplido = false;
}

void Bombardero::mostrar_progreso()
{
    cout << "Progreso: " << bombas_usadas << "/" << cantidad << endl;

}


void Bombardero::mostrar_descripcion()
{
    cout << "\nBombardero: haber usado "<< cantidad << " bombas"<<endl;
    mostrar_progreso();
}

void Bombardero::progreso(Lista <Material> * inventario, int &energia, Edificio * edificio_objetivo)
 {
     cout << endl;
 }