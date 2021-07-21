#include"Node.h"
#include<iostream>
template<typename G>
class LinkedList{
    private:
        int longitud;
        Node <G>*head;
    public:
        //constructores
        LinkedList();
        LinkedList(G);
        LinkedList(const LinkedList <G>&);
        LinkedList(LinkedList<G> &&);

        LinkedList<G>& operator=(const LinkedList<G> &);

        LinkedList<G>& operator=(LinkedList<G> &&);


        int getLongitud()const;
        Node<G>* getHead();

        Node<G>*begin();
        Node<G>*end();
        Node <G>* operator [](int);
        void insertBegin(G);
        void insertEnd(G);
        void eliminarBegin();
        void eliminarEnd();
        void eliminar(int);
        bool vacio();
        ~LinkedList();

        friend std::ostream& operator <<(std::ostream &salida1,LinkedList<G>& C){
            Node<G>* actual=C.getHead();
            salida1<<"[ ";
            while(actual!=nullptr){
                salida1<<*actual<<" "; 
                actual=actual->getNext();
            }
            salida1<<" ]";
            return salida1;
        }

};
template<typename G>
LinkedList<G>::LinkedList(){
    this->longitud=0;
    this->head=nullptr;
}

template<typename G>

LinkedList<G>::LinkedList(G value){
    this->longitud=1;
    this->head=new Node<G>(value);
}

template<typename G>

LinkedList<G>::LinkedList(const LinkedList <G>&o){//constructor copia
    this->longitud=0;
    this->head=nullptr;
    Node<G>*iterador=o.head;
    while (iterador!=nullptr){
        this->insertEnd(iterador->getContent());
        iterador=iterador->getNext();
    }
}

template<typename G>
LinkedList<G>::LinkedList(LinkedList<G> &&o){//constructor de movimiento
    this->longitud=0;
    this->head=nullptr;
    Node<G>*iterador=o.head;
    while (iterador!=nullptr){
        this->insertEnd(iterador->getContent());
        iterador=iterador->getNext();
    }
}

template<typename G>
LinkedList<G> &LinkedList<G>::operator=(const LinkedList<G> &o){//asignacion de copia
    this->longitud=0;
    this->head=nullptr;
    Node<G>*iterador=o.head;
    while (iterador!=nullptr){
        this->insertEnd(iterador->getContent());
        iterador=iterador->getNext();
    } 
}
template<typename G>
LinkedList<G>& LinkedList<G>:: operator=(LinkedList<G> &&o){//asignacion de movimiento
    this->longitud=0;
    this->head=nullptr;
    Node<G>*iterador=o.head;
    while (iterador!=nullptr){
        this->insertEnd(iterador->getContent());
        iterador=iterador->getNext();
    }
}
template<typename G>
int LinkedList<G>::getLongitud()const{
    return this->longitud;
}

template<typename G>
Node<G>* LinkedList<G>::getHead(){
    return this->head;
}

template<typename G>
Node<G>*LinkedList<G>::begin(){
    return this->head;
}

template<typename G>
Node<G>*LinkedList<G>::end(){
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

template<typename G>
Node <G>* LinkedList<G>::operator [](int pos){
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

template<typename G>
void LinkedList<G>::insertBegin(G value){
    Node<G>*nuevoNodo=new Node<G>(value);
    nuevoNodo->setNext(this->head);
    this->head=nuevoNodo;
    this->longitud++;
}

template<typename G>
void LinkedList<G>::insertEnd(G value){
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
template<typename G>
void LinkedList<G>::eliminarBegin(){
    Node<G>*aux=this->head->getNext();
    delete head;
    head=aux;
    this->longitud--;
}

template<typename G>
void LinkedList<G>::eliminarEnd(){
    
    Node<G>*auxNext=this->head;
    Node<G>*aux=nullptr;
    while(auxNext->getNext()!=nullptr){
        aux=auxNext;
        auxNext=auxNext->getNext();    
    }

    delete auxNext;
    aux->setNext(nullptr);

    this->longitud--;
}

template<typename G>
void LinkedList<G>::eliminar(int position){
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
        std::cout<<"No es posible borrar una posicion inexistente "<<std::endl;
        }
}

template<typename G>
bool LinkedList<G>::vacio(){
    return (this->head==nullptr);
}

template<typename G>
LinkedList<G>::~LinkedList(){
    Node <G>*actual=nullptr;
    while (head!=nullptr){
        actual=head->getNext();
        delete head;
        head=actual;
    }
    delete head;   
}
