#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int busqueda_binaria(vector<int> &arr, int inicio, int final, int n){
    if(final < inicio)  return -1;
    else{
        int mid = (inicio + final)/2;
        if(arr[mid] == n){
            return mid;
        }else if(arr[mid] > n){ /// si la mitad es
            return busqueda_binaria(arr,inicio,(mid-1),n);
        }else{
            return busqueda_binaria(arr,(mid+1),final,n);
        }
    }
}

int main(){

    vi arr = {1,2,3,4,5,6,7,8,9};

    int r = busqueda_binaria(arr,0,arr.size(),6);
    cout<<"la posicion es: " << r<<"\n";

    return 0;
}