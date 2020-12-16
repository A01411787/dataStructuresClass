/// 2 Septiembre 2020
/// Created by : Ing. Delia Castro
// Se agregaron los m�todos Delete, reverse, shift, == y +=
// Jos� de Jes�s Bernal Mercado A01411787


#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>

/// clase Nodo, el cual guarda un atributo de cualquier tipo y un apuntador a otra estructura igual del mismo tipo
class Node{
public:
   ///atributos
    T data;
    Node <T> *pNext;
    ///constructores
    Node (){
        pNext=NULL;           //CONSTRUCTOR SIN PAR�METROS
    }
    Node ( T data){			  //CONSTRUCTOR CON PAR�METRO data
        this->data = data;
        pNext=NULL;
    }
};

///clase Linkedlisy cuyo atributo es un apuntador al inicio de la estructura, la cual estara formada por cero, uno o varios nodos
template <class T>
class LinkedList{
private:
    Node <T> *Head;           //HEAD ES UN APUNTADOR DE TIPO NODO CON SUS RESPECTIVOS ATRIBUTOS DATA Y PNEXT
public:
    /// Constructor que inicializa el apuntador (atributo a NULL)
    LinkedList(){
        Head=NULL;
    }
    /// Desctructor, libera la memoria de todos los nodos que tenga
    ~LinkedList(){
        Node <T> *pAux = Head;
        while (pAux != NULL){
                Head = Head->pNext;
                delete pAux;
                pAux = Head;
        }
    }
    /// M�todo addFirst
    /// Par�metro: recibe un valor de tipo T
    /// Descripci�n: crea un nodo con el valor recibido como par�metro y lo coloca al inicio de la lista
    void addFirst(T dato){
    	
    	Node <T> *pNew = new Node <T> (dato);  //pNew es una cajita que tiene un valor que yo recib� de par�metro
    	pNew->pNext = Head;  //SE USA LA FLECHA ES PORQUE ES UN ATRIBUTO DIN�MICO
    	Head = pNew;
    	
	}
	
	/// M�todo deleteFirst
    /// Par�metro: ninguno
    /// Descripci�n: Elimina el primer elemento de la lista si existe
    
    
    void deleteFirst(){
    	
    	if (Head != NULL){
    		Node <T> *pAux = Head;
    		Head = Head->pNext;
    		delete pAux;
		}
    	
    	
	}


   /// M�todo addLast
    /// Par�metro: recibe un valor de tipo T
    /// Descripci�n: crea un nodo con el valor recibido como par�metro y lo coloca al final de la lista
    
    void addLast(T dato){
	
		Node <T> *pNew = new Node <T> (dato);         //Creo mi nuevo nodo a agregar AS� SIEMPRE 
		Node <T> *pAux = Head;                //Nodo Auxiliar para recorrer la lista
		
		if (Head == NULL){	//Primero checo el que primer dato en la lista sea NULL
			Head = pNew;    //Si es el NULL, entonces el dato que recibas ser� el primer
		}
		else{
			
			while(pAux->pNext != NULL)
				pAux = pAux ->pNext;
			pAux->pNext = pNew;
			
		}
	
	}
    /// M�todo deleteLast
    /// Par�metro: ninguno
    /// Descripci�n: Borra el �ltimo elemento de la lista
    
    void deleteLast(){
    	
    	Node <T> *pAux = Head;                //Nodo Auxiliar para recorrer la lista
    	Node <T> *pAux2 = NULL;
		
		if (Head != NULL){	//Primero checo el que primer dato en la lista sea NULL

			while(pAux->pNext != NULL){
				pAux2 = pAux;
				pAux = pAux ->pNext;
			}
			
			delete pAux;
			if (pAux2 != NULL)
				pAux2->pNext = NULL;
			else
				Head = NULL;
		}

	}
	
    /// M�todo addN
    /// Par�metro: recibe un valor tipo T y una posicion en la lista para guardar
    /// Descripci�n: crea un nodo con el calor recibido como par�metro y lo agrega en la posici�n dada
    
    void addN(T dato, int P){
    	
    	Node <T> *pNew = new Node <T>(dato);
    	Node <T> *pAux = Head;
    	if (P <= size() && P > 0){
 
			if (P ==1){
				addFirst(dato);
			}
			else{
				
				for (int i = 1; i <(P-1); i++){
					pAux = pAux->pNext;
				}
				pNew->pNext = pAux->pNext;
				pAux->pNext = pNew;
				
			}
			
		}
    	
	}
    
    /// M�todo printList
    /// Par�metro: ninguno
    /// Descripci�n: Muestra el contenido de los nodos de la lista
    
