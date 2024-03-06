#ifndef ARREGLO_LISTA_HPP
#define ARREGLO_LISTA_HPP

#include <iostream>

#define capacidad 10

template <typename objeto>
class arreglo_lista {
private:
    int i;
    int cap;
    objeto* arr;

public:
    explicit arreglo_lista(int tam);
    arreglo_lista(const arreglo_lista &rhs);
    arreglo_lista(arreglo_lista &&rhs);
    arreglo_lista();
    ~arreglo_lista();

    arreglo_lista &operator=(const arreglo_lista &rhs);
    arreglo_lista &operator=(arreglo_lista &&rhs);

    void push_final(const objeto &rhs);
    void push_final(objeto &&rhs);
    void pop_final();
    objeto &operator[](int indice);
    const objeto &operator[](int indice) const;
    int size() const;
    void nueva_capacidad(int nueva_cap);
    void reservar(int nueva_capacidad);
    int vacia();
    void pop(int indice);
};

#include "arreglo_lista.cpp" 

#endif
