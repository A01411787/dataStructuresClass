#include <iostream>

using namespace std;

class Producto { //CLASE PRODUCTO QUE CONTIENE EL NOMBRE, CONTENIDO Y CALORIAS DE LOS PRODUCTOS DE LA LISTA 
	
	string nombre;
	int contenido;
	int calorias;
	
	public:
		
		Producto(){
			nombre = "";
			contenido=0;
			calorias =0;
		}
		
		Producto(string new_name, int content, int calr){
			nombre = new_name;
			contenido = content;
			calorias = calr;
		}
	
		void add_name(string new_name){ nombre = new_name;};
		string get_title(){ return nombre;};
		
		void add_contenido(int content){ contenido = content;};
		int get_contenido(){return contenido;};
		
		void add_calorias(int calr){ calorias = calr;};
		int get_calorias(){ return calorias;};
};