    void printList(){
    	
    	
    	Node <T> *pP = Head;
    	while (pP!= NULL){
    		
    		cout << pP -> data << "-->";
    		pP = pP -> pNext;
    		
		}
		
    	
	}
	
	/// M�todo size
    /// Par�metro: ninguno
    /// Descripci�n: Devuelve el tama�o de la lista
    
    int size(){
    	
    	Node <T> *pAux = Head;                //Nodo Auxiliar para recorrer la lista
    	int cont = 0;
    	if (Head == NULL){	//Primero checo el que primer dato en la lista sea NULL
			cout << "La lista esta vac�a"<<endl;   //Si es el NULL, entonces el dato que recibas ser� el primer
		}

    	else{
			
			while(pAux!= NULL){
				pAux = pAux ->pNext;
				cont = cont + 1;
			}	
			return cont;	
		}
    	
	}
	
	/// M�todo reverse
    /// Par�metro: ninguno
    /// Descripci�n: Invierte la lista
    
    void reverse(){
	
		Node <T> *current = Head;
		Node <T> *previous = NULL;
		Node <T> *next;
		
		while(current != NULL){
			
			next = current->pNext;
			current->pNext=previous;
			previous = current;
			current = next;
			
		}
		Head = previous;
	
	}
	
	/// M�todo shift
    /// Par�metro: n
    /// Descripci�n: Hace el corrimiento de la lista n veces
    
    void shift (int n){
    	Node <T> *Last = Head;
    	Node <T> *unoA = NULL;
    	Node <T> *unoM = Head->pNext;
    	
		while(Last->pNext != NULL){
			unoA = Last;
			Last = Last ->pNext;
		}
				
    	if(n>0){
 
		    for (int i = 0; i < n; i++){
		    		    		
	    		Last->pNext = Head;
				Head = Last;
				Last = unoA;
				unoA->pNext = NULL;
				
				unoA = Head;
				while(unoA->pNext != Last){
					unoA = unoA->pNext;
				}
					
			}

		}else{
			
			for (int i = 0; i < n*(-1); i++){
			
			Last->pNext = Head;
			Head->pNext = NULL;
			Last = Head;
			Head = unoM;
			unoM = Head->pNext;
			}
			
		}
    		
	}
	
	/// M�todo +=
    /// Par�metro: Lista LINKEDLIST
    /// Descripci�n: concatena el contenido de dos listas
	
	void operator+=(const LinkedList<T> &L2){
        Node<T> *Aux= Head;
        Node<T> *Aux2= L2.Head;

        if (L2.Head==NULL) {
            return;
        }
        else {
            while (Aux->pNext!=NULL)
                Aux=Aux->pNext;      //Se llega a la posici�n final de la lista
   
            while (Aux2->pNext!=NULL) {
           
	            Aux->pNext=new Node<T>(Aux2->data);   //Se le concatena el valor de la lista 2
	            Aux2=Aux2->pNext;
	            Aux=Aux->pNext;
            }
            Aux->pNext=new Node<T>(Aux2->data);
        }
    }
    
    /// M�todo ==
    /// Par�metro: Lista LINKEDLIST
    /// Descripci�n: Regrese true en caso de que las listas sean iguales, en caso contrario regresa false
    
    bool operator ==(const LinkedList<T> &L2){
    	
    	Node <T> *Aux1 = Head;
    	Node <T> *Aux2 = L2.Head;
    	
    	while (Aux1!=NULL){
    		
    		if(Aux1->data != Aux2->data){
    			return false;
			}
			else{
				Aux1 = Aux1->pNext;
				Aux2 = Aux2->pNext;
			}
    		
		}

		return true;
    	
	}
	
	/// M�todo Delete
    /// Par�metro: X, Y
    /// Descripci�n: borra x nodos a partir de la posici�n y. 
    
    void Delete(int X, int Y){
    	
    	Node <T> *Aux1 = Head;
    	Node <T> *Aux2;
    	
    	for (int i =1; i< Y-1;i++){
    		Aux1 = Aux1->pNext;
		}
		
		if (X <= (size()-Y+1)){
		
			for (int i=0; i<X;i++){
				
				Node <T> *Aux2;
				Aux2 = Aux1->pNext;
				
				if(Aux2->pNext != NULL){
					Aux1->pNext = Aux2->pNext;
				}
				else{
					Aux1->pNext = NULL;
				}
				delete Aux2;
				
			}
    	}else{
    		
    		while(Aux1->pNext != NULL){
    			Node <T> *Aux2;
				Aux2 = Aux1->pNext;
				Aux1->pNext = Aux2->pNext;
				delete Aux2;
			}
    		Aux1->pNext = NULL;
		}
    	
	}
    
};

#endif // LINKEDLIST_H_INCLUDED
