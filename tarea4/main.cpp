//José de Jesús Bernal Mercado 
//A01411787

//DESCRIPCIÓN DEL PROGRAMA:

//Este programa recibe como entrada una lista de productos con 3 columnas. Nombre, Contenido, Calorias
// El programa tiene que ordenar la lista primero por nombre, después por contenido y después por calorias
// Al principio del programa se pide el nombre del archivo a leer, se muestra en pantalla la lista antes de
//ordenarla y después de ordenarla. 

#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h> 
#include "Producto.h"

using namespace std;

void selectionSort(Producto arr[], int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++) {
        	if (arr[j].get_title() < arr[min_idx].get_title())   //Encuentro el elemento mínimo del array
            min_idx = j;  
            
            else if (arr[j].get_title() == arr[min_idx].get_title()){ //Si los elementos Nombre son iguales entonces checa el contenido
        		if (arr[j].get_contenido() < arr[min_idx].get_contenido()){
        			min_idx = j;
				}
				else if (arr[j].get_contenido() == arr[min_idx].get_contenido()){ //Si los elementos Contendio son iguales entonces checa Calorias
					if (arr[j].get_calorias() < arr[min_idx].get_calorias()){
						min_idx = j;
					}
				}
			}
		}
        
		Producto temp = arr[min_idx];  
    	arr[min_idx] = arr[i];  
    	arr[i]= temp;  
    	
    }  
} 


void creando_objetos(ifstream & archivo, int cont, Producto productos[]){
	
	string nombre;
	int calorias, gramos;
	for(int i=0; i<cont; i++){
		
		archivo>>nombre>>gramos>>calorias;

		productos[i].add_name(nombre); 			//ASIGNO EL NOMBRE DEL PRODUCTO 
		productos[i].add_contenido(gramos);		//ASIGNO LA CANTIDAD DE GRAMOS
		productos[i].add_calorias(calorias);	//ASIGNO LA CANTIDAD DE CALORIAS
	}

}

void mostrar_datos(Producto productos[], int cont){
	
	for(int i=0; i<cont; i++){
		string name = productos[i].get_title();
		int contenido = productos[i].get_contenido();
		int calorias = productos[i].get_calorias();
		cout << name <<" "<< contenido << " "<< calorias<<" "<<endl;	
	}
	
}
//ESTA ES EL PROGRAMA PRINCIPAL /////////////////////////////////////////////

int main(){
	
	char fileName[256];
	cout << "Favor de ingresar el nombre del archivo: " << endl; //OBTENEMOS EL NOMBRE DEL DOCUMENTO
    cin >> fileName; 
	
	int cont;
	
	ifstream archivo;
	archivo.open(fileName); //ABRIENDO EL ARCHIVO
	archivo >> cont;
	//cout << cont<<endl;
	cout <<"\nHay "<<cont<<" elementos en el archivo"<<endl;
	
	Producto productos[cont]; //DECLARO MI ARRAY DE OBJETOS
	
	creando_objetos(archivo, cont, productos); //LLENO MI ARREGLO CON LOS OBJETOS
	cout <<"\nArreglo antes del ordenamiento: \n"<<endl;
	mostrar_datos(productos, cont);//<--- Muestro el array
	
	selectionSort(productos, cont);  //ORDENAMIENTO DE NOMBRES
									   
	cout <<"\nArreglo despues del ordenamiento: \n"<<endl;
	mostrar_datos(productos, cont);//<--- Muestro el array
	cout <<"\n"<<endl;

	//PROCEDO A ORDENAR
	
	archivo.close()	;	//CERRANDO EL ARCHIVO
	system("pause");

}

