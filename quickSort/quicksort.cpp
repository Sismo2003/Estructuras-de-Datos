#include <bits/stdc++.h>
using namespace std;
#define enl '\n'

typedef vector<int> vi;
void quicksort(vi &arr , int left, int right, int p){
    if(p >= arr.size()){
        return ;
    }
    int valor_pibote = arr[p];

    while( !(arr[left] > valor_pibote) && left< arr.size()-1){ // el primer elemento mayor al valor_pibote y que left no sea mas grande que el areglo
        left++; 
    }
    //cout<<"left: "<<left<<enl;


    while(!(arr[right] <= valor_pibote) && right>=0 ){ // el primer elemtno que sea menor o igual al pibote y q right sea igual 0
        right--;
    }
   // cout<<"right: "<<right<<enl;

    if(right>left){ // si right es mayor a left se intercambian
        swap(arr[left],arr[right]);
    }
    else{
        swap(arr[right],arr[p]); // entonces se cambia right con
    }
   
    //for(auto e : arr) cout<< e << ' ';
    //cout<<enl;

    quicksort(arr,0+1,arr.size()-1,p+1);

}


int main(){

   // vi arr = {9,8,7,6,5,4,3,2,1};
    vi arr = {20,10,30,50,40,60,70,80,90};
    cout<<"Arreglo original:" <<enl;
    for(auto e : arr) cout<< e << ' ';
    cout<<enl;

    quicksort(arr,0,arr.size()-1,0);

    cout<<"Arreglo Final:" <<enl;
    for(auto e : arr) cout<< e << ' ';
    cout<<enl;
   
    return 0;
}