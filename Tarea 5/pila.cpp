#include <iostream>
#include "pila.h"

int main() {
    Pila<int> pila_enteros(5); // Creamos una pila de enteros con capacidad inicial de 5

    // Agregamos algunos elementos a la pila
    pila_enteros.push(1);
    pila_enteros.push(2);
    pila_enteros.push(3);

    // Mostramos el tamaño de la pila
    std::cout << "Tamaño de la pila: " << pila_enteros.size() << std::endl;

    // Mostramos y quitamos elementos de la pila
    while (!pila_enteros.empty()) {
        std::cout << "Elemento en el tope de la pila: " << pila_enteros.top() << std::endl;
        pila_enteros.pop();
    }

    // Verificamos que la pila esté vacía
    if (pila_enteros.empty()) {
        std::cout << "La pila está vacía." << std::endl;
    } else {
        std::cout << "La pila no está vacía." << std::endl;
    }

    return 0;
}
