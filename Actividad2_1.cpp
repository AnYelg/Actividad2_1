//Andrea Yela González A01025250
//Joshua Ruben Amaya Camilo A01025250
//Comentarios: Reverse fue basado de un blog en internet. https://www.studytonight.com/post/program-to-reverse-a-linked-list-in-cpp

#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo *next;
	
	Nodo(T val){
		value = val;
		next = NULL;
	}
};

template <class T>
class LinkedList{
	public:
		Nodo<T> *root;
		
		LinkedList(){
			root=NULL;
		}

        void append(Nodo<T> *nuevo){
			if(root==NULL){
				root=nuevo;
			}else{
				Nodo<T> *it=root;
				while(it->next!=NULL){
					it=it->next;
				}
				it->next=nuevo;
			}
		}
        
		void append(T val){
			Nodo<T> *nuevo=new Nodo<T>(val);
			this->append(nuevo);
		}
		
		void imprimir(){
			Nodo<T> *it=root;
			while(it!=NULL){
				cout<<it->value<<",";
				it=it->next;
			}
			cout<<endl;
		}

        void Count(T i){
			int actual = 0;
            int veces = 0;
			Nodo<T> *it=root;
			while(it!=NULL){
                if(it ->value == i){
                    veces ++; 
                }
                
                it=it->next;
			}
            cout<<"Tu número buscado: " <<i << " se encuentra " << veces <<" veces en la lista" << endl;
		}
        
		void DeleteList(){
            Nodo<T> *it=root;

			if(root==NULL){
				return;
			}

			while(it->next!=NULL){
                Nodo<T> *temp = it->next;
				it->next = temp->next;
				delete temp;
			}
            
			root=root->next;
			return;
		}

        void SortedInsert (T value){
			if(root==NULL){
				return;
			}

			Nodo<T> *it = root;
			Nodo<T> *nuev = new Nodo<T>(value);
			
			while(it->next->value < nuev->value){
				it = it->next;
			}

			nuev->next = it->next;
			it ->next = nuev;
		
        }

		 void removeDuplicates(){
            Nodo <T> *it = root;
			Nodo <T> *temp = NULL;

			if(root == NULL){
				return;
			}
			
			while (it->value == it->next->value){
				temp = it->next;
				it->next = temp->next;
				delete temp;
			}
			it = it->next;
			
		}


		void  Reverse(){

			if(root==NULL){
				return;
			}

			Nodo<T> *it = root;
			Nodo<T> *temp = NULL;
			Nodo <T> *prev = NULL;

			while (it != NULL){
				temp = it->next;
				it->next= prev;
				prev = it;
				it = temp;
			}
			root = prev;
			
		}


};

int main(){
	LinkedList<int> ll;
	ll.append(5);
	ll.append(5);
	ll.append(5);
	ll.append(7);
	ll.append(8);
    ll.append(9);
	ll.append(10);
	cout << "Nuestra linked list: " << endl;
	ll.imprimir();
	ll.Count(5);
    ll.DeleteList();
    cout << "Lista borrada: "<< endl;
	ll.imprimir();
	cout << "Nueva lista ordenada: " << endl;
	ll.append(5);
	ll.append(5);
	ll.append(5);
	ll.append(7);
	ll.append(8);
    ll.append(9);
	ll.append(10);
	ll.imprimir();
	cout << "Remover duplicados: "<< endl;
    ll.removeDuplicates();
	ll.imprimir();
	cout << "Insertar un número en el orden creciente: "<< endl;
	int numeroinsertado;
	cout << "Ponga un número: "; cin >> numeroinsertado;
	ll.SortedInsert(numeroinsertado);
	ll.imprimir();
	cout << "Lista en reversa: "<< endl;
	ll.Reverse();
	ll.imprimir();
	
    
}