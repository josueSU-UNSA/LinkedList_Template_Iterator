#include<iostream>
#include<conio.h>
//#include<vector>
using namespace std;
template<typename T>
class Node{
    private:
        Node <T>*next;
        T content;
    public:
        
        Node(T _content){ 
            this->content=_content;
            this->next=nullptr;
        }
        
        Node <T>* getNext() const{
            return this->next;
        }
        
        void setNext(Node *next){
            this->next=next;
        }
        
        T getContent() const{
            return this->content;
        }
        
        void setContent(T content){
            this->content=content;
        }
        //friend ostream& operator <<(ostream &salida1,const Node<G>& C);
        Node<T>* operator++(){
            *this=*this->getNext();
            return *this;
        }
        friend ostream& operator <<(ostream &salida1,const Node<T>& C){
            salida1<<C.getContent();
            return salida1;
        }
            
};

template<typename G>
class LinkedList{
    private:
        int longitud;
        Node <G>*head;
    public:
        LinkedList(){
            this->longitud=0;
            this->head=nullptr;
            
        }
        LinkedList(G value){
            this->longitud=1;
            this->head=new Node<G>(value);
            
        }
        int getLongitud()const{
            return this->longitud;
        }
        Node<G>* getHead(){
            return this->head;
        }
        LinkedList(const LinkedList <G>&o){
            this->longitud=0;
            this->head=nullptr;
            Node<G>*iterador=o.head();
            while (iterador!=nullptr){
                this->insertEnd(iterador->getContent());
                iterador=iterador->getNext();
            }


        }
        Node<G>*begin(){
            return this->head;
        }
        Node<G>*end(){
            Node<G>* iterador=head;
            if(head==nullptr){
                return this->head;
            }
            else{
                while(iterador->getNext()!=nullptr){
                    iterador=iterador->getNext();
                }
                return iterador;
            }
        }
        Node <G>* operator [](int pos){
            int count=0;
            Node<G>*auxiliarIterador=head;
            if(pos<this->longitud){
                while(count<pos){
                    auxiliarIterador=auxiliarIterador->getNext();
                    count++;
                }
                return auxiliarIterador;
            }
        }
        void insertBegin(G value){
            
            Node<G>*nuevoNodo=new Node<G>(value);
            nuevoNodo->setNext(this->head);
            this->head=nuevoNodo;
            this->longitud++;
        }
        void insertEnd(G value){
            Node<G>*nuevoNodo=new Node<G>(value);
            Node <G>*iterador=this->head;
            if(head==nullptr){
                this->head=nuevoNodo;
            }
            else{
                while(iterador->getNext()!=nullptr){
                    iterador=iterador->getNext();
                }
                iterador->setNext(nuevoNodo);

            }
            this->longitud++;
        }
        void eliminar(int position){
            Node<G>*actual=this->head;
            Node<G>*aux=nullptr;
            int iterador=0;
            if(position<this->longitud){
                if(position==0){
                    
                    head=head->getNext();
                    delete actual;
                }
                else{
                    while(iterador<position){
                        aux = actual; 
                        actual = actual->getNext();
                        iterador++;
                    }
                    aux -> setNext( actual->getNext());
                    delete actual;   
                }
                this->longitud--;
            }
            else{
                cout<<"No es posible borrar una posicion inexistente "<<endl;
            }
            
        }
        friend ostream& operator <<(ostream &salida1,LinkedList<G>& C){
            Node<G>* actual=C.getHead();
            salida1<<"[ ";
            while(actual!=nullptr){
                salida1<<*actual<<" "; 
                actual=actual->getNext();
            }
            salida1<<" ]";
            return salida1;
        }
        
        ~LinkedList(){
            Node <G>*actual=nullptr;
            while (head!=nullptr)
            {
                actual=head->getNext();
                delete head;
                head=actual;
            }
            delete head;   

        }
        
        /*
        ~LinkedList(){
            for (Node<int>*i=this->begin();i!=nullptr; i=i->getNext()){
                delete i;
            } 
            head=nullptr;
        }
        */
};


int main(){
    Node<int> prueba(3);
    LinkedList <int>lista;
    lista.insertBegin(2);
    lista.insertBegin(4);
    lista.insertBegin(15);
    lista.insertEnd(7);
    lista.insertEnd(9);
    lista.insertBegin(13);
    lista.insertEnd(100);
    
    
    
    
    cout<<lista<<endl<<endl;
    cout<<"Usando un for para iterar sobre la lista mediante indices"<<endl;
    for (int i=0;i<lista.getLongitud();i++){
        cout<<*lista[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Usando un for para iterar sobre la lista mediante direcciones"<<endl;
  
    for (Node<int>*i=lista.begin();i!=nullptr; i=i->getNext()){
        cout<<*i<<endl;
    }
    
    
    cout<<endl<<endl;
    cout<<"Eliminacion del indice 5 de la lista"<<endl;


    

    lista.eliminar(5);
    cout<<"Lista actualizada "<<endl;
    cout<<lista<<endl;
    cout<<"Su nueva longitud seria"<<lista.getLongitud()<<endl;
    

    getch();
    return 0;
}
