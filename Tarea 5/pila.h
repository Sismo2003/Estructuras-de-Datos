template <typename T>
class Pila {
private:
    int indice; // Índice actual del tope de la pila
    int capacidad; // Capacidad actual de la pila
    T* arreglo; // Arreglo para almacenar los elementos de la pila

public:
    // Constructor con tamaño especificado
    Pila(int tam);

    // Constructor de copia
    Pila(const Pila &rhs);

    // Constructor de movimiento
    Pila(Pila &&rhs);

    // Constructor por defecto
    Pila();

    // Destructor
    ~Pila();

    // Operador de asignación por copia
    Pila &operator=(const Pila &rhs);

    // Operador de asignación por movimiento
    Pila &operator=(Pila &&rhs);

    // Agrega un elemento al tope de la pila
    void push(const T &elemento);

    // Agrega un elemento al tope de la pila utilizando movimiento
    void push(T &&elemento);

    // Elimina el elemento del tope de la pila
    void pop();

    // Devuelve una referencia al elemento del tope de la pila
    T &top();

    // Devuelve una referencia constante al elemento del tope de la pila
    const T &top() const;

    // Devuelve el número de elementos en la pila
    int size() const;

    // Verifica si la pila está vacía
    bool empty() const;
};

// Constructor con tamaño especificado
template<typename T>
Pila<T>::Pila(int tam) : indice{0}, capacidad{tam}, arreglo{new T[capacidad]} {}

// Constructor de copia
template<typename T>
Pila<T>::Pila(const Pila &rhs) : indice{rhs.indice}, capacidad{rhs.capacidad}, arreglo{new T[capacidad]} {
    for (int k = 0; k < indice; k++)
        arreglo[k] = rhs.arreglo[k];
}

// Constructor de movimiento
template<typename T>
Pila<T>::Pila(Pila &&rhs) : indice{rhs.indice}, capacidad{rhs.capacidad}, arreglo{rhs.arreglo} {
    rhs.indice = 0;
    rhs.capacidad = 0;
    rhs.arreglo = nullptr;
}

// Constructor por defecto
template<typename T>
Pila<T>::Pila() : indice{0}, capacidad{10}, arreglo{new T[10]} {}

// Destructor
template<typename T>
Pila<T>::~Pila() {
    delete[] arreglo;
}

// Operador de asignación por copia
template<typename T>
Pila<T> &Pila<T>::operator=(const Pila &rhs) {
    Pila copia = rhs;
    std::swap(capacidad, copia.capacidad);
    std::swap(indice, copia.indice);
    std::swap(arreglo, copia.arreglo);
    return *this;
}

// Operador de asignación por movimiento
template<typename T>
Pila<T> &Pila<T>::operator=(Pila &&rhs) {
    std::swap(capacidad, rhs.capacidad);
    std::swap(indice, rhs.indice);
    std::swap(arreglo, rhs.arreglo);
    return *this;
}

// Agrega un elemento al tope de la pila
template<typename T>
void Pila<T>::push(const T &elemento) {
    if (indice == capacidad)
        return; // No se puede insertar más elementos, la pila está llena
    arreglo[indice++] = elemento;
}

// Agrega un elemento al tope de la pila utilizando movimiento
template<typename T>
void Pila<T>::push(T &&elemento) {
    if (indice == capacidad)
        return; // No se puede insertar más elementos, la pila está llena
    arreglo[indice++] = std::move(elemento);
}

// Elimina el elemento del tope de la pila
template<typename T>
void Pila<T>::pop() {
    if (empty()) // La pila está vacía, no se puede hacer pop
        return;
    --indice;
}

// Devuelve una referencia al elemento del tope de la pila
template<typename T>
T &Pila<T>::top() {
    if (empty()) // La pila está vacía
        throw std::out_of_range("La pila está vacía.");
    return arreglo[indice - 1];
}

// Devuelve una referencia constante al elemento del tope de la pila
template<typename T>
const T &Pila<T>::top() const {
    if (empty()) // La pila está vacía
        throw std::out_of_range("La pila está vacía.");
    return arreglo[indice - 1];
}

// Devuelve el número de elementos en la pila
template<typename T>
int Pila<T>::size() const {
    return indice;
}

// Verifica si la pila está vacía
template<typename T>
bool Pila<T>::empty() const {
    return indice == 0;
}
