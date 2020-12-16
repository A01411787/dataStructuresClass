#include <iostream>

//Se dice que una matriz es escalar si todos los elementos de la diagonal principal son iguales.

// DEFINICIÓN DE INTERNET:
//Una Matriz Escalar es aquella matriz diagonal en la que todos los elementos de la diagonal principal tienen el mismo valor. 
//Recordar que una matriz diagonal es aquella matriz cuadrada que tiene todos sus valores iguales a cero excepto los de su diagonal principal.
//Fuente: https://www.matematicas10.net/2015/12/ejemplos-de-matriz-escalar.html


using namespace std;

void llena(int matriz[50][50], int dim){
    for (int i = 0; i<dim; i++){
        for (int j = 0; j < dim; j++){
            cout << "dame el elemento" <<i<<","<<j<<endl;
            cin >> matriz [i][j];
        }
    }
}

void mostrar(int matriz[50][50], int dim){

	cout <<"La matriz ingresada es: \n";
	
	for (int i = 0; i<dim; i++){
        for (int j = 0; j < dim; j++){
            cout <<matriz[i][j]<<"\t";
        }
        cout <<"\n"<<endl;
    }

}

bool Calcula(int matriz[50][50], int dim){ 
	
	int num;
	num = matriz[0][0];
	
	for (int row = 0; row<dim; row++){
		for(int col = 0; col < dim; col++){
			if (row == col && matriz[row][col] != num){  			//Aqui verificamos el caso en que los indices son iguales y comparamos que 
				//cout << "Error en el indice" <<row<<","<<col<<endl; //todos los valores de la diagonal sean iguales 
				return false;
				break;	
			}
			else if(row != col && matriz[row][col] != 0){			//Aqui verificamos el caso de los valores que no estan en la diagonal y comparamos
				//cout << "Error en el indice" <<row<<","<<col<<endl; //para asegurarnos que sean igual a 0
				return false;
				break;
			}
		}
	}
	
	return true;
}


int main(){
	
	// La primera parte del programa se utiliza para llenar la matriz
    int dim;
    cout << "Favor de ingresar la dimension de la matriz" << endl;
    cin >> dim; 
    int matriz[50][50];
    llena(matriz, dim);
    mostrar(matriz, dim);
    
    // En esta parte llamaremos funciones para 
    
    if (Calcula(matriz, dim))
    	cout << "la matriz cuadrada es escalar";

    else
       	cout << "la matriz cuadrada no es escalar";

    return 0;

}

