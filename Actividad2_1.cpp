//Andrea Yela González A01025250
//Joshua Ruben Amaya Camilo A01025250
#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
        T value;
        Nodo *next;
        Nodo *prev;

        Nodo(T val)
        {
            value=val;
            next=NULL;
            prev=NULL;
        }
};

template <class T>
class LinkedList{
    Nodo<T> *head;
	Nodo<T> *tail;
	public:
		Nodo<T> *root;
		
		LinkedList(){
			root=NULL;
		    head=NULL;
		    tail=NULL;
		}
		
		
		void append(T val){
			Nodo<T> *nuevo=new Nodo<T>(val);
			this->append(nuevo);
		}
		
		void imprimir(){
			Nodo<T> *temp=head;
            while(temp!=NULL){
                cout<<temp->value<<",";
                temp=temp->next;
            }
            cout<<endl;
		}
		
		void accederElemento(int i){
			int actual=0;
			Nodo<T> *it=root;
			while(it!=NULL && actual<i){
				actual++;
				it=it->next;
			}
			if(actual==i){
				cout<<it->value<<endl;
			}else{
				cout<<"no existe esa posicion"<<endl;
			}
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
            cout<<"Tu número buscado: " <<i << " se encuentra: " << veces <<" veces en la lista" << endl;
		}
		
		void modificarElemento(int i, T val){
			int actual=0;
			Nodo<T> *it=root;
			while(it!=NULL && actual<i){
				actual++;
				it=it->next;
			}
			if(actual==i){
				it->value=val;
			}else{
				cout<<"no existe esa posicion"<<endl;
			}
		}

        void append(Nodo<T> *nuevo){
            if(head == NULL){
                head = nuevo;
                tail = head;
                return;
            }
            nuevo->prev = tail;
            tail-> next = nuevo;
            tail = nuevo;
	    }
		
		void insert(int pos, Nodo<T> *nuevo){
			if(root==NULL){
				return;
			}
			int actual=0;
			Nodo<T> *it=root;
			if(pos==0){
				nuevo->next=root;
				root=nuevo;
				return;
			}
			while(it!=NULL && actual<pos-1){
				it=it->next;
				actual++;
			}
			if(actual==pos-1){
				nuevo->next=it->next;
				it->next=nuevo;
			}
		}
        void insert(int pos, T value){
            Nodo<T> *nuevo=new Nodo<T>(value);
            insert(pos, nuevo);
	    }

        void DeleteList(){
            Nodo<T> *it=head;
			while(it->next != NULL){

				if(it->prev!=NULL){
                    it->prev->next=it->next;
                }
                else{
                    head=it->next;
                }

                if(it->next!=NULL){
                    it->next->prev=it->prev;
                }
                else{
                    tail=it->prev;
                }
                delete it;
		    }
			
        }
		void insert(int pos, Nodo<T> *nuevo){

            if(head==NULL){
                    append(nuevo);
                    return;
            }
            if (pos==0){
                nuevo->next=head;
                head->prev=nuevo;
                head=nuevo;
                return;
            }
            int p=0;
            Nodo<T> *it=head;
            while(it->next!=NULL && p<pos){
                it=it->next;
                p++;
            }
            if(p==pos){
                it->prev->next=nuevo;
                nuevo->prev=it->prev;
                it->prev=nuevo;
                nuevo->next=it;
            }
            if((p+1)==pos){
                append(nuevo);
            }
            
    	}

		void remover(T value){
            Nodo<T> *it=head;
            while(it!=NULL && it->value!=value){
                it=it->next;
                }
            if(it!=NULL){
                if(it->prev!=NULL){
                    it->prev->next=it->next;
                }else{
                    head=it->next;
                }
                if(it->next!=NULL){
                    it->next->prev=it->prev;
                }else{
                    tail=it->prev;
                }
                delete it;
            }
	    }

		void insert(int pos, T val){
			Nodo<T> *nuevo=new Nodo<T>(val);
			this->insert(pos, nuevo);
		}
		
		void eliminar(T val){
			if(root==NULL){
				return;
			}
			if(root->value==val){
				Nodo<T> *temp=root;
				root=root->next;
				delete temp;
				return;
			}
			Nodo<T> *it=root;
			while(it->next!=NULL &&it->next->value!=val){
				it=it->next;
			}
			if(it->next!=NULL){
				Nodo<T> *temp=it->next;
				it->next=temp->next;
				delete temp;
			}
		}
        
        void imprimirReversa(){
		Nodo<T> *temp=root;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->prev;
		}
		cout<<endl;
	}

};
	
	


int main(){
	LinkedList<int> ll;
    int nuevonum = 0;
	ll.append(8);
	ll.append(4);
	ll.append(6);
	ll.append(4);
	ll.append(11);
    ll.append(5);
	ll.append(15);
    ll.append(5);
    ll.imprimir();
    ll.Count(6);
    //ll.DeleteList();
    cout << "Inserte un número para agregar a la lista: "; cin>> nuevonum; cout << endl;
    ll.insert(3,30);
    ll.imprimir();
    
	return 0;
}