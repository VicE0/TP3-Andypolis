#include "material.h"
#include <iostream>
// #include <cctype>

Material :: Material(string nombre, int cantidad){
  this-> nombre = nombre;
  this-> cantidad = cantidad;

  if (nombre == "piedra"){
    this -> diminutivo = "S";    
  }
  else if (nombre == "madera"){
    this -> diminutivo = "W";
  }
  else if (nombre == "metal"){
    this -> diminutivo = "I";
  }
  else{
    // int letra  = toupper(nombre[0]);
    // char ascii_inicial = char(letra);
    // string letra_inicial = string(1,ascii_inicial);
    // this ->diminutivo = letra_inicial;
    this -> diminutivo = "mat";
  }

}

Material :: ~Material(){

  }

string Material :: obtener_nombre(){ 
  
  return nombre;
}

string Material :: obtener_diminutivo(){ 

  return diminutivo;
}

int Material :: obtener_cantidad_disponible(){
  
  return cantidad;
}


void Material :: restar_material(int cantidad_material_nec){
  cantidad =  cantidad - cantidad_material_nec;
    
}

void Material :: sumar_mitad_material(int cantidad_material_nec){
    
  cantidad =  cantidad + cantidad_material_nec/2;   //truncado (redondeo hacia abajo)
                       
}


void Material :: sumar_material(int cantidad_material_recolectado){
    
  cantidad =  cantidad + cantidad_material_recolectado;   //truncado (redondeo hacia abajo)
                       
}

void Material :: mostrar_nombre(){
  
  cout << nombre;
}

void Material :: mostrar_cantidad(){
  
  cout << cantidad;
}

void Material :: saludar(){
  cout << " Soy un/a "<< nombre << " y estoy en un casillero transitable" <<endl;
}