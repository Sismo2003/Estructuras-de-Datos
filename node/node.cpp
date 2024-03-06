#include "bits/stdc++.h"
#include "node.h"

using namespace std;
#define enl '\n'
#define fore(i,n) for(int i = 0; i != n ; i++)

int main(){
    int x = 711;
    node <int> *ancla,ancla2;
    node <int> *node_tmp;

    ancla = new node <int>(7, nullptr); //nodo 1
    ancla2 = ancla;
    node_tmp = new node <int>(x, nullptr);// node 2
    ancla->setSiguiente(node_tmp); //declaracion del siguiente nodo
    ancla2=ancla;
    while(ancla2.getSiguienteptr() != nullptr){
        ancla2=ancla2.getSiguiente();
    }
    ancla2.setSiguiente(node_tmp);
    node_tmp->setDato(30);
    cout<<"El primer digito es: " <<ancla->getDato()<<enl;
    cout<<"el siguiente es: " << ancla->getSiguiente().getDato()<<enl;




    return 0;
}