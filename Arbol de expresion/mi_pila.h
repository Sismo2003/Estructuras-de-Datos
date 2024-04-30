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

// Implementación de la clase pila
template<typename objeto>
pila<objeto>::pila(int tam) : i{0}, cap{tam}, arr{new objeto[cap]} {}

template<typename objeto>
pila<objeto>::pila(const pila &rhs) : i{rhs.i}, cap{rhs.cap}, arr{new objeto[cap]} {
    for (int k = 0; k < i; k++)
        arr[k] = rhs.arr[k];
}

template<typename objeto>
pila<objeto>::pila(pila &&rhs) : i{rhs.i}, cap{rhs.cap}, arr{rhs.arr} {
    rhs.i = 0;
    rhs.cap = 0;
    rhs.arr = nullptr;
}

template<typename objeto>
pila<objeto>::pila() : i{0}, cap{10}, arr{new objeto[10]} {}

template<typename objeto>
pila<objeto>::~pila() {
    delete[] arr;
}

template<typename objeto>
pila<objeto> &pila<objeto>::operator=(const pila &rhs) {
    pila copia = rhs;
    swap(cap, copia.cap);
    swap(i, copia.i);
    swap(arr, copia.arr);
    return *this;
}

template<typename objeto>
pila<objeto> &pila<objeto>::operator=(pila &&rhs) {
    swap(cap, rhs.cap);
    swap(i, rhs.i);
    swap(arr, rhs.arr);
    return *this;
}

template<typename objeto>
void pila<objeto>::push(const objeto &rhs) {
    if (i == cap)
        return; // No se puede insertar más elementos, la pila está llena
    arr[i++] = rhs;
}

template<typename objeto>
void pila<objeto>::push(objeto &&rhs) {
    if (i == cap)
        return; // No se puede insertar más elementos, la pila está llena
    arr[i++] = std::move(rhs);
}

template<typename objeto>
void pila<objeto>::pop_top() {
    if (empty()) // La pila está vacía, no se puede hacer pop
        return;
    --i;
}

template<typename objeto>
objeto &pila<objeto>::top() {
    if (empty()) // La pila está vacía
        throw std::out_of_range("La pila está vacía.");
    return arr[i - 1];
}

template<typename objeto>
const objeto &pila<objeto>::top() const {
    if (empty()) // La pila está vacía
        throw std::out_of_range("La pila está vacía.");
    return arr[i - 1];
}

template<typename objeto>
int pila<objeto>::size() const {
    return i;
}

template<typename objeto>
bool pila<objeto>::empty() const {
    return i == 0;
}

#endif // PILA_HPP
