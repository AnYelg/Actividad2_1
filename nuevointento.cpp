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
            cout<<"Tu número buscado: " <<i << " se encuentra: " << veces <<" veces en la lista" << endl;
		}
        void DeleteList(){
            Nodo<T> *temp=root;
            Nodo<T> *it=root;

			if(root==NULL){
				return;
			}

			while(it->next!=NULL){
                Nodo<T> *temp=it->next;
				it->next=temp->next;
				delete temp;
			}
            
			root=root->next;
			delete temp;
			return;
		}
        void RemoveDuplicates(){ 
            if(root==NULL){
				return;
			}

            if(root->value == root->next->value){
                Nodo<T> *temp=root;
				root=root->next;
				delete temp;
				return;
            }
            Nodo<T> *it=root;

            while (it->next!=NULL && it->next->value != it->value){    
                it=it->next;
            }

            if(it->next!=NULL){
                Nodo<T> *temp=it;
				it = temp->next;
				delete temp;
			}

        }

        void SortedInsert (T value){
            Nodo<T>* nuevo=new Nodo<T>(value);
            if(root==NULL){
				return;
			}

            int pos = 0;
            int actual=0;
            Nodo<T> *it=root;
            while(it->value > it->next->value){

                
                it=it->next;
                pos++;
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
};

int main(){
	LinkedList<int> ll;
	/*ll.append(5);
	ll.append(5);
	ll.append(6);
	ll.append(4);
	ll.append(11);
    ll.append(4);
	ll.append(15);
	ll.imprimir();
	ll.Count(5);
    //ll.DeleteList();
    //ll.imprimir();
    ll.RemoveDuplicates();
    ll.imprimir();*/
    ll.append(1);
    ll.append(2);
    ll.append(4);
    ll.SortedInsert(3);
    ll.imprimir();
	
	
	return 0;
}