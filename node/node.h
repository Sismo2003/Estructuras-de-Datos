//
// Created by Alexis Ortiz ceceña on 04/03/24.
//

#ifndef ESTRUCTURAS_DE_DATOS_NODE_H
#define ESTRUCTURAS_DE_DATOS_NODE_H
using namespace std;
#include <iostream>
template <typename objeto>
class node {
    private:
        objeto dato;
        node *siguiente;
    public:
        node(const objeto &d, node *s= nullptr):dato{d},siguiente{s}{} // contructor para variable no volatil}
        node(objeto &&d,node *s= nullptr):dato{std::move(d)},siguiente{s}{}
        node(node *s= nullptr):siguiente{s}{}

        void setDato(const objeto &r){
            this->dato = r;
        }
        void setDato(objeto &&r){ // cuando no sea constante lleva doble referencia
            this->dato= std::move(r);
        }

        objeto getDato(){
            return this->dato;
        }
        void setSiguiente(node *s){
            this->siguiente = s;
        }
        node getSiguiente(){
            return this->siguiente;
        }
        void * getSiguienteptr(){
            return this->siguiente;
        }
};


#endif //ESTRUCTURAS_DE_DATOS_NODE_H
