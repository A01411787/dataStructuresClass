#include <iostream>
#include "Complejo.h"

using namespace std;

int main(){ 	
	
	double Re1, Img2, Re2, Img1;
	int op;
	
	cout << "Ingresa la parte real del número 1: " << endl; //OBTENEMOS EL NOMBRE DEL DOCUMENTO
    cin >> Re1; 
    
    cout << "Ingresa la parte Imaginaria del número 1: " << endl; //OBTENEMOS EL NOMBRE DEL DOCUMENTO
    cin >> Img1; 
    
    cout << "Ingresa la parte real del número 1: " << endl; //OBTENEMOS EL NOMBRE DEL DOCUMENTO
    cin >> Re2; 
    
    cout << "Ingresa la parte real del número 1: " << endl; //OBTENEMOS EL NOMBRE DEL DOCUMENTO
    cin >> Img2; 
    
    Complejo num1(Re1, Img1 );
    Complejo num2(Re2, Img2 );
    Complejo num3;
    num3.show_num();
    
   	cout << "Indica la operación que quieres hacer:\n1.- Suma\n2.- Resta\n3.-Multiplicacion\n4.- División\n5.-Igualdad\n" <<endl;
   	cin >> op;
   	num1.show_num();
   	num2.show_num();
   	
   	if (op == 1){
   		 Complejo res = num1 + num2;
   		 res.show_num();
	   }
	else if (op == 2){
		Complejo res = num1 - num2;
		res.show_num();
	}
	else if (op == 3){
		Complejo res = num1 * num2;
		res.show_num();
	}
	
	else if (op == 4){
		Complejo res = num1 / num2;
		res.show_num();
	}
	
	else if (op == 5){
		bool res = num1 == num2;
		if (res == 1){
			
			cout << "Son iguales" <<endl;
		}
		else{
			cout << "No son iguales" <<endl;
		}
	}
    return 0;
}
