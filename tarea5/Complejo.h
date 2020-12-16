#include <iostream>
#include <cmath>
using namespace std;

class Complejo {
	//INICIO DE LA CLASE COMPLEJO
	
private:
	    double Re, Img;  //DECLARACIÓN DE LOS ATRIBUTOS RE E IMG
public:
	
		
    Complejo(){ //constructor sin parámetros
        this->Re = 0;
        this->Img = 0;
    }
    
    Complejo(const double Re,const double Img){ // constructor parametrizado
        this->Re = Re;
        this->Img = Img;
    }
    
    void show_num(){  //MÉTODO PARA MOSTRAR EL NÚMERO COMPLEJO EN PANTALLA
    	cout << Re << "+" <<Img << "i" <<endl;
	}
		
		
	// SOBRECARGA DEL OPERADOR +
	Complejo operator +(const Complejo &num){
		
	    Complejo resultado;
	    resultado.Re = this->Re + num.Re;
	    resultado.Img = this->Img + num.Img;
	    cout <<"entro a la parte operador"<<endl;
	    return resultado;
	}
	
	// SOBRECARGA DEL OPERADOR -
	Complejo operator -(const Complejo &num){
		
		Complejo resultado;
	    resultado.Re = this ->Re - num.Re;
		resultado.Img = this->Img - num.Img;
	    return resultado;
	}
	
	// SOBRECARGA DEL OPERADOR *
	Complejo operator *(const Complejo &num){
		
		Complejo resultado;
	    resultado.Re = this->Re*num.Re - this->Img*num.Img;
		resultado.Img = this->Re*num.Img + this->Img*num.Re ;
	    return resultado;
	}
	
	// SOBRECARGA DEL OPERADOR /
	Complejo operator /(const Complejo &num){
		
		Complejo resultado;
	    resultado.Re = (this->Re*num.Re + this->Img*num.Img)/(pow(num.Re, 2)+ pow(num.Img, 2));
		resultado.Img = (-this->Re*num.Img + this->Img*num.Re )/(pow(num.Re, 2)+ pow(num.Img, 2));
	    return resultado;
	}
	
	//Sobrecarga del operador ==
	bool operator ==(const Complejo &num){
		
    	if (this->Re == num.Re && this->Img == num.Img){
    	return true;
		}
		else{
		return false;
		}
    
	}

	
};



