#include <iostream>
#include "LinkedList.h"
//José de Jesús Bernal Mercado A01411787
//Creación de métodos Reverse, Delete, Shift, +=, ==

using namespace std;

int main(){
	
    LinkedList <int> L;  //Crear una lista de enteros
    LinkedList <int> L1;
    LinkedList <int> L2;
    
    L1.addLast(1);
    L1.addLast(2);
    L1.addLast(3);
    L1.addLast(9);
    
    L2.addLast(1);
    L2.addLast(2);
    L2.addLast(3);
    L2.addLast(4);
    
    L.addFirst(4);
    L.addFirst(1);
    L.addFirst(14);
    L.addFirst(7);
    
    cout<<"Imprimiendo lista 1"<<endl;
    
    L.printList();
    cout<<endl;
    
    cout<<"Invirtiendo la lista1"<<endl;
    L.reverse();
    L.printList();
    cout<<endl;
    
    cout << "Probando shift a la derecha"<<endl;
    
    L.shift(2);
    L.printList();
    cout<<endl;
    
    cout<<"Probando shift a la izquierda"<<endl;
    
    L.shift(-1);
    L.printList();
    cout <<endl;


    cout <<"Probando operando += "<<endl;
    L+=L1;
    L.printList();
    cout<<endl;
    cout<<"Probando operando =="<<endl;
    L1.printList();
    cout <<endl;
    L2.printList();
    cout<<endl;
    if(L2==L1){
    	cout <<"Son iguales"<<endl;
	}else{
		cout<<"No son iguales"<<endl;
	}
    cout<<endl;
    cout <<"Probando Delete con L"<<endl;
    L.printList();
    L.Delete(2,3);
    cout<<endl;
    L.printList();
    cout<<endl;
    return 0;
}
