
#include <bits/stdc++.h>

#define ss second
#define ff first
#define pb push_back
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define enl "\n"
#define fast                 \
    ios::sync_with_stdio(0); \
    cout.tie(0);             \
    cin.tie(0);
#define sz(s) int(s.size())
#define fore(i, n) for (int i = 0; i != n; ++i)
#define foreach(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)
#define arre cout << "YES" << enl;
#define nel cout << "NO" << enl;
#define neg cout << -1 << enl;
// asendente
#define srt(s) sort(all(s));
// desendente
#define rsrt(s) sort(rall(s));
//lowerbound
#define lower(vec, s) lower_bound(vec.begin(), vec.end(), s)
//upperbound
#define upper(vec, s) upper_bound(vec.begin(), vec.end(), s)
using namespace std;
typedef long long lli;
typedef pair<lli, lli> ii;
typedef vector<char> vhar;
typedef vector<lli> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
#include "automovile.h"
#include "house.h"
#include "life.h"
#include "user.h"




void menu(){
    vector<user> users_List;
    int user_menu_answer = 0;
    int user_policy_type_answer = 0;
    while(user_menu_answer < 4 && user_menu_answer >= 0){
        cout<<"Ingrese la Opcion deseada"<<enl;
        cout<<"1.Agregar Poliza\n 2.Editar Poliza\n 3.Eliminar Poliza\n 4.Salir del programa"<<enl;
        cout<<"---> ";cin>>user_menu_answer;
        cout<<enl;
        if(user_menu_answer  == 1) { // Add new policy
            while(user_policy_type_answer >= 0 && user_policy_type_answer < 4 ) {
                cout << "Seleccione el tipo de poliza de su preferencia: \n";
                cout << " 1.Vida\n2.Automovil\n3.Casa" << enl<<"---> ";
                cin >> user_policy_type_answer;
                cout<<enl;
                if(user_policy_type_answer == 1){ //Life policy type
                        Life new_life_Policy;
                        user new_User(new_life_Policy);
                        new_User.set_Client_Name();
                        new_User.set_age();
                        new_User.set_amount();
                        new_User.set_Monthly_Payment();
                        users_List.push_back(new_User);
                        new_User.set_id(sz(users_List));
                        cout<<"El folio de la poliza es: "<<new_User.get_id()<<enl;
                        break;
                }
                else if(user_policy_type_answer == 2){
                    automovile new_car_Policy;
                    user new_User(new_car_Policy);
                    new_User.set_Client_Name();
                    new_User.set_age();
                    new_User.set_amount();
                    new_User.set_Monthly_Payment();
                    users_List.push_back(new_User);
                    new_User.set_id(sz(users_List));
                    break;
                }
                else if(user_policy_type_answer == 3){
                    house new_House_Policy;
                    user new_User(new_House_Policy);
                    new_User.set_Client_Name();
                    new_User.set_age();
                    new_User.set_amount();
                    new_User.set_Monthly_Payment();
                    users_List.push_back(new_User);
                    int id = sz(users_List);
                    new_User.set_id(id);
                    cout<<"Su numero de Poliza seria: "<<new_User.get_id()<<enl;
                    break;
                }
            }
        }
        else if(user_menu_answer == 2){
            int user_policy_entry;
            bool existing_user_flag = false;
            cout<<"Ingresa el numero de Poliza: ";
            cin>>user_policy_entry;
            for(auto e : users_List){
                cout<<"usuario: "<<e.get_id()<<enl;
            }
            for(auto e : users_List){
                if(user_policy_entry == e.get_id()){
                    existing_user_flag = true;
                    user lookup_User = e;
                    int user_edit_selected = 0;
                    cout<<"Que deseas editar?"<<enl;
                    cout<<"1.Nombre a cargo de la poliza.\n2.Edad\n3.Domicilio\n4.Cantidad asegurada\n5.Pagos mensuales"<<enl;
                    cout<<">>> ";
                    cin>>user_edit_selected;
                    if(user_edit_selected == 1){
                        cout<<"Nombre anterior: "<<lookup_User.get_Client_Name()<<enl;
                        lookup_User.set_Client_Name();
                        break;
                    }
                    else if(user_edit_selected == 2){
                        cout<<"La edad actual es: "<<lookup_User.get_age()<<enl;
                        lookup_User.set_age();
                        break;
                    }
                    else if(user_edit_selected == 3){
                        cout<<"El Domicilio actual es: "<<lookup_User.get_Address()<<enl;
                        lookup_User.set_addres();
                        break;
                    }
                    else if(user_edit_selected == 4){
                        cout<<"La cantidad asegurada es: "<<enl;
                        lookup_User.set_addres();
                        break;
                    }
                    else if(user_edit_selected == 5){
                        cout<<"Los pagos mensuales actuales: "<<lookup_User.get_monthly_Payments()<<" $"<<enl;
                        lookup_User.set_Monthly_Payment();
                        break;
                    } else{
                        cout<<"Opcion invalida."<<enl;
                        break;
                    }
                }
            }
            if(!existing_user_flag){
                cout<<"Usuario no encontrado."<<enl;
            }

        }
        else if(user_menu_answer == 3){
            int user_policy_answer = 0;
            cout<<"Ingresa el numero de poliza que deseas eliminar: ";
            cin>>user_policy_type_answer;
            bool existing_user_flag = false;
            for(auto e : users_List){
                if(e.get_id() == user_policy_type_answer ){
                    int user_confirmation = 0;
                    existing_user_flag = true;
                    cout<<"Seguro que deseas eliminar la poliza? ";
                    cout<<"1.Si, Borrar para siempre.\n2.No, esperate un poquito.";
                    cout<<">>> ";
                    cin>>user_confirmation;
                    if(user_confirmation == 1){
                        users_List.erase(users_List.begin() + e.get_id());
                        cout<<"USUARIO BORRADO CON EXITO!"<<enl;
                        break;
                    }
                }
            }
            if(!existing_user_flag){
                cout<<"El ususario no existe!"<<enl;
            }

        }

    }

}


int main(){
    cout<<"Bienvenidos al seguro de polizas\n";
    menu();
    cout<<"Gracias por su preferencia";



    return 0;
}




