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
		
		void imprimir(){
			Nodo<T> *temp=head;
            while(temp!=NULL){
                cout<<temp->value<<",";
                temp=temp->next;
            }
            cout<<endl;
		}

        void Count(T i){
			int actual = 0;
            int veces = 0;
			Nodo<T> *it=head;
			while(it!=NULL){
                if(it ->value == i){
                    veces ++; 
                }
                
                it=it->next;
			}
            cout<<"Tu número buscado: " <<i << " se encuentra: " << veces <<" veces en la lista" << endl;
		}

        void posicion(){
            int posi = 0;
            Nodo<T> *it=head;
            while (it != NULL){
                if (it > it->next){
                    posi++;
                    insert(posi, it);
                }
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
    
    void DeleteList(){
        Nodo<T> *it=head;
        Nodo<T> *temp=head;
        if(it==NULL){
            return;
        }
        while(it->next!=NULL){
            Nodo<T> *temp=it->next;
            it->next=temp->next;
            delete temp;
        }

        it=it->next;
        delete temp;
    }


    
};
	
	


int main(){
	/*LinkedList<int> ll;
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
    ll.Count(58);*/
    /*
    LinkedList<int> pos;     
    pos.append(6);
    pos.append(9);
    pos.append(5);
    pos.append(7);
    pos.posicion();
    pos.imprimir();*/

    LinkedList<int> ll;
	ll.append(8);
	ll.append(4);
	ll.append(6);
	ll.append(4);
	ll.append(11);
    ll.append(5);
	ll.append(15);
    ll.append(5);
    ll.imprimir();
    ll.DeleteList(); // Saca un 0 de la nada 
    ll.imprimir();
	return 0;
}