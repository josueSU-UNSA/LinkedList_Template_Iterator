template<typename T>
class Node{
    private:
        Node <T>*next;
        T content;
    public:
        //constructores
        Node(T _content){ 
            this->content=_content;
            this->next=nullptr;
        }
        Node(){ 
            this->content=0;
            this->next=nullptr;
        }
        Node (const Node<T> &obj){//constructor copia
            this->next=obj.next;
            this->content=obj.content;
        }
        Node(Node<T> &&obj){//constructor de movimiento
            this->next=obj.next;
            this->content=obj.content; 
        }
        Node<T>& operator=(const Node<T> &obj){//asignacion de copia
            this->next=obj.next;
            this->content=obj.content; 
        }
        Node<T>& operator=(Node<T> &&obj){//asignacion de movimiento
            this->next=obj.next;
            this->content=obj.content; 
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
        friend std::ostream& operator <<(std::ostream &salida1,const Node<T>& C){
            salida1<<C.getContent();
            return salida1;
        }            
};