#include <bits/stdc++.h>
#include "arreglo_lista.hpp"
using namespace std;

template <typename objeto>
arreglo_lista<objeto>::arreglo_lista(int tam) : i{tam}, cap{i + capacidad}, arr{new objeto[cap]} {}

template <typename objeto>
arreglo_lista<objeto>::arreglo_lista(const arreglo_lista &rhs) : i{rhs.i}, cap{rhs.cap}, arr{new objeto[cap]} {
    for (int k = 0; k < i; k++)
        arr[k] = rhs.arr[k];
}

template <typename objeto>
arreglo_lista<objeto>::arreglo_lista(arreglo_lista &&rhs) : i{rhs.i}, cap{rhs.cap}, arr{rhs.arr} {
    rhs.i = 0;
    rhs.cap = 0;
    rhs.arr = nullptr;
}

template <typename objeto>
arreglo_lista<objeto>::arreglo_lista() : i{0}, cap{capacidad}, arr{new objeto[capacidad]} {}

template <typename objeto>
arreglo_lista<objeto>::~arreglo_lista() {
    delete[] arr;
}

template <typename objeto>
arreglo_lista<objeto> &arreglo_lista<objeto>::operator=(const arreglo_lista &rhs) {
    arreglo_lista copia = rhs;
    swap(cap, copia.cap);
    swap(i, copia.i);
    swap(arr, copia.arr);
    return *this;
}

template <typename objeto>
arreglo_lista<objeto> &arreglo_lista<objeto>::operator=(arreglo_lista &&rhs) {
    swap(cap, rhs.cap);
    swap(i, rhs.i);
    swap(arr, rhs.arr);
    return *this;
}

template <typename objeto>
void arreglo_lista<objeto>::push_final(const objeto &rhs) {
    if (i == cap)
    reservar(cap + 1); // invocar metodo para aumentar el espacio
    arr[i] = rhs;
    i++;
}

template <typename objeto>
void arreglo_lista<objeto>::push_final(objeto &&rhs) {
    if (i == cap)
        reservar(cap + 1); // invocar metodo para aumentar el espacio
    arr[i] = std::move(rhs);
    i++;
}

template <typename objeto>
void arreglo_lista<objeto>::pop_final() {
    if (!vacia()) // metodo
        i--;
}

template <typename objeto>
objeto &arreglo_lista<objeto>::operator[](int indice) {
    return arr[indice];
}

template <typename objeto>
const objeto &arreglo_lista<objeto>::operator[](int indice) const {
    return arr[indice];
}

template <typename objeto>
int arreglo_lista<objeto>::size() const {
    return i;
}

template <typename objeto>
void arreglo_lista<objeto>::nueva_capacidad(int nueva_cap) {
    if (nueva_cap > cap) {
        reservar(nueva_cap);
        cap = nueva_cap;
    }
}

template <typename objeto>
void arreglo_lista<objeto>::reservar(int nueva_capacidad) {
    objeto* nuevo_arr = new objeto[nueva_capacidad];
    for (int k = 0; k < i; k++) {
        nuevo_arr[k] = std::move(arr[k]);
    }
    delete[] arr;
    arr = nuevo_arr;
}

template <typename objeto>
int arreglo_lista<objeto>::vacia() {
    return i == 0;
}

template <typename objeto>
void arreglo_lista<objeto>::pop(int indice) {
    if (indice < 0 || indice >= i) {
        cout << "Índice fuera de rango." << endl;
        return;
    }

    for (int j = indice; j < i - 1; ++j) {
        arr[j] = arr[j + 1];
    }

    i--;
}



