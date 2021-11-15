#include <iostream>
#include <fstream>
#include "inventario.h"

const int ERROR = -1;

using namespace std;

const string PATH_MATERIALES = "materiales.txt";

//Constructor de inventario sin parametros
Inventario :: Inventario(){
    
    lista_materiales = 0;
    cantidad_de_materiales = 0;
}


//Obtener cantidad de materiales en lista_materiales
int Inventario :: obtener_cantidad_de_materiales(){
    return cantidad_de_materiales;
}

//Obtener material de lista materiales 
Material* Inventario :: obtener_material_de_lista_materiales(int posicion){
    return lista_materiales[posicion];
}


//cargar materiales
void Inventario :: cargar_materiales(){
    
    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if(archivo_materiales.is_open()){

        string nombre;
        string cantidad;

        Material *material;
        
        while(archivo_materiales >> nombre){
            archivo_materiales >> cantidad;

            material = new Material(nombre, stoi(cantidad) );

            agregar_material(material);
        }

        archivo_materiales.close();
    }
    else{
        cantidad_de_materiales = ERROR; 
    }
} 


//agregar material a la lista de materiales
void Inventario :: agregar_material(Material* material){
    
    int tope_viejo = cantidad_de_materiales;

    Material** nuevo_vector_materiales = new Material*[tope_viejo + 1];

    for(int i = 0; i < cantidad_de_materiales; i++){
        nuevo_vector_materiales[i] = lista_materiales[i];
    }
    
    nuevo_vector_materiales[tope_viejo] = material;

    if(cantidad_de_materiales != 0){
        delete[] lista_materiales;
    }

    lista_materiales = nuevo_vector_materiales;
    cantidad_de_materiales++;
}


//Destructor de inventario
Inventario:: ~ Inventario(){
    
    int cantidad_total = cantidad_de_materiales;
    
    if (cantidad_total != ERROR){
        ofstream archivo_materiales(PATH_MATERIALES);
        for(int i = 0; i < cantidad_total; i++){
            archivo_materiales << lista_materiales[i]->obtener_nombre()<< ' '
            << lista_materiales[i] -> obtener_cantidad_disponible()<< '\n';
        }
    }

        
    for(int i = 0; i < cantidad_total; i++){

        delete lista_materiales[i];
        
        cantidad_de_materiales--;
    }

    delete [] lista_materiales;
    lista_materiales = nullptr;

};


//Mostrar inventario
void Inventario :: mostrar_inventario(){
    cout << setfill(' ') << setw(64)<<"MATERIALES DE CONSTRUCCION"<<"\n\n"
    << setfill(' ') << setw(45) <<"MATERIAL"<< setfill(' ')<<setw(21)<<"CANTIDAD DISPONIBLE"<<endl
    << setfill(' ') << setw(72)<<"__________________________________________" <<endl<<endl;
    
    for(int i = 0; i < cantidad_de_materiales; i++){
        cout<<setfill(' ') << setw(45) << lista_materiales[i] -> obtener_nombre()
        <<setfill(' ') << setw(12) << lista_materiales[i] -> obtener_cantidad_disponible() <<endl;
        }
    
    cout<<endl;   
}; 


//chequar si alcanza material en cuestion
void Inventario :: chequear_material(int cantidad_disponible, int cantidad_material_nec, bool &alcanza){
    if (cantidad_disponible < cantidad_material_nec){
                alcanza = false;
    }
}


//Chequear si alcanzan materiales
bool Inventario :: alcanzan_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int 
cantidad_metal_nec){

    bool alcanza = true;
    int i = 0;
    while (alcanza && i < cantidad_de_materiales){
        
        string material_a_chequear = lista_materiales[i]->obtener_nombre();

        int cantidad_disponible = lista_materiales[i]->obtener_cantidad_disponible();
        
        if (material_a_chequear == PIEDRA){
            chequear_material(cantidad_disponible, cantidad_piedra_nec, alcanza);
        } 
        if (material_a_chequear == MADERA){
            chequear_material(cantidad_disponible, cantidad_madera_nec, alcanza);
        } 
        if (material_a_chequear == METAL){
            chequear_material(cantidad_disponible, cantidad_metal_nec, alcanza);
        } 
        i++;
    }
    return alcanza;
}


//Utilizar materiales
void Inventario:: utilizar_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int 
cantidad_metal_nec){
    
    int i = 0;
    
    while (i < cantidad_de_materiales){
    
        string material_a_chequear = lista_materiales[i] -> obtener_nombre();

        if (material_a_chequear == PIEDRA){
            lista_materiales[i] -> restar_material(cantidad_piedra_nec);
        }
        if (material_a_chequear == MADERA){
            lista_materiales[i] -> restar_material(cantidad_madera_nec);
        } 
        if (material_a_chequear == METAL){
            lista_materiales[i] -> restar_material(cantidad_metal_nec);
        }
        i++;
    }
}



//Devolver materiales
void Inventario :: devolver_materiales(int cantidad_piedra_nec, int cantidad_madera_nec, int 
cantidad_metal_nec){
    
    int i = 0;

    while (i < cantidad_de_materiales){
    
        string material_a_chequear = lista_materiales[i] -> obtener_nombre();
        
        if (material_a_chequear == PIEDRA){
            lista_materiales[i] -> sumar_material(cantidad_piedra_nec);
        }
        if (material_a_chequear == MADERA){
            lista_materiales[i] -> sumar_material(cantidad_madera_nec);        
        } 
        if (material_a_chequear == METAL){
            lista_materiales[i] -> sumar_material(cantidad_metal_nec);
        }
        i++;
    }

};


//Recolectar materiales
void Inventario :: recolectar_materiales(int cantidad_piedra_rec, int cantidad_madera_rec, 
int cantidad_metal_rec){
    
    int i = 0;

    while (i < cantidad_de_materiales){
    
        string material_a_chequear = lista_materiales[i] -> obtener_nombre();
        
        if (material_a_chequear == PIEDRA){
            lista_materiales[i] -> sumar_material(cantidad_piedra_rec);
        }
        if (material_a_chequear == MADERA){
            lista_materiales[i] -> sumar_material(cantidad_madera_rec);        
        } 
        if (material_a_chequear == METAL){
            lista_materiales[i] -> sumar_material(cantidad_metal_rec);
        }
        i++;
    }

}


//Obtener posicion material
int Inventario :: obtener_posicion_material(string material_a_buscar){
    bool encontrado = false;
    int posicion = ERROR;
    int i = 0;
    while (!encontrado && i< cantidad_de_materiales){
        if (lista_materiales[i]->obtener_nombre() == material_a_buscar){
            encontrado = true;
            posicion = i;
        }
        i++;
    }
    return posicion;
}