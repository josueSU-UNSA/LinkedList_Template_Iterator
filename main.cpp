#include<iostream>
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
    cout<<"Su nueva longitud seria "<<lista.getLongitud()<<endl;
    
    cout<<"Probando iterador "<<endl;
    Iterator<int> iterador;
    for(iterador=lista.begin();iterador!=nullptr;iterador++){
        cout<<iterador;
    }
    cout<<"Aca termina de probarse el code"<<endl;
    return 0;
}
