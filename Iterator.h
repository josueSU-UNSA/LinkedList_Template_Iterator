#include<iostream>
#include "LinkedList.h"
template<typename I>
class Iterator{
    private:
        Node<I>*iterador;
    public:
        Iterator();
        Iterator(Node<I> *);
        Iterator(const Iterator<I>&);

        Iterator(Iterator<I> &&);
        void setIterator(Node<I>*);
        Iterator <I>operator =(Node<I>*);

        Iterator<I> operator =(const Iterator<I>&);

        Iterator<I> operator =(const Iterator<I>&&);

        Iterator <I>operator++(int);//forma de postfijo
        Iterator <I>&operator++();
        Iterator<I> operator +(int);
        Iterator<I> operator +=(int);
        I operator*();
        bool operator!=(Node<I>*);
        ~Iterator();
        friend std::ostream& operator <<(std::ostream &salida1,Iterator<I>& i){
            salida1<<*i<<std::endl;
            return salida1;
        }  
};

template<typename I>
Iterator<I>::Iterator(){     //constructor por defecto
    this->iterador=nullptr;
}

template<typename I>
Iterator<I>::Iterator(Node<I> *o){//constructor q copia un objeto Node * a un objeto iterator
    this->iterador=o;
}

template<typename I>
Iterator<I>::Iterator(const Iterator<I>&o){//constructor q copia un objeto Node * a un objeto iterator
    this->iterador=o.iterador;
}

template<typename I>
Iterator<I>::Iterator(Iterator<I> &&o){//constructor de movimiento
    this->iterador=o.iterador;
    o.setIterator(nullptr);
}
template<typename I>
void Iterator<I>::setIterator(Node<I>*i){
    this->iterador=i;
}
template<typename I>
Iterator <I> Iterator<I>::operator =(Node<I>*o){//operador de asignacion
    delete this->iterador;
    this->iterador=o;
    return *this;
}

template<typename I>
Iterator<I> Iterator<I>::operator =(const Iterator<I>&o){// operador de asignacion
    this->iterador=o.iterador;
    return *this;
}

template<typename I>
Iterator<I> Iterator<I>::operator =(const Iterator<I>&&o){//asignacion de movimiento
    delete this->iterador;
    this->iterador=o.iterador;
    return *this;
    delete o;
    return *this;
}

template<typename I>
Iterator <I> Iterator<I>::operator++(int){//forma de postfijo
    this->iterador = this->iterador->getNext();
    Iterator <I>aux(this->iterador);
    return aux; 
}

template<typename I>
Iterator <I>& Iterator<I>::operator++(){//forma de prefijo
    this->iterador = this->iterador->getNext();
    Iterator <I>aux(this->iterador);
    return *this; 
}

template<typename I>
Iterator<I> Iterator<I>::operator +(int i){
    for(int j=0;j<i;j++){
        this->iterador=this->iterador->getNext();
    }
    Iterator <I>aux(this->iterador);
    return aux;  
}
template<typename I>
Iterator<I> Iterator<I>::operator +=(int i){
    for(int j=0;j<i;j++){
        this->iterador=this->iterador->getNext();
    }
    Iterator <I>aux(this->iterador);
    return aux; 
}
template<typename I>
I Iterator<I>::operator*(){
    return this->iterador->getContent();
}

template<typename I>
bool Iterator<I>::operator!=(Node<I>*o){
    return (this->iterador!=o);
}
template<typename I>
Iterator<I>::~Iterator(){}
