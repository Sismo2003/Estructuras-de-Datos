#include <bits/stdc++.h>
#include "arreglo_pila.hpp"

using namespace std;

int main(){

    pila<string> miPinchePila;
    while(true){
        string exp;
        cout<<"Digite su expresion posfija: "; cin >> exp;
        for(auto e : exp){
            if((e != 42) && (e != 43) && (e != 45) && (e != 47) && (e != 94)) miPinchePila.push(string(1,e));
            else{
                if(miPinchePila.size() >= 2){
                    int num1, num2, ans;
                    string s1,s2;
                    s2 = miPinchePila.top();
                    miPinchePila.pop_top();
                    s1 = miPinchePila.top();
                    miPinchePila.pop_top();
                    num2 = std::stoi(s2);
                    num1 = std::stoi(s1);

                    if(e == 42){
                        ans = num1 * num2;
                        miPinchePila.push(to_string(ans));
                    }

                    if(e == 43){
                        ans = num1 + num2;
                        miPinchePila.push(to_string(ans));
                    }

                    if(e == 45){
                        ans = num1 - num2;
                        miPinchePila.push(to_string(ans));
                    }

                    if(e == 47){
                        ans = num1 / num2;
                        miPinchePila.push(to_string(ans));
                    }

                    if(e == 94){
                        ans = pow(num1,num2);
                        miPinchePila.push(to_string(ans));
                    }

                }
            }
        
            
        }

        if(miPinchePila.size() == 1){
            cout<<"La respuesta a su operacion posfija es: "<<miPinchePila.top()<<endl;;
            miPinchePila.pop_top();
        }else{
            cout<<"Su expresion posfija estab mal hecha, corrijala porfavor."<<endl;
        }

        int continuar;

        cout<<"Desea intentarlo de nuevo? si(1) - no(0)"<<endl;
        cin>>continuar;

        if(continuar) continue;
        else break;



    }
    



    return EXIT_SUCCESS;
}