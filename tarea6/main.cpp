#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h> 
#include <vector>
#include <sstream>

//JOSÉ DE JESÚS BERNAL MERCADO A01411787 Ing. Sistemas Digitales y Robótica
//Estructura de datos - Tarea 6 

//Este programa sirve para implementar diferentes operaciones a vectores
//La primera línea de entrada contiene un número entero T que indica el número de casos de prueba. 
//Luego siguen los casos de prueba T. La primera línea de entrada contiene un entero Q que indica el número de consultas. 
//Luego, en la siguiente línea, están Q consultas separadas por espacios.
//Una consulta puede ser de cinco tipos:

//1. a x (agrega un elemento x al vector A al final)
//2. b (Ordena el vector A en orden ascendente)
//3. c (invierte el vector A)
//4. d (imprime el tamaño del vector)
//5. e (imprime valores separados por espacios del vector)
//5. f (Ordena el vector A en orden descendente)



using namespace std;

void agrega_valor(vector<int> &vec, int val ){  //FUNCION PARA AGREGAR VALOR
	
	vec.push_back(val);

}

void printVector(vector <int> &vec){           //FUNCION PARA IMPRIMIR EL VECTOR
	
	vector <int> :: iterator x;
    for (x = vec.begin(); x != vec.end(); x++){
    	cout<< *x << " ";
	}
	
}

void ascendente(vector <int> &arr) {      //FUNCION PARA ORDENAR EL VECTOR DE FORMA ASCENDENTE
  
    int i, j, min_idx;  
    int n = arr.size();
  
    for (i = 0; i < n -1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j <n; j++) {
        	if (arr[j] < arr[min_idx])   
            min_idx = j;  
            
		}
        
		int temp = arr[min_idx];  
    	arr[min_idx] = arr[i];  
    	arr[i]= temp;  
    	
    }  
} 

void descendente(vector <int> &arr){   //FUNCION PARA ORDENAR EL VECTOR DE FORMA DESCENDENTE
    int i, j, min_idx;  
    int n = arr.size();
  
    for (i = 0; i < n -1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j <n; j++) {
        	if (arr[j] > arr[min_idx])   //Encuentro el elemento mínimo del array
            min_idx = j;  
            
		}
        
		int temp = arr[min_idx];  
    	arr[min_idx] = arr[i];  
    	arr[i]= temp;  
    	
    }  
} 

void invertir(vector <int> &vector){    //FUNCION PARA INVERTIR EL ARRAY
	
	int limite = vector.size();
	
	for (int i=0;i<limite/2;i++) // limite/2 es una recta que se parte en dos, la cual el intercambio de extremos se da por un axuliar.
	{
		int temp = vector[i]; // Temp = auxiliar, el auxiliar toma el valor de vector inicial.
		vector[i] = vector[limite-1 -i]; //El vector inicial toma el valor enésima del vector.
		vector[limite-1 -i] = temp; // El vector inicial toma el valor de temp = auxiliar.
	}	

	
}

void size(vector <int>&vec){  //FUNCION PARA IMPRIMIR EL TAMAÑO DEL ARRAY
	cout <<vec.size()<<" ";
}
	

int main(){ //PROGRAMA PRINCIPAL

	char fileName[256];
	int prueba, consulta;
	int val;
	string line;
	cout << "Favor de ingresar el nombre del archivo: " << endl; //OBTENEMOS EL NOMBRE DEL DOCUMENTO
    cin >> fileName; 
    int cont;

	ifstream archivo;
	archivo.open(fileName); //ABRIENDO EL ARCHIVO    
	
	
	archivo >> prueba;
	for (int i = 0; i < prueba; i++){   //CICLO PARA NUMERO DE PRUEBAS
		vector <int> vec;
		archivo >> consulta;   //SE LEE EL NUMERO DE CONSULTA
		for (int j = 0; j < consulta; j++) { //CICLO PARA EL NUMERO DE CONSULTAS
		
			archivo >> line;
			if (line == "a"){        //SE MANDA A LLAMAR LA FUNCIÓN "agrega_valor()", DONDE AGREGA UN ELEMENTO AL VECTOR AL FINAL
				archivo >> val;
				agrega_valor(vec,val);
			}
			else if(line == "b"){    //SE MANDA A LLAMAR LA FUNCIÓN "ascendente()", DONDE SE ORDENA EL VECTOR DE FORMA ASCENDENTE
				ascendente(vec);
			}
			else if(line == "c"){   //SE MANDA A LLAMAR LA FUNCIÓN "invertir()", DONDE SE ORDENA INVIERTE EL VECTOR 
				invertir(vec);
			}
			else if(line == "d"){   //SE MANDA A LLAMAR LA FUNCIÓN "size()", PARA IMPRIMIR EL TAMAÑO DEL VECTOR
				size(vec);
			}
			else if(line == "e"){   //SE MANDA A LLAMAR LA FUNCIÓN "printVector()", DONDE SE IMPRIMEN LOS VALORES DEL VECTOR
				printVector(vec);
			}
			else if(line == "f"){   //SE MANA A LLAMAR LA FUNCIÓN "descendente()", DONDE SE ORDENEN EL VECTOR DE FORMA DESCENDENTE
				descendente(vec);
			}
			
		}
		cout<<endl;
	}
	
}
