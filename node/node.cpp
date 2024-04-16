#include "bits/stdc++.h"
#include "node.h"

using namespace std;
#define enl '\n'
#define fore(i,n) for(int i = 0; i != n ; i++)
bool empty( node <int> *a){
    if(a== nullptr) return true;
    else return false;
}

void push_back(node <int> *ancla, int x){
    if(empty(ancla)){
        cout<<"hh"<<enl;
    }else{
        node <int> *node_tmp = new node<int> (x, nullptr);
        while(ancla->getSiguiente() != nullptr){
            ancla=ancla->getSiguiente();
        }
        ancla->setSiguiente(node_tmp);
    }
}


int main(){
    node <int> ancla;
    //push_back(ancla,221);
    int x = 9;
    node <int> *node_tmp;
    node_tmp = new node<int> (x);
    ancla.setSiguiente(node_tmp);
    cout<<ancla.getSiguiente()<<enl;
    cout<<ancla.getDato()<<enl;

    return 0;
}