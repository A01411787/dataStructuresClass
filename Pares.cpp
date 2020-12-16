#include <iostream>
using namespace std;

void llena(int matriz[50][50], int row, int col){
    for (int i = 0; i<row; i++){
        for (int j = 0; j < col; j++){
            cout << "Dame el elemento " <<i<<","<<j<<endl;
            cin >> matriz [i][j];
        }
    }
} 

void mostrar(int matriz[50][50], int row, int col){



	cout <<"La matriz ingresada es: \n";
	
	for (int i = 0; i<row;i++){
	
        for (int j = 0; j < col; j++){
		
            cout <<matriz[i][j]<<"\t";
        }
        cout <<"\n"<<endl;
    }

}

bool Pares(int matriz[50][50], int row, int col, int X){
	int suma;
	int cont = 0;
	
	for (int r = 0; r< row; r++){
		for(int c = 0; c< col-1; c++){
			suma =	matriz[r][c] + matriz[r][c+1];
			if (suma == X){
				cout << "la suma de los valores de los indices ("<<r<<","<<c<<") y ("<<r<<","<<c+1<<") son igual a "<<suma<<endl;
				cont++;
			}	
		}
	}
	
	if (cont == 0){
		cout << "Ninguna suma coincidio con el valor de X";
	}
}

int main(){
	
	// La primera parte del programa se utiliza para llenar la matriz
    int row, col, X;
    cout << "Favor de ingresar el numero de filas de la matriz: " << endl;
    cin >> row; 
    cout << "Favor de ingresar el numero de columnas de la matriz: " << endl;
    cin >> col; 
    
    int matriz[50][50];
    llena(matriz, row, col);
    mostrar(matriz, row, col);
    
    cout << "Favor de ingresar el numero X, : " << endl;
    cin >> X;
    
    Pares(matriz, row, col, X);
    
    // En esta parte llamaremos funciones para 

    return 0;

}
