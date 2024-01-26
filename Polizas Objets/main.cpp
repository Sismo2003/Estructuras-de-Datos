
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

                }
                break;
            }
        }
        else if(user_menu_answer == 2){
            cout<<"hi"<<enl;
        }
    }

}


int main(){
    cout<<"Bienvenidos al seguro de polizas\n";
    menu();
    cout<<"Gracias por su preferencia";



    return 0;
}