#include <bits/stdc++.h>

using namespace std;

template <typename object> 
class node{
    private:
        object dato;
        node *siguiente;
    public:
        node(const object &d, node *s=nullptr):dato{d}, siguiente{s}{}
        node(object &&d, node *s=nullptr):dato{std::move(d)}, siguiente{s}{}
        node():siguiente{nullptr}{}

        void setDato(const object &rhs){
            this->dato = rhs;
        }
        void setDato(object &&rhs){
            this->dato = std::move(rhs);
        }
        object getDato()const{
            return this->dato;
        }
        void setSiguiente(node *s){
            this->siguiente = s;
        }
        node* getSiguiente(){
            return this->siguiente;
        }

        

    

};


// Clase para la lista enlazada
template <typename object> 
class ListaEnlazada {
private:
    node<object>* ancla; // Nodo de ancla
    long long tam;
public:
    // Constructor que inicializa el nodo de ancla
    ListaEnlazada() {
        ancla = new node<object>();
    }

    // Destructor para liberar la memoria
    ~ListaEnlazada() {
        node<object>* actual = ancla;
        while (actual) {
            node<object>* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        }
    }

    // Inserta un elemento al final de la lista
    void pushBack(const object &data) {
        node<object>* nuevoNodo = new node<object>(data);
        node<object>* actual = ancla;
        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevoNodo);
        this->tam++;
    }

    // Inserta un elemento al principio de la lista
    void pushFront(const object &data) {
        node<object>* nuevoNodo = new node<object>(data);
        nuevoNodo->setSiguiente(ancla->getSiguiente());
        ancla->setSiguiente(nuevoNodo);
        this->tam++;
    }

    // Inserta un elemento en una posición específica en la lista
    void push(const object &data, int position) {
        if (position < 0 || position > tam) {
            std::cerr << "Error: Posición fuera de rango." << std::endl;
            return;
        }

        node<object>* nuevoNodo = new node<object>(data);
        node<object>* actual = ancla;

        for (int i = 0; i < position; i++) {
            actual = actual->getSiguiente();
        }

        nuevoNodo->setSiguiente(actual->getSiguiente());
        actual->setSiguiente(nuevoNodo);
        tam++;
    }

    // Elimina el primer elemento de la lista
    void popFront() {
        if (tam == 0) {
            std::cerr << "Error: Lista vacía." << std::endl;
            return;
        }

        node<object>* eliminar = ancla->getSiguiente();
        ancla->setSiguiente(eliminar->getSiguiente());
        delete eliminar;
        tam--;
    }

    // Elimina el último elemento de la lista
    void popBack() {
        if (tam == 0) {
            std::cerr << "Error: Lista vacía." << std::endl;
            return;
        }

        node<object>* actual = ancla;
        while (actual->getSiguiente()->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }

        delete actual->getSiguiente();
        actual->setSiguiente(nullptr);
        tam--;
    }

    // Elimina el elemento en una posición específica en la lista
    void pop(int position) {
        if (position < 0 || position >= tam) {
            std::cerr << "Error: Posición fuera de rango." << std::endl;
            return;
        }

        node<object>* actual = ancla;
        for (int i = 0; i < position; i++) {
            actual = actual->getSiguiente();
        }

        node<object>* eliminar = actual->getSiguiente();
        actual->setSiguiente(eliminar->getSiguiente());
        delete eliminar;
        tam--;
    }

    // Retorna el elemento en una posición específica sin modificar la lista
    object peek(int position) const {
        if (position < 0 || position >= tam) {
            std::cerr << "Error: Posición fuera de rango." << std::endl;
            throw std::out_of_range("Posición fuera de rango.");
        }

        node<object>* actual = ancla->getSiguiente();
        for (int i = 0; i < position; i++) {
            actual = actual->getSiguiente();
        }

        return actual->getDato();
    }

    // Cambia el valor de un elemento en una posición específica de la lista
    void replace(const object &data, int position) {
        if (position < 0 || position >= tam) {
            std::cerr << "Error: Posición fuera de rango." << std::endl;
            return;
        }

        node<object>* actual = ancla->getSiguiente();
        for (int i = 0; i < position; i++) {
            actual = actual->getSiguiente();
        }

        actual->setDato(data);
    }

    // Busca un elemento en la lista y devuelve su posición (si se encuentra)
    int find(const object &data) const {
        int position = 0;
        node<object>* actual = ancla->getSiguiente();
        while (actual != nullptr) {
            if (actual->getDato() == data) {
                return position;
            }
            actual = actual->getSiguiente();
            position++;
        }
        return -1; // Si el elemento no se encuentra en la lista
    }

    // Muestra todos los elementos de la lista
    void display() const {
    node<object>* actual = ancla->getSiguiente();
    int position = 0;
    while (actual != nullptr) {
        std::cout << position << " -> " << actual->getDato() << std::endl;
        actual = actual->getSiguiente();
        position++;
    }
}



    // Retorna el tamaño de la lista
    int size() const {
        return this->tam;
    }

    bool empty() const {
        return tam == 0;
    }

    
};



int main(){
    
    ListaEnlazada<int> lista;
    lista.pushBack(10);
    lista.pushBack(20);
    lista.pushBack(30);
    
    lista.display();

    return 0;
}