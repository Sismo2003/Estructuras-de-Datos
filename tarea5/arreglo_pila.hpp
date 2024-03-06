#ifndef PILA_HPP
#define PILA_HPP

template <typename objeto>
class pila {
private:
    int i; // Índice actual del tope de la pila
    int cap; // Capacidad actual de la pila
    objeto* arr; // Arreglo para almacenar los elementos de la pila

public:
    // Constructor con tamaño especificado
    pila(int tam);

    // Constructor de copia
    pila(const pila &rhs);

    // Constructor de movimiento
    pila(pila &&rhs);

    // Constructor por defecto
    pila();

    // Destructor
    ~pila();

    // Operador de asignación por copia
    pila &operator=(const pila &rhs);

    // Operador de asignación por movimiento
    pila &operator=(pila &&rhs);

    // Agrega un elemento al tope de la pila
    void push(const objeto &rhs);

    // Agrega un elemento al tope de la pila utilizando movimiento
    void push(objeto &&rhs);

    // Elimina el elemento del tope de la pila
    void pop_top();

    // Devuelve una referencia al elemento del tope de la pila
    objeto &top();

    // Devuelve una referencia constante al elemento del tope de la pila
    const objeto &top() const;

    // Devuelve el número de elementos en la pila
    int size() const;

    // Verifica si la pila está vacía
    bool empty() const;
};

#include "arreglo_pila.cpp" // Incluye la implementación de la clase

#endif // PILA_HPP
