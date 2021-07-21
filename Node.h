template<typename T>
class Node{
    private:
        Node <T>*next;
        T content;
    public:
        //constructores
        Node(T);
        Node();
        Node (const Node<T> &);
        Node(Node<T> &&);
        Node<T>& operator=(const Node<T> &);
        Node<T>& operator=(Node<T> &&);
        Node <T>* getNext() const;
        void setNext(Node *);
        T getContent() const;
        void setContent(T);
        friend std::ostream& operator <<(std::ostream &salida1,const Node<T>& C){
            salida1<<C.getContent();
            return salida1;
        }            
};
template<typename T>
Node<T>::Node(T _content){ 
    this->content=_content;
    this->next=nullptr;
}

template<typename T>
Node<T>::Node(){ 
    this->content=0;
    this->next=nullptr;
}

template<typename T>
Node<T>::Node (const Node<T> &obj){//constructor copia
    this->next=obj.next;
    this->content=obj.content;
}

template<typename T>
Node<T>::Node(Node<T> &&obj){//constructor de movimiento
    this->next=obj.next;
    this->content=obj.content; 
}

template<typename T>
Node<T>&Node<T>:: operator=(const Node<T> &obj){//asignacion de copia
    this->next=obj.next;
    this->content=obj.content; 
}

template<typename T>
Node<T>& Node<T>::operator=(Node<T> &&obj){//asignacion de movimiento
    this->next=obj.next;
    this->content=obj.content; 
}

template<typename T>
Node <T>* Node<T>::getNext() const{
    return this->next;
}
        
template<typename T>
void Node<T>::setNext(Node *next){
    this->next=next;
}
        
template<typename T>
T Node<T>:: getContent() const{
    return this->content;
}
        
template<typename T>
void Node<T>::setContent(T content){
    this->content=content;
}
