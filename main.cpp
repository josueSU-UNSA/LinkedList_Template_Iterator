#include<iostream>
#include<list>
#include "Iterator.h"
using namespace std;
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
    for (int i=0;i<lista.getLongitud();++i){
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
    cout<<"Su nueva longitud seria "<<lista.getLongitud()<<endl;
    
    cout<<"Probando objeto iterador en la lista "<<endl;
    Iterator<int> iterador;
    for(iterador=lista.begin();iterador!=nullptr;iterador++){
        cout<<iterador;
    }
    cout<<"Borramos el primer y ultimo elemento de la lista"<<endl;
    lista.eliminarBegin();
    lista.eliminarEnd();
    cout<<lista<<endl;
    cout<<"La longitud de la lista actualizada es "<<lista.getLongitud()<<endl<<endl;
    list<int>pruebaStl();
    
    cout<<"Antes de invocar al destructor: "<<endl;
    (lista.vacio())?cout<<"La lista esta vacia "<<endl:cout<<"La lista no esta vacia "<<endl<<endl;
    
    lista.~LinkedList();
    cout<<"Despues de invocar al destructor: "<<endl;
    (lista.vacio())?cout<<"La lista esta vacia "<<endl:cout<<"La lista no esta vacia "<<endl;
    return 0;
}
