#include <bits/stdc++.h>
#include "mi_pila.h"
#include "Node.h"
using namespace std;
#define enl '\n'
#define fore(i,n) for(int i = 0 ;i !=n ; i++);

int main(){

    pila<Node> miPinchePila;

    string exp;
    cout<<"Digite su expresion posfija: "; cin >> exp;
    for(auto e : exp){
        //cout<<"hola"<<endl;
        if((e != 42) && (e != 43) && (e != 45) && (e != 47) && (e != 94)){
            Node *n=new Node(string(1,e));
            miPinchePila.push(*n);
        }
        else{
            if(miPinchePila.size() >= 2){
                cout<<miPinchePila.size()<<endl;
                int num1, num2, ans;
                Node *s2 = new Node(miPinchePila.top());
                miPinchePila.pop_top();
                Node *s1 = new Node(miPinchePila.top());
                miPinchePila.pop_top();
                Node *root = new Node(string(1,e));
                root->setNode(s1, 'l');
                root->setNode(s2, 'r');
//                cout<<"Lado izquierdo (root): "<<root->getNode('l')->getValue()<<enl;
//                cout<<"Lado derecho (root): "<<root->getNode('r')->getValue()<<enl;

                miPinchePila.push(*root);
               // cout<<"paso 1"<<endl;
            }
        }


    }

    cout<<miPinchePila.size()<<enl;

    return 0;
}
