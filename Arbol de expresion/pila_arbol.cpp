#include <bits/stdc++.h>
#include "mi_pila.h"
using namespace std;
#include "Node.h"

int main(){

    pila<Node> miPinchePila;
    
        string exp;
        cout<<"Digite su expresion posfija: "; cin >> exp;
        for(auto e : exp){
            cout<<"hola"<<endl;
            if((e != 42) && (e != 43) && (e != 45) && (e != 47) && (e != 94)){
                Node n(string(1,e));
                miPinchePila.push(n);
            } 
            else{
                if(miPinchePila.size() >= 2){
                    cout<<miPinchePila.size()<<endl;
                    int num1, num2, ans;
                    Node s1,s2;
                    s2 = miPinchePila.top();
                    miPinchePila.pop_top();
                    s1 = miPinchePila.top();
                    miPinchePila.pop_top();
                    

                    Node roo(string(1,e));
                    Node test("3");
                    roo.setNode(&test, 'l');
                    roo.setNode(&test, 'r');

                    cout<<roo.getNode('r')->getValue()<<endl;
                    

                    miPinchePila.push(roo);

                    cout<<"paso 1"<<endl;
                }
            }
        
            
        }

        cout<<miPinchePila.size()<<endl;



    
    



    return EXIT_SUCCESS;
}