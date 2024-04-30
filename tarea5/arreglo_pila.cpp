
#include <bits/stdc++.h>
#include "arreglo_pila.hpp"
// Constructor con tamaño especificado
template<typename objeto>
pila<objeto>::pila(int tam) : i{0}, cap{tam}, arr{new objeto[cap]} {}

// Constructor de copia
template<typename objeto>
pila<objeto>::pila(const pila &rhs) : i{rhs.i}, cap{rhs.cap}, arr{new objeto[cap]} {
    for (int k = 0; k < i; k++)
        arr[k] = rhs.arr[k];
}

// Constructor de movimiento
template<typename objeto>
pila<objeto>::pila(pila &&rhs) : i{rhs.i}, cap{rhs.cap}, arr{rhs.arr} {
    rhs.i = 0;
    rhs.cap = 0;
    rhs.arr = nullptr;
}

// Constructor por defecto
template<typename objeto>
pila<objeto>::pila() : i{0}, cap{10}, arr{new objeto[10]} {}

// Destructor
template<typename objeto>
pila<objeto>::~pila() {
    delete[] arr;
}

// Operador de asignación por copia
template<typename objeto>
pila<objeto> &pila<objeto>::operator=(const pila &rhs) {
    pila copia = rhs;
    swap(cap, copia.cap);
    swap(i, copia.i);
    swap(arr, copia.arr);
    return *this;
}

// Operador de asignación por movimiento
template<typename objeto>
pila<objeto> &pila<objeto>::operator=(pila &&rhs) {
    swap(cap, rhs.cap);
    swap(i, rhs.i);
    swap(arr, rhs.arr);
    return *this;
}

// Agrega un elemento al tope de la pila
template<typename objeto>
void pila<objeto>::push(const objeto &rhs) {
    if (i == cap)
        return; // No se puede insertar más elementos, la pila está llena
    arr[i++] = rhs;
}

// Agrega un elemento al tope de la pila utilizando movimiento
template<typename objeto>
void pila<objeto>::push(objeto &&rhs) {
    if (i == cap)
        return; // No se puede insertar más elementos, la pila está llena
    arr[i++] = std::move(rhs);
}

// Elimina el elemento del tope de la pila
template<typename objeto>
void pila<objeto>::pop_top() {
    if (empty()) // La pila está vacía, no se puede hacer pop
        return;
    --i;
}

// Devuelve una referencia al elemento del tope de la pila
template<typename objeto>
objeto &pila<objeto>::top() {
    if (empty()) // La pila está vacía
        throw std::out_of_range("La pila está vacía.");
    return arr[i - 1];
}

// Devuelve una referencia constante al elemento del tope de la pila
template<typename objeto>
const objeto &pila<objeto>::top() const {
    if (empty()) // La pila está vacía
        throw std::out_of_range("La pila está vacía.");
    return arr[i - 1];
}

// Devuelve el número de elementos en la pila
template<typename objeto>
int pila<objeto>::size() const {
    return i;
}

// Verifica si la pila está vacía
template<typename objeto>
bool pila<objeto>::empty() const {
    return i == 0;
}
