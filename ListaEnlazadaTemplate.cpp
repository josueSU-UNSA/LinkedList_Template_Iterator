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
        Node(){ 
            this->content=0;
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
            Node<G>*iterador=o.head;
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
};
    template<typename I>
        class Iterator{
            private:
                Node<I>*iterador;
            public:
                Iterator(){     //constructor por defecto
                    this->iterador=nullptr;
                }
                Iterator(Node<I> *o){//constructor q copia un objeto Node * a un objeto iterator
                    this->iterador=o;
                }
                Iterator(const Iterator<I>&o){//constructor q copia un objeto Node * a un objeto iterator
                    this->iterador=o.iterador;
                }
                Iterator operator =(Node<I>*o){//constructor de movimiento
                    this->iterador=o;
                    return *this;
                }
                Iterator operator =(const Iterator<I>&o){//constructor de movimiento
                    this->iterador=o.iterador;
                    return *this;
                }
                
                Iterator<I> operator++(){
                    this->iterador=this->iterador->getNext();   
                    Iterator<I>aux(this->iterador);
                    return aux;
                }
                
                Iterator<I> operator +(int i){
                    for(int j=0;j<i;j++){
                       this->iterador=this->iterador->getNext();
                    }
                    Iterator <I>aux(this->iterador);
                    return aux;  

               }
               
                I operator*(){
                    return this->iterador->getContent();
                } 
                
                friend ostream& operator <<(ostream &salida1,Iterator<I>& i){
                    salida1<<*i<<endl;
                    return salida1;
                }               
                bool operator!=(Node<I>*o){
                    return (this->iterador!=o);
                }
                ~Iterator(){}
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
    
    LinkedList<int> lista2=lista;

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
    
    cout<<"Probando iterador "<<endl;
    //for(Iterator<int>i=lista.begin();i!=lista.end()->getNext();i++){
        //cout<<*i<<endl;
    //}
    //Node<int>*aux=lista.getHead();
    Iterator<int> iterador;
    for(iterador=lista.begin();iterador!=nullptr;iterador++){
        cout<<iterador;
    }
    cout<<"Aca termina de probarse el code"<<endl;


    //cout<<lista2<<endl;
    getch();
    return 0;
}
